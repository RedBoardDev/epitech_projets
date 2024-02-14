import React, { useState, useEffect, useContext } from 'react';
import { StyleSheet, Text, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import OptionSelect from '../Components/OptionSelect';
import AppLanguage from '../AppLanguageContext';

export default function LanguageScreen({ navigation }) {
  const { language, setLanguage } = useContext(AppLanguage);
  const [selected, setSelected] = useState(language === 'english' ? 0 : language === 'francais' ? 1 : 0);
  const { colors } = useTheme();

  const updateLanguage = (newLanguage) => {
    newLanguage = newLanguage.toLowerCase();
    setLanguage(newLanguage);
    AsyncStorage.setItem('language', newLanguage);
  };

  useEffect(() => {
    updateLanguage(selected === 0 ? 'english' : 'francais');
  }, [selected]);

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <Text style={{ color: colors.text, marginBottom: 15 }}>{t('choose the language of the app.')}</Text>
        <OptionSelect list={["English", "Francais"]} selected={selected} setSelected={setSelected} />
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
