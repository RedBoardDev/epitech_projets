import React from 'react';
import { View, ActivityIndicator, StyleSheet } from 'react-native';

const LoadingIndicator = ({ loading, children }) => {
    if (loading) {
        return (
            <View style={styles.loadingContainer}>
                <ActivityIndicator size="large" color="blue" />
            </View>
        );
    }
    return children;
};

const styles = StyleSheet.create({
    loadingContainer: {
        justifyContent: 'center',
        alignItems: 'center',
    },
});

export default LoadingIndicator;
