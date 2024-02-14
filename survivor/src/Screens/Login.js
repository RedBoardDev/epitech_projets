import React, { useContext, useEffect, useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet } from 'react-native';
import { LinearGradient } from 'expo-linear-gradient';
import Icon from 'react-native-vector-icons/FontAwesome';
import ForgotPasswordComponent from '../Components/ForgotPassword';
import { useNavigation } from '@react-navigation/native';
import { login, getMe } from '../Requests';
import { LOGIN_PASSWORD, LOGIN_EMAIL } from "@env"
import { Alert } from 'react-native';
import BiometricAuth from '../Components/BiometricAuth';
import AsyncStorage from '@react-native-async-storage/async-storage';
import AppBiometry from '../AppBiometryContext';

const LoginScreen = () => {
    const navigation = useNavigation();
    const { biometry, setBiometry } = useContext(AppBiometry);

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const [emailStyle, setEmailStyle] = useState({});
    const [isPasswordVisible, setPasswordVisibility] = useState(false);
    const [showBiometricAuth, setShowBiometricAuth] = useState(false);
    const [isPopupVisible, setPopupVisibility] = useState(false);

    const navigateToHome = () => {
        navigation.navigate('NavBar');
        navigation.reset({
            index: 0,
            routes: [{ name: 'NavBar' }],
        });
    };

    useEffect(() => {
        async function fetchToken() {
            try {
                let token = await AsyncStorage.getItem('access_token');
                if (token) {
                    if (biometry) {
                        setShowBiometricAuth(true);
                    }
                    else {
                        setShowBiometricAuth(false);
                        const rsp = await getMe();
                        if (rsp) {
                            navigateToHome();
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
            const rsp = await login(email, password);
            if (rsp === true)
                navigateToHome();
            else {
                Alert.alert('Login error', rsp.toString());
            }
        }
    };

    const handleBiometricAuthComplete = async (success) => {
        if (success) {
            const rsp = await getMe();
            if (rsp) {
                navigateToHome();
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
                <View style={styles.welcomeContainer}>
                    <Text style={styles.welcomeText}>Welcome</Text>
                    <Text style={styles.subtitleText}>Login to your access</Text>
                </View>
                <TouchableOpacity style={styles.loginButton} onPress={handleLoginPress}>
                    <Text style={styles.loginButtonText}>Connexion</Text>
                </TouchableOpacity>

                <View style={styles.formContainer}>
                    <View style={styles.inputContainer}>
                        <Icon name="user" size={24} color="#245684" style={styles.icon} />
                        <TextInput
                            placeholder="Nom d'utilisateur"
                            placeholderTextColor="rgba(255, 255, 255, 0.6)"
                            style={[styles.textInput, emailStyle]}
                            value={email}
                            onChangeText={(text) => { handleEmailFocus(); setEmail(text) }}
                        />
                    </View>
                    <View style={styles.inputContainer}>
                        <Icon name="lock" size={24} color="#245684" style={styles.icon} />
                        <TextInput
                            placeholder="Mot de passe"
                            placeholderTextColor="rgba(255, 255, 255, 0.6)"
                            style={styles.textInput}
                            secureTextEntry={!isPasswordVisible}
                            value={password}
                            onChangeText={(text) => setPassword(text)}
                        />
                        <TouchableOpacity onPress={togglePasswordVisibility}>
                            <Icon name={isPasswordVisible ? "eye" : "eye-slash"} size={24} color="#245684" style={styles.eyeIcon} />
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
        padding: 20,
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
        backgroundColor: '#245684',
        paddingVertical: 20,
        borderRadius: 15,
        position: 'absolute',
        bottom: 20,
        left: '5%',
        right: '5%',
        alignItems: 'center',
        justifyContent: 'center',
        transform: [{ translateY: 2 }],
        shadowColor: '#000',
        shadowOffset: {
            width: 0,
            height: -5,
        },
        shadowOpacity: 0.5,
        shadowRadius: 5,
        elevation: 6,
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
