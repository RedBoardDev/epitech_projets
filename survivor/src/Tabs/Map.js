import React, { useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import { NavigationContainer, useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';

import MapScreen from '../Screens/Map';

export default function MapStackScreen() {
  const MapStack = createNativeStackNavigator();
  const { colors } = useTheme();

  return (
    <MapStack.Navigator>
      <MapStack.Screen name="MapScreen" component={MapScreen} options={{
        title: t('map'),
        ...styles.header,
        headerTitleStyle: [styles.headerTitle, { color: colors.primary }],
      }} />
    </MapStack.Navigator>
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
