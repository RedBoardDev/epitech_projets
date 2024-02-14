import React, { useEffect, useState } from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { t } from '../Translate';

export default function HomeProfile() {
    const { colors } = useTheme();
    const [me, setMe] = useState('');
    const [currentDate, setCurrentDate] = useState(new Date().toLocaleString());
    const [currentTime, setCurrentTime] = useState(new Date().toLocaleString());
    var monthNames = ['Jan', 'Fev', 'Mar', 'Apr', 'May','Jun',
    'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];

    useEffect(() => {
        const getData = async () => {
            try {
                const profileValue = await AsyncStorage.getItem('userProfil');
                return JSON.parse(profileValue);
            } catch (e) {
                console.error('Error when get profile item: ', e);
            }
        }
        getData().then(data => setMe(data));
    }, []);

    useEffect(() => {
        let secTimer = setInterval( () => {
            let date = new Date().getDate();
            let month = monthNames[new Date().getMonth()];
            let year = new Date().getFullYear();
            let hours = new Date().getHours();
            let min = new Date().getMinutes();
            let sec = new Date().getSeconds();
            setCurrentDate(date + ' ' + month + ' ' + year);
            setCurrentTime(hours + ':' + (min < 10 ? '0' : '') + min + ':' + (sec < 10 ? '0' : '') + sec)
        },1000)
        return () => clearInterval(secTimer);
    }, []);

    const names = me.name + ' ' + me.surname;

    return (
        <View style={[styles.container, { backgroundColor: colors.card }]}>
            <View>
                <Text style={[styles.welcome, { color: colors.text }]}>{t('welcome')} {names},</Text>
                <Text style={[styles.current, { color: colors.text }]}>{currentDate}</Text>
                <Text style={[styles.current, { color: colors.text }]}>{currentTime}</Text>
            </View>
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
    welcome: {
        fontSize: 25,
        fontWeight: 'bold',
    },
    current: {
        fontSize: 15,
        fontWeight: 'bold',
        alignSelf: 'center',
    }
});