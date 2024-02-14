import AsyncStorage from '@react-native-async-storage/async-storage';

export const storeAsyncData = async (key, value) => {
    try {
        const jsonValue = JSON.stringify(value);
        await AsyncStorage.setItem(key, jsonValue);
    } catch (e) {
        console.error('Error while saving data:', e);
    }
};

export const getAsyncData = async (key) => {
    try {
        const jsonValue = await AsyncStorage.getItem(key);
        const value = jsonValue != null ? JSON.parse(jsonValue) : null;
        return value;
    } catch (e) {
        console.error('Error while retrieving data:', e);
    }
};

export const removeAsyncData = async (key) => {
    try {
        await AsyncStorage.removeItem(key);
    } catch (e) {
        console.error('Error while removing data:', e);
    }
};
