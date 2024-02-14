import React, { useState, useEffect, useContext } from 'react';
import { StyleSheet, Text, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import AppTheme from '../AppThemeContext';
import OptionSelect from '../Components/OptionSelect';

export default function ThemeScreen({ navigation }) {
  const { theme, setTheme } = useContext(AppTheme);
  const [selected, setSelected] = useState(theme === 'adaptive' ? 0 : theme === 'dark' ? 1 : 2);
  const { colors } = useTheme();

  const updateTheme = (newtheme) => {
    newtheme = newtheme.toLowerCase();
    setTheme(newtheme);
    AsyncStorage.setItem('theme', newtheme);
  };

  useEffect(() => {
    updateTheme(selected === 0 ? 'adaptive' : selected === 1 ? 'dark' : 'light');
  }, [selected]);

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <Text style={{ color: colors.text, marginBottom: 15 }}>{t('choose the appearance of the app.')}</Text>
        <OptionSelect list={[t('adaptive'), t('dark'), t('light')]} selected={selected} setSelected={setSelected} />
      </View>
    </SafeAreaView>
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
