import React, { useEffect, useState } from 'react';
import { StyleSheet, View, Text, TouchableOpacity, Image } from 'react-native';
import Modal from 'react-native-modal';
import FeatherIcon from 'react-native-vector-icons/Feather';
import { useTheme } from '@react-navigation/native';

import { trombiApi } from '../Requests';
import EmployeeFocusCard from './EmployeeFocusCard';

export default function EmployeeCard({ infos }) {
  const [profilePicture, setProfilePicture] = useState(null);

  const [isModalVisible, setModalVisible] = useState(false);
  const { colors } = useTheme();

  const fetchUserData = async () => {
    trombiApi.getEmployeePP(infos.id).then((data) => {
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
    setModalVisible(true);
  };

  const isBirthday = () => {
    const today = new Date();
    const birthday = new Date(infos.birth_date);
    if (birthday.getMonth() === today.getMonth() && birthday.getDate() === today.getDate()) return true;
    return false;
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
            <View style={styles.nameContainer}>
              <Text style={{ fontSize: 16, fontWeight: '700', color: colors.text }}>{infos.name} {infos.surname}</Text>
              <View style={infos.status == 1 ? styles.onlineIndicator : styles.offlineIndicator}/>
            </View>
            <Text style={styles.cardDescription}>{infos.email}</Text>
          </View>

          <View style={styles.cardAction}>
            {/* {isBirthday() && <FeatherIcon name="cake" size={24} color="black" />} */}
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
          infos={infos}
          pp={profilePicture}
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
  onlineIndicator: {
    display: 'flex',
    width: 10,
    height: 10,
    marginRight: 10,
    backgroundColor: '#0fcc45',
    borderRadius: 50,
    marginLeft: 5,
  },
  offlineIndicator: {
    display: 'flex',
    width: 10,
    height: 10,
    marginRight: 10,
    backgroundColor: '#e60909',
    borderRadius: 50,
    marginLeft: 5,
  },
  nameContainer: {
    flexDirection: 'row',
    alignItems: 'center',
  },
});
