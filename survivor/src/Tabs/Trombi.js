import React, { useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import { NavigationContainer, useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';

import TrombiScreen from '../Screens/Trombi';

export default function TrombiStackScreen() {
  const TrombiStack = createNativeStackNavigator();
  const { colors } = useTheme();

  return (
    <TrombiStack.Navigator>
      <TrombiStack.Screen name="TrombiScreen" component={TrombiScreen} options={{
        title: t('trombi'),
        ...styles.header,
        headerTitleStyle: [styles.headerTitle, { color: colors.primary }],
      }} />
    </TrombiStack.Navigator>
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
