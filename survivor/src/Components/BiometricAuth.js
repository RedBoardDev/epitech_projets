import React, { useState, useEffect } from 'react';
import { View, Text, Button } from 'react-native';
import * as LocalAuthentication from 'expo-local-authentication';
import { t } from '../Translate';

const BiometricAuth = ({ onBiometricAuthComplete }) => {
    const [supported, setSupported] = useState(null);

    useEffect(() => {
        checkBiometrics();
        authenticate();
        // onBiometricAuthComplete(true);
    }, []);

    const checkBiometrics = async () => {
        const supported = await LocalAuthentication.hasHardwareAsync();
        if (supported) {
            setSupported(true);
        } else {
            setSupported(false);
        }
    };

    const authenticate = async () => {
        const result = await LocalAuthentication.authenticateAsync({
            promptMessage: t('verify your identity'),
        });

        if (result.success) {
            onBiometricAuthComplete(true);
        } else {
            onBiometricAuthComplete(false);
        }
    };

    return;
};

export default BiometricAuth;