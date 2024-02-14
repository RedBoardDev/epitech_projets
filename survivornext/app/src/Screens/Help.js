import React from 'react';
import { StyleSheet, View, Text} from 'react-native';
import { useTheme } from '@react-navigation/native';
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
