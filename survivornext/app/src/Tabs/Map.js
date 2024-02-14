import React from 'react';
import { StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
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
