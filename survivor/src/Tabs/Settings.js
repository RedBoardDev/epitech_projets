import React, { useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import { NavigationContainer, useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Ionicons } from '@expo/vector-icons';

import SettingsScreen from '../Screens/Settings';
import WidgetsScreen from '../Screens/SettingsWidgets';
import ThemeScreen from '../Screens/SettingsTheme';
import LanguageScreen from '../Screens/SettingsLanguage';
import { t } from '../Translate';

export default function SettingsStackScreen() {
  const SettingsStack = createNativeStackNavigator();
  const { colors } = useTheme();

  return (
    <SettingsStack.Navigator>
      <SettingsStack.Screen name="SettingsScreen" component={SettingsScreen} options={{
        title: t('settings'),
        ...styles.header,
        headerTitleStyle: [styles.headerTitle, { color: colors.primary }],
      }} />
      <SettingsStack.Screen name="WidgetsScreen" component={WidgetsScreen} options={{
        title: t('widgets'),
      }} />
      <SettingsStack.Screen name="ThemeScreen" component={ThemeScreen} options={{
        title: t('theme'),
      }} />
      <SettingsStack.Screen name="LanguageScreen" component={LanguageScreen} options={{
        title: t('language'),
      }} />
    </SettingsStack.Navigator>
  );
}

const styles = StyleSheet.create({
  header: {
    headerTitleAlign: 'center',
  },
  headerTitle: {
    fontWeight: 'bold',
    fontSize: 26,
  },
});
