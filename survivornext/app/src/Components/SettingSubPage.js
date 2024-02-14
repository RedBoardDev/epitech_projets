import React from 'react';
import { Text, View, StyleSheet, TouchableOpacity } from 'react-native';
import { useTheme } from '@react-navigation/native';
import FeatherIcon from 'react-native-vector-icons/Feather';

export default function SettingSubPage({ navigation, text, route }) {
  const { colors } = useTheme();

  return (
    <TouchableOpacity onPress={() => { navigation.navigate(route) }}>
      <View style={[styles.container, { backgroundColor: colors.card }]}>
        <Text style={{ color: colors.text }}>{text}</Text>
        <View style={styles.cardAction}>
          <FeatherIcon
            color="#9ca3af"
            name="chevron-right"
            size={22}
          />
        </View>
      </View>
    </TouchableOpacity>
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
  cardAction: {
    paddingRight: 0,
  },
});
