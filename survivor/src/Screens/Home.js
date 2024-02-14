import React, { useContext, useState } from 'react';
import { StyleSheet, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import WeatherComponent from '../Components/Weather';
import Newsletter from '../Components/Newsletter';
import Todolist from '../Components/Todolist';

import { WeatherWidget, NewsWidget, TodoWidget } from '../WidgetContexts';

export default function HomeScreen({ navigation }) {
  const { weatherWidget, setWeatherWidget } = useContext(WeatherWidget);
  const { newsWidget, setNewsWidget } = useContext(NewsWidget);
  const { todoWidget, setTodoWidget } = useContext(TodoWidget);

  const renderWeather = () => {
    if (weatherWidget) {
      return (<WeatherComponent />);
    }
    return null;
  };

  const renderNews = () => {
    if (newsWidget) {
      return (<Newsletter />);
    }
    return null;
  };

  const renderTodo = () => {
    if (todoWidget) {
      return (<Todolist />);
    }
    return null;
  };

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <ScrollView>
          <View style={{ marginVertical: 10 }} />
          {renderWeather()}
          <View style={{ marginVertical: 10 }} />
          {renderNews()}
          <View style={{ marginVertical: 10 }} />
          {renderTodo()}
          <View style={{ marginVertical: 10 }} />
        </ScrollView>
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
