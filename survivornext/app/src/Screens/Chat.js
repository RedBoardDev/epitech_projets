import React, { useState, useEffect, useRef } from 'react';
import { View, Text, TextInput, FlatList, StyleSheet, Image, TouchableOpacity, KeyboardAvoidingView, ActivityIndicator } from 'react-native';
import Octicons from 'react-native-vector-icons/Octicons';
import { chatApi } from '../Requests';
import { useTheme } from '@react-navigation/native';
import * as ImagePicker from 'expo-image-picker';
import * as FileSystem from 'expo-file-system';
import Modal from 'react-native-modal';
import AsyncStorage from '@react-native-async-storage/async-storage';
import ImageViewer from 'react-native-image-zoom-viewer';
import { Alert } from 'react-native';
import LoadingIndicator from '../Components/LoadingIndicator';

const ChatScreen = () => {
    const [messages, setMessages] = useState([]);
    const [newMessage, setNewMessage] = useState('');
    const { colors } = useTheme();
    const flatListRef = useRef(null);
    const [selectedImage, setSelectedImage] = useState(null);
    const [isModalVisible, setIsModalVisible] = useState(false);
    const [userProfil, setUserProfil] = useState(null);
    const [date, setDate] = useState(new Date());
    const [isSending, setIsSending] = useState(false);

    const handleImagePress = (imageUri) => {
        setSelectedImage(imageUri);
        setIsModalVisible(true);
    };

    useEffect(() => {
        loadLastMessages();
    }, []);

    useEffect(() => {
        const interval = setInterval(() => {
            setDate(new Date());
        }, 50000000);
        return () => clearInterval(interval);
    }, []);

    useEffect(() => {
        loadRecentMessages();
    }, [date]);

    useEffect(() => {
        async function fetchData() {
            try {
                const jsonValue = await AsyncStorage.getItem('userProfil');
                const object = JSON.parse(jsonValue) || null;
                setUserProfil(object);
            } catch (e) {
                console.error('Error when getting user profil:', e);
            }
        }
        fetchData();
        if (flatListRef.current) {
            flatListRef.current.scrollToEnd({ animated: false });
        }
    }, [messages]);

    const loadLastMessages = async () => {
        try {
            const data = await chatApi.getLastXMessages(50);
            data.sort((a, b) => b.created_at - a.created_at);
            setMessages(data);
        } catch (error) {
            console.error('Error loading last messages:', error);
        }
    };

    const loadRecentMessages = async () => {
        if (messages.length === 0)
            return;
        try {
            const lastMessageDate = messages[messages.length - 1].created_at;
            const data = await chatApi.getRecentMessages(lastMessageDate);
            data.sort((a, b) => b.created_at - a.created_at);
            setMessages([...messages, ...data]);
        } catch (error) {
            console.error('Error loading recent messages:', error);
        }
    };

    const handleSendMessage = async () => {
        try {
            if (!newMessage || newMessage.trim() === '') return;
            setIsSending(true);
            await chatApi.sendMessage(newMessage, userProfil['email'], userProfil['name']);
            loadRecentMessages();
        } catch (error) {
            console.error('Error sending a message:', error);
            Alert.alert('Error', 'Message could not be sent. Please try again later.');
        } finally {
            setIsSending(false);
            setNewMessage('');
        }
    };

    async function askForCameraPermission() {
        const { status } = await ImagePicker.requestMediaLibraryPermissionsAsync();
        if (status !== 'granted') {
            console.error('Permission refused');
            return;
        }
    }

    async function pickImage() {
        await askForCameraPermission();

        const result = await ImagePicker.launchImageLibraryAsync({
            mediaTypes: ImagePicker.MediaTypeOptions.All,
            allowsEditing: true,
            quality: 1,
        });
        if (!result.canceled) {
            const selectedImageUri = result.assets[0].uri;
            const base64 = await FileSystem.readAsStringAsync(selectedImageUri, { encoding: 'base64' });
            const userName = userProfil['name'] + ' ' + userProfil['surname'];
            try {
                setIsSending(true);
                await chatApi.sendImage(base64, userProfil['email'], userName);
                loadRecentMessages();
            } catch (error) {
                console.error('Error sending an image:', error);
                Alert.alert('Error', 'Image could not be sent. Please try again later.');
            } finally {
                setIsSending(false);
            }
        }
    }

    return (
        <View style={styles.container}>
            <FlatList
                ref={flatListRef}
                data={messages}
                keyExtractor={(item) => item.id.toString()}
                renderItem={({ item }) => (
                    <View style={item.senderEmail === userProfil['email'] ? [styles.messageContainerRight, { backgroundColor: colors.primary }] : [styles.messageContainerLeft, { backgroundColor: colors.card }]}>
                        {item.senderEmail !== userProfil['email'] && (
                            <Text style={[styles.senderNameLeft, { color: colors.text }]}>{item.senderName}</Text>
                        )}
                        {item.message ? (
                            <Text style={item.senderEmail === userProfil['email'] ? { color: "#fff" } : { color: colors.text }}>{item.message}</Text>
                        ) : (
                            <TouchableOpacity onPress={() => handleImagePress(item.imageUri)}>
                                <Image source={{ uri: item.imageUri }} style={{ width: 100, height: 100 }} />
                            </TouchableOpacity>

                        )}

                    </View>
                )}
            />
            <View style={[styles.inputContainer, { borderTopColor: colors.border }]}>
                <TextInput
                    style={[styles.input, { backgroundColor: colors.card }]}
                    placeholder="Write your message..."
                    placeholderTextColor={colors.border}
                    value={newMessage}
                    onChangeText={(text) => setNewMessage(text)}
                />
                {isSending ? (
                    <View style={styles.sendButton}>
                        <ActivityIndicator size="large" color={colors.primary} />
                    </View>
                ) : (
                    <TouchableOpacity
                        onPress={handleSendMessage}
                        style={styles.thirdIcon}
                    >
                        <Octicons
                            name="paper-airplane"
                            size={26}
                            color={colors.primary}
                        />
                    </TouchableOpacity>
                )}
                <Octicons
                    name="image"
                    size={26}
                    color={colors.primary}
                    style={styles.sendIcon}
                    onPress={pickImage}
                />
            </View>
            <KeyboardAvoidingView behavior={Platform.OS === "ios" ? "padding" : "height"} keyboardVerticalOffset={100} />
            <Modal
                isVisible={isModalVisible}
                onBackdropPress={() => setIsModalVisible(false)}
                swipeDirection={['up', 'down']}
                onSwipeComplete={() => setIsModalVisible(false)}
                animationIn="slideInUp"
                animationOut="slideOutDown"
                backdropOpacity={0}
                style={{ margin: 0, padding: 0 }}
            >
                <ImageViewer
                    imageUrls={[{ url: selectedImage }]}
                    enableSwipeDown={true}
                    onSwipeDown={() => setIsModalVisible(false)}
                    renderIndicator={() => null}
                    backgroundColor="black"
                    style={{ flex: 1 }}
                />
            </Modal>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        padding: 16,
        paddingTop: 0,
    },
    messageContainerLeft: {
        padding: 10,
        borderRadius: 12,
        marginBottom: 8,
        elevation: 2,
        alignSelf: 'flex-start',
        maxWidth: '70%',
    },
    messageContainerRight: {
        padding: 10,
        borderRadius: 12,
        marginBottom: 8,
        alignSelf: 'flex-end',
        elevation: 2,
    },
    sendButton: {
        position: 'absolute',
        right: 12,
        top: '35%',
    },

    senderNameLeft: {
        fontWeight: 'bold',
        marginBottom: 4,
    },
    inputContainer: {
        flexDirection: 'row',
        alignItems: 'center',
        borderTopWidth: 1,
        paddingBottom: 0,
        paddingTop: 8,
    },
    input: {
        flex: 1,
        padding: 14,
        borderRadius: 30,
        paddingLeft: 26,
        elevation: 2,
    },
    sendIcon: {
        position: 'absolute',
        right: 58,
        top: '50%',
        transform: [{ translateY: -5 }],
    },
    thirdIcon: {
        position: 'absolute',
        right: 18,
        top: '50%',
        transform: [{ translateY: -5 }],
    },
    closeButton: {
        position: 'absolute',
        top: 20,
        right: 20,
        zIndex: 1,
    },

});


export default ChatScreen;
