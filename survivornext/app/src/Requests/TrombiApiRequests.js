import AsyncStorage from '@react-native-async-storage/async-storage';
import { makeRequest } from "./MakeRequest";

export async function login(email, password) {
    const url = "/api/employees/login";
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
    return (await makeRequest("GET", "/api/employees")).json();
}

export async function getEmployee(id) {
    return (await makeRequest("GET", "/api/employees/" + id)).json();
}

export async function getMe() {
    try {
        const response = await makeRequest("GET", "/api/employees/me");
        return response.json();
    } catch (error) {
        console.log(error);
        return undefined;
    }
}

export async function getLeaders() {
    return (await makeRequest("GET", "/api/employees/leaders")).json();
}

export async function getEmployeePP(id) {
    return (await makeRequest("GET", "/api/employees/" + id + "/image", null, {}, "image/png")).blob();
}

export async function setStatusEmployees(id, status) {
    return (await makeRequest("POST", "/api/employees/status/" + id + "/" + status));
}