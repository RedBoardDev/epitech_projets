import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, Image } from 'react-native';
import * as Location from 'expo-location';
import LoadingIndicator from './LoadingIndicator';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';

const WeatherComponent = () => {
    const [weatherData, setWeatherData] = useState(null);
    const [loading, setLoading] = useState(true);
    const { colors } = useTheme();

    useEffect(() => {
        const fetchWeatherData = async () => {
            try {
                const { status } = await Location.requestForegroundPermissionsAsync();
                if (status !== 'granted') {
                    console.error('Permission of geolocalisation not allowed.');
                    return;
                }

                const location = await Location.getCurrentPositionAsync({});
                const lat = location.coords.latitude;
                const lon = location.coords.longitude;

                const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&units=metric&appid=e203317f0df5474c05874e35b030eda3`);
                const data = await response.json();
                setWeatherData(data);
                setLoading(false);
            } catch (error) {
                console.error('Error for get weather data:', error);
                setLoading(false);
            }
        };

        fetchWeatherData();
    }, []);

    return (
        <View style={[styles.container, { backgroundColor: colors.card }]}>
            <View>
                <LoadingIndicator loading={loading} />
                {weatherData && (
                    <>
                        <View style={styles.header}>
                            <Text style={[styles.city, { color: colors.text }]}>{weatherData.name}</Text>
                            <Image
                                source={{ uri: `https://openweathermap.org/img/w/${weatherData.weather[0].icon}.png` }}
                                style={styles.weatherIcon}
                            />
                        </View>
                        <View style={styles.temperatureContainer}>
                            <Text style={[styles.temperature, { color: colors.text }]}>{Math.round(weatherData.main.temp)}°C</Text>
                            <View style={styles.details}>
                                <Text style={[styles.parameterLabel, { color: colors.text }]}>{t('wind')}: {weatherData.wind.speed} m/s</Text>
                                <Text style={[styles.parameterLabel, { color: colors.text }]}>{t('humidity')}: {weatherData.main.humidity}%</Text>
                            </View>
                        </View>
                    </>
                )}
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        width: '100%',
        borderRadius: 12,
        paddingHorizontal: 20,
        paddingVertical: 10,
        justifyContent: 'center',
        alignItems: 'center',
    },
    header: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
    },
    city: {
        fontWeight: '600',
        fontSize: 28,
        paddingHorizontal: 20,
        margin: 0,
        letterSpacing: 1,
    },
    weatherIcon: {
        width: 50,
        height: 50,
    },
    temperatureContainer: {
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'space-between',
        marginTop: 5,
    },
    temperature: {
        fontWeight: '500',
        fontSize: 44,
        width: 'auto',
        letterSpacing: -2,
        margin: 0,
    },
    details: {
        width: '50%',
        marginLeft: 20,
    },
    parameterLabel: {
        fontWeight: '400',
        fontSize: 18,
        textAlign: 'right',
    },
});

export default WeatherComponent;
