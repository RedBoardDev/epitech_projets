import React, { useEffect, useContext } from 'react';
import { StyleSheet, Text, View, SafeAreaView } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import SettingSwitch from '../Components/SettingSwitch';
import { WeatherWidget, NewsWidget, TodoWidget, BirthdayContext } from '../Contexts/WidgetContexts';

export default function WidgetsScreen() {
  const { colors } = useTheme();
  const { weatherWidget, setWeatherWidget } = useContext(WeatherWidget);
  const { newsWidget, setNewsWidget } = useContext(NewsWidget);
  const { todoWidget, setTodoWidget } = useContext(TodoWidget);
  const { birthdayWidget, setBirthdayWidget } = useContext(BirthdayContext);

  useEffect(() => {
    AsyncStorage.setItem('weather', weatherWidget ? 'true' : 'false');
  }, [weatherWidget]);

  useEffect(() => {
    AsyncStorage.setItem('news', newsWidget ? 'true' : 'false');
  }, [newsWidget]);

  useEffect(() => {
    AsyncStorage.setItem('todo', todoWidget ? 'true' : 'false');
  }, [todoWidget]);

  useEffect(() => {
    AsyncStorage.setItem('birthday', birthdayWidget ? 'true' : 'false');
  }, [birthdayWidget]);

  const toggleWeather = () => {
    setWeatherWidget(previousState => !previousState);
  };

  const toggleNews = () => {
    setNewsWidget(previousState => !previousState);
  };

  const toggleTodo = () => {
    setTodoWidget(previousState => !previousState);
  };

  const toggleBirthday = () => {
    setBirthdayWidget(previousState => !previousState);
  }

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <Text style={{ color: colors.text, marginBottom: 15 }}>{t('choose which widgets do you want to see in your home page.')}</Text>
        <SettingSwitch text={t('weather')} isEnabled={weatherWidget} onChange={toggleWeather} />
        <SettingSwitch text={t('news')} isEnabled={newsWidget} onChange={toggleNews} />
        <SettingSwitch text={t('todo')} isEnabled={todoWidget} onChange={toggleTodo} />
        <SettingSwitch text={t('birthdays')} isEnabled={birthdayWidget} onChange={toggleBirthday} />
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
