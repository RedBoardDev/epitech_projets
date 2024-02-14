import React, { useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import { NavigationContainer, useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';

import ChatScreen from '../Screens/Chat';

export default function ChatStackScreen() {
  const ChatStack = createNativeStackNavigator();
  const { colors } = useTheme();

  return (
    <ChatStack.Navigator>
      <ChatStack.Screen name="Global chat" component={ChatScreen} options={{
        title: t('chat'),
        ...styles.header,
        headerTitleStyle: [styles.headerTitle, { color: colors.primary }],
      }} />
    </ChatStack.Navigator>
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
