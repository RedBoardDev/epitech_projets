import React, { useContext } from 'react';
import { StyleSheet, View, SafeAreaView } from 'react-native';
import { KeyboardAwareScrollView } from 'react-native-keyboard-aware-scroll-view';
import WeatherComponent from '../Components/Weather';
import Newsletter from '../Components/Newsletter';
import Todolist from '../Components/Todolist';
import AnniversaryComponent from '../Components/Anniversery';

import { WeatherWidget, NewsWidget, TodoWidget, BirthdayContext } from '../Contexts/WidgetContexts';
import HomeProfile from '../Components/HomeProfile';

export default function HomeScreen() {
  const { weatherWidget } = useContext(WeatherWidget);
  const { newsWidget } = useContext(NewsWidget);
  const { todoWidget } = useContext(TodoWidget);
  const { birthdayWidget } = useContext(BirthdayContext);

  const renderProfile = () => {
    return (<View style={{ marginVertical: 10 }}><HomeProfile /></View>);
  }

  const renderWeather = () => {
    if (weatherWidget) {
      return (<View style={{ marginVertical: 10 }}><WeatherComponent /></View>);
    }
    return null;
  };

  const renderNews = () => {
    if (newsWidget) {
      return (<View style={{ marginVertical: 10 }}><Newsletter /></View>);
    }
    return null;
  };

  const renderTodo = () => {
    if (todoWidget) {
      return (<View style={{ marginVertical: 10 }}><Todolist /></View>);
    }
    return null;
  };

  const renderAnniv = () => {
    if (birthdayWidget) {
      return (<View style={{ marginVertical: 10 }}><AnniversaryComponent /></View>);
    }
    return null;
  };

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <KeyboardAwareScrollView keyboardShouldPersistTaps='handled'>
          {renderProfile()}
          {renderWeather()}
          {renderNews()}
          {renderTodo()}
          {renderAnniv()}
        </KeyboardAwareScrollView>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    paddingHorizontal: 20,
    flexGrow: 1,
    flexShrink: 1,
    flexBasis: 0,
  }
});
