import React, { useEffect, useState } from 'react';
import { StyleSheet } from 'react-native';
import { useTheme } from '@react-navigation/native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { Ionicons } from '@expo/vector-icons';

import HomeStackScreen from './Tabs/Home';
import TrombiStackScreen from './Tabs/Trombi';
import MapStackScreen from './Tabs/Map';
import ChatStackScreen from './Tabs/Chat';
import SettingsStackScreen from './Tabs/Settings';
import { trombiApi } from './Requests';
import UserInfos from './Contexts/UserInfoContext';
import { NewsWidget, TodoWidget, WeatherWidget, BirthdayContext } from './Contexts/WidgetContexts';
import { t } from './Translate';

export default function NavBar() {
  const [userInfos, setUserInfos] = useState(undefined);
  const Tab = createBottomTabNavigator();
  const [weatherWidget, setWeatherWidget] = useState(true);
  const [newsWidget, setNewsWidget] = useState(true);
  const [todoWidget, setTodoWidget] = useState(true);
  const [birthdayWidget, setBirthdayWidget] = useState(true);
  const { colors } = useTheme();

  useEffect(() => {
    AsyncStorage.getItem('userProfil').then((value) => {
      trombiApi.setStatusEmployees(JSON.parse(value).id, 1);
      setTimeout(async () => {
        trombiApi.setStatusEmployees(JSON.parse(value).id, 1);
      }, 60000);
    });
  }, [userInfos]);

  async function fetchUserData() {
    const employees = await trombiApi.getEmployees();
    setUserInfos(employees);
  }

  useEffect(() => {
    fetchUserData();
    AsyncStorage.getItem('weather').then((value) => {
      if (value) {
        setWeatherWidget(value === 'true');
      } else {
        setWeatherWidget(true);
        AsyncStorage.setItem('weather', 'true');
      }
    });
    AsyncStorage.getItem('news').then((value) => {
      if (value) {
        setNewsWidget(value === 'true');
      } else {
        setNewsWidget(true);
        AsyncStorage.setItem('news', 'true');
      }
    });
    AsyncStorage.getItem('todo').then((value) => {
      if (value) {
        setTodoWidget(value === 'true');
      } else {
        setTodoWidget(true);
        AsyncStorage.setItem('todo', 'true');
      }
    });
    AsyncStorage.getItem('birthday').then((value) => {
      if (value) {
        setBirthdayWidget(value === 'true');
      } else {
        setBirthdayWidget(true);
        AsyncStorage.setItem('birthday', 'true');
      }
    });
  }, []);

  return (
    <UserInfos.Provider value={{ userInfos, setUserInfos }}>
      <NewsWidget.Provider value={{ newsWidget, setNewsWidget }}>
        <TodoWidget.Provider value={{ todoWidget, setTodoWidget }}>
          <WeatherWidget.Provider value={{ weatherWidget, setWeatherWidget }}>
            <BirthdayContext.Provider value={{ birthdayWidget, setBirthdayWidget }}>
              <Tab.Navigator screenOptions={({ route }) => ({
                tabBarActiveTintColor: colors.primary,
                tabBarInactiveTintColor: colors.text,
              })}>
                <Tab.Screen
                  name="HomeTab"
                  component={HomeStackScreen}
                  options={{
                    title: t('home'),
                    headerShown: false,
                    tabBarLabel:() => {return null},
                    tabBarIcon: ({ focused, color, size }) => (
                      <Ionicons name={focused ? 'home' : 'home-outline'} size={size} color={color} style={styles.tabBarIcon} />
                    ),
                  }}
                />
                <Tab.Screen
                  name="TrombiTab"
                  component={TrombiStackScreen}
                  options={{
                    title: t('trombi'),
                    headerShown: false,
                    tabBarLabel:() => {return null},
                    tabBarIcon: ({ focused, color, size }) => (
                      <Ionicons name={focused ? 'person' : 'person-outline'} size={size} color={color} style={styles.tabBarIcon} />
                    ),
                  }}
                />
                <Tab.Screen
                  name="MapTab"
                  component={MapStackScreen}
                  options={{
                    title: t('map'),
                    headerShown: false,
                    tabBarLabel:() => {return null},
                    tabBarIcon: ({ focused, color, size }) => (
                      <Ionicons name={focused ? 'map' : 'map-outline'} size={size} color={color} style={styles.tabBarIcon} />
                    ),
                  }}
                />
                <Tab.Screen
                  name="Chat"
                  component={ChatStackScreen}
                  options={{
                    title: t('chat'),
                    headerShown: false,
                    tabBarLabel:() => {return null},
                    tabBarIcon: ({ focused, color, size }) => (
                      <Ionicons name={focused ? 'chatbubbles' : 'chatbubbles-outline'} size={size} color={color} style={styles.tabBarIcon} />
                    ),
                  }}
                />
                <Tab.Screen
                  name="SettingsTab"
                  component={SettingsStackScreen}
                  options={{
                    title: t('settings'),
                    headerShown: false,
                    tabBarLabel:() => {return null},
                    tabBarIcon: ({ focused, color, size }) => (
                      <Ionicons name={focused ? 'settings' : 'settings-outline'} size={size} color={color} style={styles.tabBarIcon} />
                    ),
                  }}
                />
              </Tab.Navigator>
            </BirthdayContext.Provider>
          </WeatherWidget.Provider>
        </TodoWidget.Provider>
      </NewsWidget.Provider>
    </UserInfos.Provider>
  );
}

const styles = StyleSheet.create({
  tabBarIcon: {
    fontSize: 25,
  },
});
