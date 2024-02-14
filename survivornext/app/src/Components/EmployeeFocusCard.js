import React, { useEffect, useState, useRef } from 'react';
import { StyleSheet, View, TouchableOpacity, Image, Animated, Text } from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';
import { Linking } from 'react-native';

import { trombiApi } from '../Requests';

export default function EmployeeFocusCard({ infos, pp, onClose }) {
    const [pikachu, setPikachu] = useState(false);
    const fadeAnim = useRef(new Animated.Value(0)).current;

    useEffect(() => {
        Animated.timing(fadeAnim, {
            toValue: 1,
            duration: 100,
            useNativeDriver: false,
        }).start();
    }, []);

    const closeModal = () => {
        Animated.timing(fadeAnim, {
            toValue: 0,
            duration: 100,
            useNativeDriver: false,
        }).start(() => {
            if (onClose) {
                onClose();
            }
        });
    };

    return (
        <View style={styles.popupContainer}>
            <TouchableOpacity
                activeOpacity={1}
                style={styles.popupContainer}
                onPress={closeModal}
            />
            <Animated.View style={[styles.popup, { opacity: fadeAnim }]}>
                <View style={styles.imageContainer}>
                    <View style={styles.imageShadow} />
                    <TouchableOpacity
                        onPress={() => { setPikachu(prev => !prev) }}>
                        <Image alt="" resizeMode="cover" source={
                            pp !== null
                                ? (pikachu ? require('../../assets/images.jpeg') : { uri: pp })
                                : require('../../assets/Blank-profile.png')
                        } style={styles.popupImg} />
                    </TouchableOpacity>
                </View>
                <View style={styles.infoContainer}>
                    <View style={styles.nameContainer}>
                        <Text style={styles.popupTextName}>{infos.name} {infos.surname}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Icon name="envelope" size={20} color="#000" />
                        <Text style={styles.value}>{infos.email}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Icon name="birthday-cake" size={20} color="#000" />
                        <Text style={styles.value}>{infos.birth_date}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Icon name="venus-mars" size={20} color="#000" />
                        <Text style={styles.value}>{infos.gender}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Icon name="briefcase" size={20} color="#000" />
                        <Text style={styles.value}>{infos.work}</Text>
                    </View>
                </View>
            </Animated.View>
        </View>
    );
}

const styles = StyleSheet.create({
    popupContainer: {
        flex: 1,
        backgroundColor: 'transparent',
        justifyContent: 'flex-end',
    },
    popup: {
        backgroundColor: 'rgba(255, 255, 255, 1)',
        borderTopLeftRadius: 20,
        borderTopRightRadius: 20,
        paddingHorizontal: 20,
        paddingBottom: 10,
    },
    popupImg: {
        position: 'absolute',
        top: -80,
        width: 150,
        height: 150,
        borderRadius: 100,
        alignSelf: 'center',
        borderWidth: 1,
        borderColor: 'white',
        backgroundColor: 'black',
    },
    infoContainer: {
        marginTop: 80,
    },
    nameContainer: {
        alignItems: 'center',
        marginBottom: 10,
    },
    imageShadow: {
        position: 'absolute',
        width: 152,
        height: 150,
        backgroundColor: 'rgba(0, 0, 0, 0.5)',
        top: -78,
        borderRadius: 75,
    },
    imageContainer: {
        alignItems: 'center',
        position: 'relative',
    },
    infoItem: {
        flexDirection: 'row',
        alignItems: 'center',
        marginBottom: 30,
    },
    value: {
        fontWeight: 'bold',
        marginLeft: 5,
    },
    popupTextName: {
        fontSize: 26,
        fontWeight: 'bold',
        color: 'black',
        marginBottom: 10,
    },
});
