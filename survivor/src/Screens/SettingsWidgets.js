import React, { useState, useEffect, useContext } from 'react';
import { StyleSheet, Text, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import SettingSwitch from '../Components/SettingSwitch';
import { WeatherWidget, NewsWidget, TodoWidget } from '../WidgetContexts';

export default function WidgetsScreen({ navigation }) {
  const { colors } = useTheme();
  const { weatherWidget, setWeatherWidget } = useContext(WeatherWidget);
  const { newsWidget, setNewsWidget } = useContext(NewsWidget);
  const { todoWidget, setTodoWidget } = useContext(TodoWidget);

  useEffect(() => {
    AsyncStorage.setItem('weather', weatherWidget ? 'true' : 'false');
  }, [weatherWidget]);

  useEffect(() => {
    AsyncStorage.setItem('news', newsWidget ? 'true' : 'false');
  }, [newsWidget]);

  useEffect(() => {
    AsyncStorage.setItem('todo', todoWidget ? 'true' : 'false');
  }, [todoWidget]);

  const toggleWeather = () => {
    setWeatherWidget(previousState => !previousState);
  };

  const toggleNews = () => {
    setNewsWidget(previousState => !previousState);
  };

  const toggleTodo = () => {
    setTodoWidget(previousState => !previousState);
  };

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <Text style={{ color: colors.text, marginBottom: 15 }}>{t('choose which widgets do you want to see in your home page.')}</Text>
        <SettingSwitch text={t('weather')} isEnabled={weatherWidget} onChange={toggleWeather} />
        <SettingSwitch text={t('news')} isEnabled={newsWidget} onChange={toggleNews} />
        <SettingSwitch text={t('todo')} isEnabled={todoWidget} onChange={toggleTodo} />
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
