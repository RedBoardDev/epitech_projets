import React, { useEffect, useMemo, useState } from 'react';
import { Appearance } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import { StatusBar } from 'expo-status-bar';
import { changeLanguage } from './Translate';

import LoginScreen from './Screens/Login';
import NavBar from './NavBar';
import AppTheme from './Contexts/AppThemeContext';
import AppLanguage from './Contexts/AppLanguageContext';
import AppBiometry from './Contexts/AppBiometryContext';

export default function App() {
  const [theme, setTheme] = useState(undefined);
  const [language, setLanguage] = useState(undefined);
  const [biometry, setBiometry] = useState(undefined);
  const Stack = createStackNavigator();

  const Light = { "colors": { "background": "rgb(242, 242, 242)", "border": "rgb(216, 216, 216)", "card": "rgb(255, 255, 255)", "notification": "rgb(255, 59, 48)", "primary": "rgb(0, 122, 255)", "text": "rgb(28, 28, 30)" }, "dark": false }
  const Dark = { "colors": { "background": "rgb(1, 1, 1)", "border": "rgb(39, 39, 41)", "card": "rgb(22, 22, 22)", "notification": "rgb(255, 69, 58)", "primary": "rgb(10, 132, 255)", "text": "rgb(229, 229, 231)" }, "dark": true }

  useEffect(() => {
    AsyncStorage.getItem('theme').then((value) => {
      if (value) {
        setTheme(value);
      } else {
        setTheme('adaptive');
        AsyncStorage.setItem('theme', 'adaptive');
      }
    });
  }, []);

  useEffect(() => {
    AsyncStorage.getItem('language').then((value) => {
      if (value) {
        setLanguage(value);
      } else {
        setLanguage('english');
        AsyncStorage.setItem('language', 'english');
      }
    });
  }, []);

  useEffect(() => {
    AsyncStorage.getItem('biometry').then((value) => {
      if (value) {
        setBiometry(value === 'true');
      } else {
        setBiometry(false);
        AsyncStorage.setItem('biometry', 'false');
      }
    });
  }, []);

  useMemo(() => {
    changeLanguage(language === 'english' ? 'en' : language === 'francais' ? 'fr' : 'en');
  }, [language]);

  const getColorTheme = () => {
    if (theme === 'adaptive')
      return Appearance.getColorScheme();
    else
      return theme;
  }

  return (
    theme !== undefined && language !== undefined && biometry !== undefined &&
    <AppLanguage.Provider value={{ language, setLanguage }}>
      <AppTheme.Provider value={{ theme, setTheme }}>
        <AppBiometry.Provider value={{ biometry, setBiometry }}>
          <NavigationContainer theme={getColorTheme() === "dark" ? Dark : Light}>
            <Stack.Navigator>
              <Stack.Screen name="LoginScreen" component={LoginScreen} options={{ headerShown: false }} />
              <Stack.Screen name="NavBar" component={NavBar} options={{ headerShown: false }} />
            </Stack.Navigator>
            <StatusBar style={getColorTheme() === "dark" ? "light" : "dark"} />
          </NavigationContainer>
        </AppBiometry.Provider>
      </AppTheme.Provider>
    </AppLanguage.Provider>
  );
}
