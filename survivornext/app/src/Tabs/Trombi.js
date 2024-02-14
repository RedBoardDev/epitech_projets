import React from 'react';
import { StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
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
