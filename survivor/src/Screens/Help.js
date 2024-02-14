import React, { useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import { NavigationContainer, useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';

export default function HelpScreen({ navigation }) {
  const { colors } = useTheme();

  return (
    <View style={styles.container}>
      <Text style={{ color: colors.text }}>{t('help')}</Text>
    </View>
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
});
