import React, { useContext, useState } from 'react';
import { StyleSheet, Text, View, ScrollView, SafeAreaView, RefreshControl, ActivityIndicator } from 'react-native';
import { Picker } from '@react-native-picker/picker';
import { SearchBar } from 'react-native-elements';
import { useTheme } from '@react-navigation/native';
import { t } from '../Translate';
import { trombiApi } from '../Requests';
import ProfileCard from '../Components/ProfileCard';
import EmployeeCard from '../Components/EmployeeCard';
import UserInfos from '../Contexts/UserInfoContext';

export default function TrombiScreen() {
  const { userInfos, setUserInfos } = useContext(UserInfos);
  const [me] = useState({});
  const [refreshing, setRefreshing] = useState(false);
  const [search, setSearch] = useState('');
  const { colors } = useTheme();
  const [jobFilter, setJobFilter] = useState('');

  const onRefresh = React.useCallback(() => {
    setRefreshing(true);

    const reloadStatus = async () => {
      const rsp = await trombiApi.getEmployees();
      const updatedUserInfos = userInfos.map((userInfo, index) => ({
        ...userInfo,
        status: rsp[index].status,
      }));
      setUserInfos(updatedUserInfos);
    };

    reloadStatus();

    setTimeout(() => {
      setRefreshing(false);
    }, 500);
  }, [userInfos]);

  const renderEmployees = () => {
    if (!userInfos)
      return null;
    return userInfos
      .filter((elem) => elem.name.toLowerCase().includes(search.toLowerCase()) || elem.surname.toLowerCase().includes(search.toLowerCase()))
      .filter((elem) => elem.work === jobFilter || jobFilter === '')
      .map((employee) => (<EmployeeCard key={employee.id} infos={employee} />));
  };

  const renderLeaders = () => {
    if (!userInfos)
      return null;
    return userInfos
      .filter((elem) => elem.work === "CEO" && (elem.name.toLowerCase().includes(search.toLowerCase()) || elem.surname.toLowerCase().includes(search.toLowerCase())))
      .filter((elem) => elem.work === jobFilter || jobFilter === '')
      .map((leader) => (<EmployeeCard key={leader.id} infos={leader} />));
  };

  const jobOptions = [
    'CEO',
    'VP of Marketing',
    'Marketing Manager',
    'Finance Manager',
    'Financial Analyst',
    'HR Manager',
    'HR Coordinator',
  ];

  const Displaypills = () => {
    const { colors } = useTheme();
    return (
      <View>
        <View
          style={{
            backgroundColor: colors.card,
            borderColor: colors.border,
            borderWidth: 1,
            borderRadius: 5,
            marginBottom: 10,
          }}
        >
          <Picker
            selectedValue={jobFilter}
            onValueChange={(itemValue) => setJobFilter(itemValue)}
            style={{ color: colors.text }}
          >
            <Picker.Item label="Select a Job" value="" />
            {jobOptions.map((job, index) => (
              <Picker.Item
                key={index}
                label={job}
                value={job}
                style={{
                  color: jobFilter === job ? 'grey' : colors.text,
                }}
              />
            ))}
          </Picker>
        </View>
      </View>
    );
  }

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
        {userInfos === undefined && <ActivityIndicator size="large" style={styles.loading} /> ||
          <ScrollView style={{ paddingTop: 15 }} refreshControl={<RefreshControl refreshing={refreshing} onRefresh={onRefresh} />}>
            {Displaypills()}
            <Text style={{ fontSize: 20, fontWeight: 'bold', color: colors.text }}>{t('leaders')}</Text>
            {renderLeaders()}
            <Text style={{ fontSize: 20, fontWeight: 'bold', color: colors.text }}>{t('employees')}</Text>
            {renderEmployees()}
          </ScrollView>}
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
  horizontalScroll: {
    overflow: 'hidden',
    padding: 30,
    width: '90%',
    height: 10,
  },
  pills: {
    paddingHorizontal: 10,
    height: 20,
    borderRadius: 12,
    marginHorizontal: 4,
    marginBottom: 15,
    shadowColor: 'black',
    alignItems: 'center',
    justifyContent: 'center',
  },
  pillsText: {
    alignContent: 'center',
    textAlign: 'center',
    fontSize: 10,
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
  loading: {
    marginTop: 30,
  }
});
