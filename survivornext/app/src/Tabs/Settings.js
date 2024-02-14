import React from 'react';
import { StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

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
