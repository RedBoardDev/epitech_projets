const API_BASE_URL = 'https://plutus.thomasott.fr/survivor/chat';
import ImageBase64 from 'react-native-image-base64';

export const getRecentMessages = async (count) => {
    try {
        const response = await fetch(`${API_BASE_URL}/messages/${count}`);
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error fetching recent messages:', error);
        throw error;
    }
};

export const getAllMessages = async () => {
    try {
        const response = await fetch(`${API_BASE_URL}/messages`);
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error fetching all messages:', error);
        throw error;
    }
};

export const sendMessage = async (message, senderEmail, senderName) => {
    try {
        const response = await fetch(`${API_BASE_URL}/message`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                "senderEmail": senderEmail,
                "senderName": senderName,
                "message": message,
            }),
        });
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error adding a message:', error);
        throw error;
    }
};


export const sendImage = async (base64, senderEmail, senderName) => {
    try {
        // Créez un objet représentant l'image avec les données nécessaires
        console.log("d4");
        const imageToAdd = {
            "imageUri": `data:image/jpeg;base64,${base64}`, // Ajoutez la préfixe et le type appropriés
            "senderEmail": senderEmail,
            "senderName": senderName,
        };
        console.log("d5");
        // Envoyez l'objet image à votre API
        const response = await fetch(`${API_BASE_URL}/image`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(imageToAdd),
        });
        console.log("d2", data);
        const data = await response.json();
        console.log("d1");
        return data;
    } catch (error) {
        console.log("d3");
        console.error('Error adding an image:', error);
        throw error;
    }
};
