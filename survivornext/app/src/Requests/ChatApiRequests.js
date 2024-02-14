import { makeRequest } from "./MakeRequest";

export const getRecentMessages = async (date) => {
    try {
        const rsp = await makeRequest("GET", `/chat/messages/timestamp/${date}`);
        const data = await rsp.json();
        return data;
    } catch (error) {
        console.log('Error fetching recent messages:', error);
        return [];
    }
};

export const getLastXMessages = async (count) => {
    try {
        const rsp = await makeRequest("GET", `/chat/messages/count/${count}`);
        const data = await rsp.json();
        return data;
    } catch (error) {
        console.log('Error fetching last messages:', error);
        return [];
    }
};

export const getAllMessages = async () => {
    try {
        const rsp = await makeRequest("GET", `/chat/messages`);
        const data = await rsp.json();
        return data;
    } catch (error) {
        console.log('Error fetching all messages:', error);
        return [];
    }
};

export const sendMessage = async (message, senderEmail, senderName) => {
    try {
        const body = {
            senderEmail: senderEmail,
            senderName: senderName,
            message: message,
        };

        const rsp = await makeRequest("POST", `/chat/message`, null, body, "application/json");
        const data = await rsp.json();
        return data;
    } catch (error) {
        console.log('Error adding a message:', error);
        throw error;
    }
};

export const sendImage = async (base64, senderEmail, senderName) => {
    try {
        const body = {
            imageUri: `data:image/jpeg;base64,${base64}`,
            senderEmail: senderEmail,
            senderName: senderName,
        };

        const rsp = await makeRequest("POST", `/chat/image`, null, body, "application/json");
        const data = await rsp.json();
        return data;
    } catch (error) {
        console.log('Error adding an image:', error);
        throw error;
    }
};
