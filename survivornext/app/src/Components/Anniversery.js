import React, { useEffect, useState, useContext } from 'react';
import { StyleSheet, View, Image, Text, ScrollView, ActivityIndicator } from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';
import { useTheme } from '@react-navigation/native';

import { trombiApi } from '../Requests';
import UserInfos from '../Contexts/UserInfoContext';
import { t } from '../Translate';

const DispayBirthdayInfos = ({ elem, isToday }) => {
    const [profilePicture, setProfilePicture] = useState(null);
    const { colors, dark } = useTheme();

    useEffect(() => {
        trombiApi.getEmployeePP(elem.id).then((data) => {
            const fileReaderInstance = new FileReader();
            fileReaderInstance.readAsDataURL(data);
            fileReaderInstance.onload = () => {
                setProfilePicture(fileReaderInstance.result);
            }
        }).catch((error) => {
            console.error(error);
        });
    }, []);

    return (
        <View style={[styles.card, { backgroundColor: dark ? "#252525" : "#f5f5f5" }]}>
            <Image
                alt=""
                resizeMode="cover"
                source={profilePicture !== null ? { uri: profilePicture } : require('../../assets/Blank-profile.png')}
                style={styles.cardImg}
            />
            <View style={styles.cardBody}>
                <Text style={{ marginTop: 5, fontSize: 12, fontWeight: '700', color: colors.primary, textAlign: 'center' }}>{elem.name} {elem.surname}</Text>
                {!isToday && <Text style={{ fontSize: 8, fontWeight: '700', color: colors.text, textAlign: 'center' }}>{elem.birth_date}</Text>}
            </View>
        </View>
    )
}

export default function AnniversaryComponent() {
    const { colors } = useTheme();
    const { userInfos } = useContext(UserInfos);

    const renderEmployeess = (isToday) => {
        const res = userInfos.filter((elem) => {
            const currentDate = new Date();
            currentDate.setFullYear(2000);
            const weekDate = new Date();
            weekDate.setDate(currentDate.getDate() + 7);
            weekDate.setFullYear(2000);
            const bDate = new Date(elem.birth_date);
            bDate.setFullYear(2000);
            if (isToday) {
                return bDate === currentDate;
            } else {
                return bDate >= currentDate && bDate <= weekDate;
            }
        });

        if (res.length === 0)
            return (
                <Text style={{ fontSize: 12, fontWeight: '700', color: colors.text, textAlign: 'center' }}>{t('no birthday')}</Text>
            );
        else
            return (
                <ScrollView horizontal>
                    {res.map((elem) => (
                        <View key={elem.id} style={{ flex: 1 }} contentContainerStyle={styles.cardContainer}>
                            <DispayBirthdayInfos elem={elem} isToday={isToday} />
                        </View>
                    ))}
                </ScrollView>
            );
    };

    return (
        <View style={[styles.container, { backgroundColor: colors.card }]}>
            <View style={styles.nameContainer}>
                <Icon name="birthday-cake" size={30} color={colors.primary} />
                <Text style={[styles.popupTextName, { color: colors.text }]}>{t('today\'s birthdays')}</Text>
            </View>
            {userInfos !== undefined && renderEmployeess(true) || <ActivityIndicator size="large" />}
            <View style={styles.nameContainer}>
                <Text style={[styles.popupTextName, { color: colors.text }]}>{t('next week')}...</Text>
            </View>
            {userInfos !== undefined && renderEmployeess(false) || <ActivityIndicator size="large" />}
            <View style={{ margin: 10 }} />
        </View>
    )
}

const styles = StyleSheet.create({
    container: {
        width: '100%',
        borderRadius: 12,
        paddingHorizontal: 20,
        paddingVertical: 10,
        justifyContent: 'center',
        alignItems: 'center',
    },
    cardContainer: {
        flex: 1,
        flexDirection: "rows",
        flexWrap: "wrap",
        justifyContent: "space-around",
    },
    card: {
        width: 90,
        height: 110,
        margin: 10,
        marginBottom: 0,
        alignItems: "center",
        borderRadius: 12,
        padding: 4,
    },
    cardImg: {
        width: 62,
        height: 62,
        borderRadius: 10,
        marginTop: 5,
    },
    infoContainer: {
        textAlign: "left"
    },
    nameContainer: {
        alignItems: 'center',
        marginVertical: 5,
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
        marginVertical: 5,
    },
});
