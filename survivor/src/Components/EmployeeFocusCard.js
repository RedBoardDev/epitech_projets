import React, { useEffect, useState, useRef } from 'react';
import { StyleSheet, View, Text, TouchableOpacity, Image, Animated } from 'react-native';

import { getEmployee, getEmployeePP } from '../Requests';
import { t } from '../Translate';

export default function EmployeeFocusCard({ id, email, name, surname, onClose }) {
    const [birthDate, setBirthDate] = useState('');
    const [gender, setGender] = useState('');
    const [work, setWork] = useState('');
    const [profilePicture, setProfilePicture] = useState(null);
    const fadeAnim = useRef(new Animated.Value(0)).current;

    useEffect(() => {
        getEmployee(id)
            .then((data) => {
                setBirthDate(data.birth_date);
                setGender(data.gender);
                setWork(data.work);
            })
            .catch((error) => {
                console.error(error);
            });
        getEmployeePP(id).then((data) => {
                const fileReaderInstance = new FileReader();
                fileReaderInstance.readAsDataURL(data);
                fileReaderInstance.onload = () => {
                    setProfilePicture(fileReaderInstance.result);
                    Animated.timing(fadeAnim, {
                        toValue: 1,
                        duration: 100,
                        useNativeDriver: false,
                    }).start();
                };
            })
            .catch((error) => {
                console.error(error);
            });
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
            <Animated.View
                style={[
                    styles.popup,
                    {
                        opacity: fadeAnim,
                    },
                ]}
            >
                <View style={styles.imageContainer}>
                    <View style={styles.imageShadow} />
                    <Image
                        alt=""
                        resizeMode="cover"
                        source={
                            profilePicture !== null
                                ? { uri: profilePicture }
                                : require('../../assets/Blank-profile.png')
                        }
                        style={styles.popupImg}
                    />
                </View>
                <View style={styles.infoContainer}>
                    <View style={styles.nameContainer}>
                        <Text style={styles.popupTextName}>{name} {surname}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Text style={styles.label}>{t('email')}:</Text>
                        <Text style={styles.value}>{email}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Text style={styles.label}>{t('birthdate')}:</Text>
                        <Text style={styles.value}>{birthDate}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Text style={styles.label}>{t('gender')}:</Text>
                        <Text style={styles.value}>{gender}</Text>
                    </View>
                    <View style={styles.infoItem}>
                        <Text style={styles.label}>{t('work')}:</Text>
                        <Text style={styles.value}>{work}</Text>
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
        backgroundColor: 'white',
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
        marginBottom: 10,
    },
    label: {
        color: 'gray',
        marginRight: 5,
    },
    value: {
        fontWeight: 'bold',
    },
    popupTextName: {
        fontSize: 26,
        fontWeight: 'bold',
        color: 'black',
        marginBottom: 10,
    },
});
