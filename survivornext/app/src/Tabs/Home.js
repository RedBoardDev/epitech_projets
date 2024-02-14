import React from 'react';
import { StyleSheet } from 'react-native';
import {  useTheme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';

import HomeScreen from '../Screens/Home';
import HelpScreen from '../Screens/Help';
import { t } from '../Translate';

export default function HomeStackScreen() {
  const HomeStack = createNativeStackNavigator();
  const { colors } = useTheme();

  return (
    <HomeStack.Navigator>
      <HomeStack.Screen name="HomeScreen" component={HomeScreen} options={{
        title: t('home'),
        ...styles.header,
        headerTitleStyle: [styles.headerTitle, { color: colors.primary }],
      }} />
      <HomeStack.Screen name="HelpScreen" component={HelpScreen} options={{
        title: t('help'),
      }} />
    </HomeStack.Navigator>
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
