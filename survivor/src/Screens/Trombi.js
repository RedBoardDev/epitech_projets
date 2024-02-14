import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import Modal from 'react-native-modal';
import { SearchBar } from 'react-native-elements';
import { useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';
import { login, getMe, getEmployee, getEmployeePP, getEmployees, getLeaders, makeRequest } from '../Requests';
import ProfileCard from '../Components/ProfileCard';
import EmployeeCard from '../Components/EmployeeCard';

export default function TrombiScreen({ navigation }) {
  const [employees, setEmployees] = useState([]);
  const [leaders, setLeaders] = useState([]);
  const [me, setMe] = useState({});
  const [refreshing, setRefreshing] = React.useState(false);
  const [search, setSearch] = useState('');
  const { colors } = useTheme();

  const onRefresh = React.useCallback(() => {
    setRefreshing(true);
    fetchData();
    setTimeout(() => {
      setRefreshing(false);
    }, 100);
  }, []);

  useEffect(() => {
    fetchData();
  }, []);

  const fetchData = () => {
    getEmployees().then((data) => {
      data.sort((a, b) => { const aname = a.name + ' ' + a.surname; const bname = b.name + ' ' + b.surname; if (aname < bname) return -1; if (aname > bname) return 1; return 0; });
      setEmployees(data);
    }).catch((error) => {
      console.error(error);
    });
    getLeaders().then((data) => {
      data.sort((a, b) => { const aname = a.name + ' ' + a.surname; const bname = b.name + ' ' + b.surname; if (aname < bname) return -1; if (aname > bname) return 1; return 0; });
      setLeaders(data);
    }).catch((error) => {
      console.error(error);
    });
    getMe().then((data) => {
      setMe(data);
    }).catch((error) => {
      console.error(error);
    });
  };

  const renderEmployees = () => {
    return employees.filter((elem) => {
      return elem.name.toLowerCase().includes(search.toLowerCase()) || elem.surname.toLowerCase().includes(search.toLowerCase());
    }).map((employee) => (
      <EmployeeCard key={employee.id} id={employee.id} email={employee.email} name={employee.name} surname={employee.surname} />
    ));
  };

  const renderLeaders = () => {
    return leaders.filter((elem) => {
      return elem.name.toLowerCase().includes(search.toLowerCase()) || elem.surname.toLowerCase().includes(search.toLowerCase());
    }).map((leader) => (
      <EmployeeCard key={leader.id} id={leader.id} email={leader.email} name={leader.name} surname={leader.surname} />
    ));
  };

  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <SearchBar
          containerStyle={{ backgroundColor: 'transparent', borderBottomColor: 'transparent', borderTopColor: 'transparent', }}
          inputContainerStyle={{ borderRadius: 10, height: 30, backgroundColor: colors.card }}
          inputStyle={{ color: colors.text }}
          platform='ios'
          placeholder={t('search') + '...'}
          onChangeText={setSearch}
          value={search}
        />
        <ProfileCard id={me.id} name={me.name} surname={me.surname} email={me.email} />
        <ScrollView style={{ paddingTop: 15 }} refreshControl={<RefreshControl refreshing={refreshing} onRefresh={onRefresh} />}>
          <Text style={{ fontSize: 20, fontWeight: 'bold', color: colors.text }}>{t('leaders')}</Text>
          {renderLeaders()}
          <Text style={{ fontSize: 20, fontWeight: 'bold', color: colors.text }}>{t('employees')}</Text>
          {renderEmployees()}
        </ScrollView>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 15,
    paddingHorizontal: 20,
    flexGrow: 1,
    flexShrink: 1,
    flexBasis: 0,
  },
  popup: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  popupText: {
    fontSize: 15,
    color: 'white',
  },
});
