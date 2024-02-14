import { GROUP_TOKEN } from "@env"
import AsyncStorage from '@react-native-async-storage/async-storage';

const baseUrl = "https://masurao.fr";
let lastRequestTime = 0;

function delay(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

export async function makeRequest(method, url, token, body = {}, contentType = "application/json") {
  if (!token) {
    token = await AsyncStorage.getItem('access_token');
  }
  const currentTime = Date.now();
  const elapsedTime = currentTime - lastRequestTime;
  if (elapsedTime < 1000) {
    await delay(1000 - elapsedTime);
  }
  lastRequestTime = Date.now();

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
  const response = await fetch(url, options);
  if (!response.ok) {
    throw new Error(`${response.status} ${await response.text()} ${response.url}`);
  }
  return response;
}

export async function login(email, password) {
  const url = baseUrl + "/api/employees/login";
  try {
    const rsp1 = await makeRequest("POST", url, "", {
      email: email,
      password: password,
    });
    const rsp = await rsp1.json();
    if (!rsp || (!rsp.detail && !rsp.access_token)) {
      return 'API error';
    }
    if (!rsp.access_token) {
      return rsp.detail;
    }
    await AsyncStorage.setItem('access_token', rsp.access_token);
    return true;
  } catch (error) {
    return 'Identifiants invalides';
  }
}

export async function getEmployees() {
  return (await makeRequest("GET", baseUrl + "/api/employees")).json();
}

export async function getEmployee(id) {
  return (await makeRequest("GET", baseUrl + "/api/employees/" + id)).json();
}

export async function getMe() {
  try {
    const response = await makeRequest("GET", baseUrl + "/api/employees/me");
    return response.json();
  } catch (error) {
    return undefined;
  }
}

export async function getLeaders() {
  return (await makeRequest("GET", baseUrl + "/api/employees/leaders")).json();
}

export async function getEmployeePP(id) {
  return (await makeRequest("GET", baseUrl + "/api/employees/" + id + "/image", null, {}, "image/png")).blob();
}
