import React, { useEffect, useState } from 'react';
import { StyleSheet, View, Text, TouchableOpacity, SafeAreaView, ScrollView, Image, Button } from 'react-native';
import Modal from 'react-native-modal';
import FeatherIcon from 'react-native-vector-icons/Feather';
import { useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';

import { getEmployee, getEmployeePP } from '../Requests';
import EmployeeFocusCard from './EmployeeFocusCard';

export default function EmployeeCard({ id, email, name, surname }) {
  const [profilePicture, setProfilePicture] = useState(null);

  const [isModalVisible, setModalVisible] = useState(false);
  const { colors } = useTheme();

  const fetchUserData = async () => {
    getEmployeePP(id).then((data) => {
      const fileReaderInstance = new FileReader();
      fileReaderInstance.readAsDataURL(data);
      fileReaderInstance.onload = () => {
        setProfilePicture(fileReaderInstance.result);
      }
    }).catch((error) => {
      console.error(error);
    });
  };

  const openModal = () => {
    fetchUserData();
    setModalVisible(true);
  };

  const closeModal = () => {
    setModalVisible(false);
  };

  useEffect(() => {
      fetchUserData();
  }, [])

  return (
    <View>
      <TouchableOpacity onPress={openModal}>
        <View style={styles.container}>
          <Image
            alt=""
            resizeMode="cover"
            source={profilePicture !== null ? { uri: profilePicture } : require('../../assets/Blank-profile.png')}
            style={styles.cardImg}
          />

          <View style={styles.cardBody}>
            <Text style={{ fontSize: 16, fontWeight: '700', color: colors.text }}>{name} {surname}</Text>
            <Text style={styles.cardDescription}>{email}</Text>
          </View>

          <View style={styles.cardAction}>
            <FeatherIcon
              color="#9ca3af"
              name="chevron-right"
              size={22}
            />
          </View>
        </View>
      </TouchableOpacity>

      <Modal isVisible={isModalVisible} style={{ margin: 0, padding: 0 }}>
        <EmployeeFocusCard
          id={id}
          email={email}
          name={name}
          surname={surname}
          onClose={closeModal}
        />
      </Modal>

    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    padding: 12,
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'flex-start',
  },
  cardImg: {
    width: 42,
    height: 42,
    borderRadius: 10,
  },
  cardAvatar: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#9ca1ac',
  },
  cardBody: {
    marginRight: 'auto',
    marginLeft: 12,
  },
  cardDescription: {
    fontSize: 15,
    lineHeight: 20,
    fontWeight: '500',
    color: '#616d79',
    marginTop: 3,
  },
  cardAction: {
    paddingRight: 16,
  },
});
