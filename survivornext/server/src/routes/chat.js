const uuid = require('uuid');
const fs = require('fs');

const express = require('express');
const router = express.Router();

// endpoints

function getMessages() {
    try {
        const data = fs.readFileSync('data/messages.json', 'utf8');
        return JSON.parse(data).messages;
    } catch (error) {
        console.error('Error while reading messages:', error);
        return [];
    }
}

function addMessage(message, isImage = false) {
    try {
        const messages = getMessages();
        const messageToAdd = {
            id: uuid.v4(),
            message: isImage ? null : message.message,
            imageUri: isImage ? message.imageUri : null,
            senderEmail: message.senderEmail,
            senderName: message.senderName,
            created_at: new Date(),
        };

        messages.push(messageToAdd);
        fs.writeFileSync('data/messages.json', JSON.stringify({ messages }, null, 2), 'utf8');
        return messageToAdd;
    } catch (error) {
        throw new Error(`Error when adding a ${isImage ? 'image' : 'message'}`);
    }
}

function getMessagesWithSenderInfo() {
    const messages = getMessages();
    return messages;
}

router.get('/messages/:type/:value', async (req, res) => {
    let result;
    const type = req.params.type;
    const value = req.params.value;

    switch (type) {
        case 'count':
            const valueI = parseInt(value);
            result = getMessagesWithSenderInfo().slice(-valueI);
            break;
        case 'timestamp':
            result = getMessagesWithSenderInfo().filter(message => message.created_at > value);
            break;
        default:
            res.status(400).json({ error: 'Invalid route type' });
            return;
    }

    res.status(200).json(result);
});

router.get('/messages', async (req, res) => {
    const messages = getMessagesWithSenderInfo();
    res.status(200).json(messages);
});

router.post('/message', (req, res) => {
    try {
        const newMessage = req.body;

        if (!newMessage.message || !newMessage.senderEmail || !newMessage.senderName) {
            throw new Error('Some required fields are missing in newMessage');
        }

        const messageToAdd = addMessage(newMessage);
        res.status(201).json(messageToAdd);
    } catch (error) {
        console.error('Error when adding an message:', error);
        res.status(500).json({ error: error.message });
    }
});

router.post('/image', async (req, res) => {
    try {
        const imageData = req.body;

        if (!imageData.imageUri || !imageData.senderEmail || !imageData.senderName) {
            throw new Error('Some required fields are missing in imageData');
        }

        const imageToAdd = addMessage(imageData, true);
        res.status(201).json(imageToAdd);
    } catch (error) {
        console.error('Error when adding an image:', error);
        res.status(500).json({ error: error.message });
    }
});

router.get('/', async (req, res) => {
    res.status(200).json('chat endpoint');
});

module.exports = router;
