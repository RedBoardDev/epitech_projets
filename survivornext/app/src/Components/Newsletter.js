import React, { useEffect, useState } from 'react';
import { View, Text, StyleSheet, Image, Linking } from 'react-native';
import Icon from 'react-native-vector-icons/Entypo';
import LoadingIndicator from './LoadingIndicator';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import { newsApi } from "../Requests";

const NewsWidget = () => {
    const [newsData, setNewsData] = useState(null);
    const [loading, setLoading] = useState(true);
    const { colors } = useTheme();

    useEffect(() => {
        newsApi.getNews('all')
            .then(data => {
                setNewsData(data.data);
                setLoading(false);
            })
            .catch(error => {
                setLoading(false);
            });
    }, []);

    return (
        <View style={[styles.container, { backgroundColor: colors.card }]}>
            <View style={styles.header}>
                <Text style={[styles.newsTitle, { color: colors.primary }]}>
                    <Icon name="news" size={20} color={colors.primary} /> {t('news').toUpperCase()}
                </Text>
            </View>
            <LoadingIndicator loading={loading}>
                {newsData && newsData.slice(0, 5).map((item, index) => (
                    <View style={styles.content} key={index}>
                        <View style={styles.textContainer}>
                            <Text style={[styles.author, { color: colors.text }]}>{item.author}</Text>
                            <Text
                                style={[styles.title, { color: colors.text }]}
                                onPress={() => Linking.openURL(item.readMoreUrl)}
                            >
                                {item.title.split(':')[0]}
                            </Text>

                        </View>

                        <View style={styles.imageContainer}>
                            <Image
                                source={{ uri: item.imageUrl }}
                                style={styles.image}
                            />
                        </View>
                    </View>
                ))}
            </LoadingIndicator>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        width: '100%',
        borderRadius: 12,
        paddingHorizontal: 20,
        paddingVertical: 10,
    },
    header: {
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'space-between',
    },
    newsTitle: {
        fontSize: 18,
        fontWeight: 'bold',
    },
    title: {
        flex: 1,
        fontSize: 16,
        fontWeight: 'bold',
        marginBottom: 5,
    },
    author: {
        fontSize: 6,
        fontWeight: 'bold',
    },
    textContainer: {
        flex: 1,
        flexDirection: 'column',
    },

    content: {
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'space-between',
        marginTop: 16,
    },
    imageContainer: {
        width: 70,
        height: 70,
        borderRadius: 8,
        marginLeft: 10,
        marginRight: 10,
    },
    image: {
        width: '100%',
        height: '100%',
        borderRadius: 8,
        marginRight: 10,
    },
});

export default NewsWidget;
