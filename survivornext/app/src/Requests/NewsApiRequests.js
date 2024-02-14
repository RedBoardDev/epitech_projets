import { makeRequest } from "./MakeRequest";

export async function getNews(category) {
    try {
        const response = await makeRequest("GET", `/news/news?category=${category}`);
        return response.json();
    } catch (error) {
        console.log('Error fetch news:', error);
        throw error;
    }
}
