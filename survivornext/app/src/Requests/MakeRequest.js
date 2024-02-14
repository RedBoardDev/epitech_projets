import { GROUP_TOKEN, API_BASE_URL } from "@env";
import AsyncStorage from '@react-native-async-storage/async-storage';

function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

export async function makeRequest(method, url, token, body = {}, contentType = "application/json") {
    if (!token) {
        token = await AsyncStorage.getItem('access_token');
    }

    const options = {
        method: method,
        headers: {
            "Content-Type": contentType,
            "Authorization": 'Bearer ' + token,
            "X-Group-Authorization": GROUP_TOKEN,
        },
    };
    if (method !== "GET") {
        options.body = JSON.stringify(body);
    }
    const response = await fetch(API_BASE_URL + url, options);
    if (!response.ok) {
        if (response.status === 429) {
            console.error('429: too many requests, retrying in 10 seconds...');
            await delay(10000);
            return await makeRequest(method, API_BASE_URL + url, token, body, contentType);
        } else
            throw new Error(`${response.status} ${await response.text()} ${response.url}`);
    }
    return response;
}