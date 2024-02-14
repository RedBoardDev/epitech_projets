const uuid = require('uuid');
const axios = require('axios');
const { DateTime } = require('luxon');

const express = require('express');
const router = express.Router();

const API_BASE_URL = 'https://inshorts.com/api/en';

// endpoints

router.get('/news', async (req, res) => {
    const category = req.query.category;

    if (!category) {
        return res.status(400).json({
            error: 'please add category in query params',
        });
    }

    try {
        const response = await axios.get(`${API_BASE_URL}/search/trending_topics/${category}`, {
            params: {
                category: 'top_stories',
                max_limit: 10,
                include_card_data: true,
            },
        });

        const news_data = response.data.data.news_list;
        const newsList = news_data.map((entry) => {
            const news = entry.news_obj;
            if (!news) {
                return null;
            }

            const timestamp = news.created_at / 1000;
            const dt_utc = DateTime.fromSeconds(timestamp, { zone: 'utc' });
            const dt_ist = dt_utc.setZone('Asia/Kolkata');

            return {
                id: uuid.v4(),
                title: news.title,
                imageUrl: news.image_url,
                url: news.shortened_url,
                content: news.content,
                author: news.author_name,
                date: dt_ist.toFormat('EEEE, dd LLLL, yyyy'),
                time: dt_ist.toFormat('hh:mm a'),
                readMoreUrl: news.source_url,
            };
        });

        const filteredNewsList = newsList.filter((news) => news !== null);

        res.status(200).json({
            success: true,
            category: category,
            data: filteredNewsList,
        });

    } catch (error) {
        console.error(error);
        res.status(500).json({
            error: 'Internal Server Error',
        });
    }
});

router.get('/', async (req, res) => {
    res.status(200).json('news endpoint');
});

module.exports = router;
