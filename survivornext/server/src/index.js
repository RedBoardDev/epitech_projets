const bodyParser = require('body-parser');
require('dotenv').config();

const express = require('express');
const cors = require('cors');

const app = express();
const port = process.env.PORT || 4000;

app.use(cors());
app.use(bodyParser.json({ limit: '100mb' }));
app.use(bodyParser.urlencoded({ limit: '100mb', extended: true }));

// ROUTES

const routerChat = require('./routes/chat');
const routerTrombinoscope = require('./routes/trombinoscope');
const routerNews = require('./routes/news');

app.use('/chat', routerChat);
app.use('/api/', routerTrombinoscope);
app.use('/news/', routerNews);

app.get('/', (req, res) => {
    res.status(200).json('API survivor');
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
