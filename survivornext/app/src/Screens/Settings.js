import React, { useEffect, useContext } from 'react';
import { StyleSheet, Text, View, TouchableOpacity, DevSettings, SafeAreaView } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import SettingSwitch from '../Components/SettingSwitch';
import SettingSubPage from '../Components/SettingSubPage';
import AppBiometry from '../Contexts/AppBiometryContext';

export default function SettingsScreen({ navigation }) {
  const { biometry, setBiometry } = useContext(AppBiometry);
  const { colors } = useTheme();

  const toggleBiometry = () => {
    setBiometry(previousState => !previousState);
  };

  const logout = () => {
    AsyncStorage.removeItem('access_token');
    DevSettings.reload();
  };

  useEffect(() => {
    AsyncStorage.setItem('biometry', biometry.toString());
  }, [biometry]);

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <SettingSwitch text={t('biometry')} isEnabled={biometry} onChange={toggleBiometry} />
        <Text style={[styles.legendText, { color: colors.text }]}>{t('if you want to login with Face ID / Touch ID at application startup.')}</Text>
        <SettingSubPage navigation={navigation} route="WidgetsScreen" text={t('widgets')} />
        <SettingSubPage navigation={navigation} route="ThemeScreen" text={t('theme')} />
        <SettingSubPage navigation={navigation} route="LanguageScreen" text={t('language')} />
        <TouchableOpacity onPress={logout}>
          <Text style={{ color: colors.notification, textAlign: 'center', marginTop: 30, fontSize: 16 }}>{t('logout')}</Text>
        </TouchableOpacity>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    paddingVertical: 20,
    paddingHorizontal: 20,
    flexGrow: 1,
    flexShrink: 1,
    flexBasis: 0,
  },
  legendText: {
    fontSize: 11,
    marginTop: 0,
    marginBottom: 20,
    paddingHorizontal: 10,
  },
});

