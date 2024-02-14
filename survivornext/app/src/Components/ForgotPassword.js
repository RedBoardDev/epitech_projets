import React from 'react';
import { View, Text, Modal, TouchableOpacity, StyleSheet } from 'react-native';
import { t } from '../Translate';

const ForgotPasswordComponent = ({ visible, onClose }) => {
    return (
        <Modal
            animationType="fade"
            transparent={true}
            visible={visible}
        >
            <View style={styles.popupContainer}>
                <View style={styles.popup}>
                    <Text style={styles.popupText}>bah ratio mec</Text>
                    <TouchableOpacity onPress={onClose}>
                        <Text style={styles.closeButton}>{t('close')}</Text>
                    </TouchableOpacity>
                </View>
            </View>
        </Modal>
    );
};

const styles = StyleSheet.create({
    popupContainer: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: 'rgba(0, 0, 0, 0.5)',
    },
    popup: {
        backgroundColor: 'white',
        padding: 20,
        borderRadius: 10,
        elevation: 5,
        width: '80%',
    },
    popupText: {
        fontSize: 18,
        marginBottom: 10,
    },
    closeButton: {
        fontSize: 16,
        color: 'blue',
        textAlign: 'right',
    },
});

export default ForgotPasswordComponent;