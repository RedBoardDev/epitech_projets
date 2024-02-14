import React from 'react';
import { StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
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
