import React, { useState, useEffect, useRef } from 'react';
import { View, Text, TextInput, FlatList, StyleSheet, Image, TouchableOpacity } from 'react-native';
import Octicons from 'react-native-vector-icons/Octicons';
import { getRecentMessages, sendMessage, sendImage } from '../ChatApiRequest';
import { useTheme } from '@react-navigation/native';
import * as ImagePicker from 'expo-image-picker';
import * as FileSystem from 'expo-file-system';
import Modal from 'react-native-modal';

const ChatScreen = () => {
    const [messages, setMessages] = useState([]);
    const [newMessage, setNewMessage] = useState('');
    const { colors } = useTheme();
    const flatListRef = useRef(null);
    const [selectedImage, setSelectedImage] = useState(null);
    const [isModalVisible, setIsModalVisible] = useState(false);


    useEffect(() => {
        loadRecentMessages();
    }, []);

    const handleImagePress = (imageUri) => {
        setSelectedImage(imageUri);
        setIsModalVisible(true);
    };

    useEffect(() => {
        if (flatListRef.current) {
            flatListRef.current.scrollToEnd({ animated: false });
        }
    }, [messages]);

    const loadRecentMessages = async () => {
        try {
            const data = await getRecentMessages(50);
            setMessages(data.reverse());
        } catch (error) {
            console.error('Error loading recent messages:', error);
        }
    };

    const handleSendMessage = async () => {
        try {
            if (!newMessage || newMessage.trim() === '') return;
            await sendMessage(newMessage, 'email2@email.com', 'John Doe');
            loadRecentMessages();
            setNewMessage('');
        } catch (error) {
            console.error('Error sending a message:', error);
        }
    };

    async function askForCameraPermission() {
        const { status } = await ImagePicker.requestMediaLibraryPermissionsAsync();
        if (status !== 'granted') {
            console.error('Permission refusée');
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
            const selectedImageUri = result.uri;
            console.log('Image URI sélectionnée :', selectedImageUri);
            const base64 = await FileSystem.readAsStringAsync(result.uri, { encoding: 'base64' });
            console.log("Image base64", base64);
            await sendImage(base64, 'email2@email.com', 'John Doe');
        }
    }

    return (
        <View style={styles.container}>
            <FlatList
                ref={flatListRef}
                data={messages}
                keyExtractor={(item) => item.id.toString()}
                inverted
                renderItem={({ item }) => (
                    <View style={item.senderEmail === 'email2@email.com' ? [styles.messageContainerRight, { backgroundColor: colors.primary }] : [styles.messageContainerLeft, { backgroundColor: colors.card }]}>
                        {item.senderEmail !== 'email2@email.com' && (
                            <Text style={[styles.senderNameLeft, { color: colors.text }]}>{item.senderName}</Text>
                        )}
                        {item.message ? (
                            <Text style={item.senderEmail === 'email2@email.com' ? { color: "#fff" } : { color: colors.text }}>{item.message}</Text>
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
                <Octicons
                    name="image"
                    size={26}
                    color={colors.primary}
                    style={styles.sendIcon}
                    onPress={pickImage}
                />
                <Octicons
                    name="paper-airplane"
                    size={26}
                    color={colors.primary}
                    style={styles.thirdIcon}
                    onPress={handleSendMessage}
                />
            </View>
            <Modal
                isVisible={isModalVisible}
                onBackdropPress={() => setIsModalVisible(false)}
                swipeDirection={['up', 'down']}
                onSwipeComplete={() => setIsModalVisible(false)}
                animationIn="slideInUp"
                animationOut="slideOutDown"
                animationInTiming={300}
                animationOutTiming={300}
            >
                <View style={styles.modalContainer}>
                    <Image
                        source={{ uri: selectedImage }}
                        style={{ width: '100%', height: '100%' }}
                    />
                </View>
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
    modalContainer: {
        flex: 1,
        backgroundColor: 'black',
        justifyContent: 'center',
        alignItems: 'center',
    },
    closeButton: {
        position: 'absolute',
        top: 20,
        right: 20,
        zIndex: 1,
    },

});


export default ChatScreen;
