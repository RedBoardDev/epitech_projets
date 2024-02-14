import React, { useContext, useEffect, useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, Image } from 'react-native';
import { LinearGradient } from 'expo-linear-gradient';
import Icon from 'react-native-vector-icons/FontAwesome';
import ForgotPasswordComponent from '../Components/ForgotPassword';
import { useNavigation } from '@react-navigation/native';
import { trombiApi } from '../Requests';
import { LOGIN_PASSWORD, LOGIN_EMAIL } from "@env"
import { Alert } from 'react-native';
import BiometricAuth from '../Components/BiometricAuth';
import AsyncStorage from '@react-native-async-storage/async-storage';
import AppBiometry from '../Contexts/AppBiometryContext';
import { ImageBackground } from 'react-native';

const LoginScreen = () => {
    const navigation = useNavigation();
    const { biometry } = useContext(AppBiometry);

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const [emailStyle, setEmailStyle] = useState({});
    const [isPasswordVisible, setPasswordVisibility] = useState(false);
    const [showBiometricAuth, setShowBiometricAuth] = useState(false);
    const [isPopupVisible, setPopupVisibility] = useState(false);

    useEffect(() => {
        async function fetchToken() {
            try {
                const token = await AsyncStorage.getItem('access_token');
                if (token) {
                    if (biometry) {
                        setShowBiometricAuth(true);
                    } else {
                        setShowBiometricAuth(false);
                        if (await verifyAuthentification()) {
                            return;
                        }
                    }
                }
            } catch (error) {
                setShowBiometricAuth(false);
                console.error(error);
            }
        }
        setEmail(LOGIN_EMAIL);
        setPassword(LOGIN_PASSWORD);
        fetchToken();
    }, []);

    const navigateToHome = () => {
        navigation.reset({
            index: 0,
            routes: [{ name: 'NavBar' }],
        });
    };

    const verifyAuthentification = async () => {
        const rsp = await trombiApi.getMe();
        if (rsp) {
            navigateToHome();
            try {
                const jsonValue = JSON.stringify(rsp);
                await AsyncStorage.setItem('userProfil', jsonValue);
            } catch (e) {
                console.error('Error when save user profil:', e);
            }
            return true;
        }
        return false;
    }

    const handleLoginPress = async () => {
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

        setEmailStyle({});
        if (!email || !password) {
            Alert.alert('Login error', "Please fill email and password");
            return;
        } else if (!emailRegex.test(email)) {
            setEmailStyle({ color: 'red' });
            return;
        } else {
            const rsp = await trombiApi.login(email, password);
            if (await verifyAuthentification()) {
                return;
            }
            else {
                Alert.alert('Login error', rsp.toString());
            }
        }
    };

    const handleBiometricAuthComplete = async (success) => {
        if (success) {
            if (await verifyAuthentification()) {
                return;
            }
            setShowBiometricAuth(false);
            Alert.alert('Log in expired', "Please authentificate you with your email and your password");
        } else {
            setShowBiometricAuth(false);
        }
    };

    const togglePasswordVisibility = () => {
        setPasswordVisibility(!isPasswordVisible);
    };

    const togglePopupVisibility = () => {
        setPopupVisibility(!isPopupVisible);
    };

    const handleEmailFocus = () => {
        setEmailStyle({});
    };

    return (
        <View style={styles.container}>
            <LinearGradient
                colors={['#7B72DF', '#245684']}
                style={styles.gradient}
            >
                <ImageBackground source={require('../../assets/LoginBg.jpg')} style={{ width: '100%', height: '100%', position: 'absolute' }}>
                </ImageBackground>
                <View style={styles.welcomeContainer}>
                    <Image
                        source={{
                            uri: 'https://media.discordapp.net/attachments/1146026043879211060/1151174607114620988/Icon4.png'
                        }}
                        style={{ width: 100, height: 100 }}
                    />
                    <Text style={styles.welcomeText}>Welcome</Text>
                    <Text style={styles.subtitleText}>Login to your access</Text>
                </View>
                <TouchableOpacity style={styles.loginButton} onPress={handleLoginPress}>
                    <Text style={styles.loginButtonText}>Login</Text>
                </TouchableOpacity>

                <View style={styles.formContainer}>
                    <View style={styles.inputContainer}>
                        <Icon name="user" size={24} color="white" style={styles.icon} />
                        <TextInput
                            placeholder="Nom d'utilisateur"
                            placeholderTextColor="rgba(255, 255, 255, 0.6)"
                            style={[styles.textInput, emailStyle]}
                            value={email}
                            onChangeText={(text) => { handleEmailFocus(); setEmail(text) }}
                        />
                    </View>
                    <View style={styles.inputContainer}>
                        <Icon name="lock" size={24} color="white" style={styles.icon} />
                        <TextInput
                            placeholder="Mot de passe"
                            placeholderTextColor="rgba(255, 255, 255, 0.6)"
                            style={styles.textInput}
                            secureTextEntry={!isPasswordVisible}
                            value={password}
                            onChangeText={(text) => setPassword(text)}
                        />
                        <TouchableOpacity onPress={togglePasswordVisibility}>
                            <Icon name={isPasswordVisible ? "eye" : "eye-slash"} size={24} color="white" style={styles.eyeIcon} />
                        </TouchableOpacity>
                    </View>
                    <Text style={styles.forgotPasswordText} onPress={togglePopupVisibility}>Mot de passe oublié ?</Text>
                </View>

                {showBiometricAuth && (
                    <BiometricAuth onBiometricAuthComplete={handleBiometricAuthComplete} />
                )}
            </LinearGradient>
            <ForgotPasswordComponent visible={isPopupVisible} onClose={togglePopupVisibility} />
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },
    gradient: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
    },
    welcomeContainer: {
        alignItems: 'center',
        marginBottom: 20,
    },
    welcomeText: {
        color: 'white',
        fontSize: 55,
        fontWeight: 'bold',
    },
    subtitleText: {
        color: 'white',
        fontSize: 18,
    },
    formContainer: {
        width: '80%',
        padding: 10,
        backgroundColor: 'transparent',
        alignItems: 'center',
        borderRadius: 15,
    },
    inputContainer: {
        flexDirection: 'row',
        alignItems: 'center',
        marginBottom: 10,
        backgroundColor: 'rgba(255, 255, 255, 0.2)',
        borderRadius: 15,
        paddingHorizontal: 20,
        height: 60,
    },
    icon: {
        marginRight: 15,
    },
    textInput: {
        flex: 1,
        color: 'white',
        fontSize: 18,
    },
    eyeIcon: {
        marginLeft: 15,
    },
    loginButton: {
        backgroundColor: 'rgba(255, 255, 255, 0.1)',
        paddingVertical: 20,
        borderRadius: 15,
        position: 'absolute',
        bottom: 80,
        left: '15%',
        right: '15%',
        alignItems: 'center',
        justifyContent: 'center',
        borderWidth: 1,
        borderColor: 'rgba(255, 255, 255, 0.2)',
        backdropFilter: 'blur(10px)',
        boxShadow: '10px 10px 30px rgba(0, 0, 0, 0.2), -10px -10px 30px rgba(255, 255, 255, 0.2)',
    },

    loginButtonText: {
        color: 'white',
        fontWeight: 'bold',
        fontSize: 18,
        textAlign: 'center',
    },
    forgotPasswordText: {
        color: 'white',
        fontSize: 16,
        textDecorationLine: 'underline',
        alignSelf: 'flex-end',
        marginTop: 10,
        marginRight: 10,
    },
});

export default LoginScreen;
