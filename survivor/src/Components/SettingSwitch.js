import React from 'react';
import { Text, View, Switch, StyleSheet } from 'react-native';
import { useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';

export default function SettingSwitch({ text, isEnabled, onChange }) {
  const { colors } = useTheme();

  return (
    <View style={[styles.container, { backgroundColor: colors.card }]}>
      <Text style={{ color: colors.text }}>{text}</Text>
      <Switch
        onValueChange={onChange}
        value={isEnabled}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    height: 45,
    margin: 2,
    padding: 6,
    paddingHorizontal: 12,
    borderRadius: 8,
  },
});
