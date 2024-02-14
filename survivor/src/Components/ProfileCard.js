import React, { useEffect, useState } from 'react';
import { Text, View, TouchableOpacity, StyleSheet, Image, Button } from 'react-native';
import Modal from 'react-native-modal';
import { useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';

import { getMe, getEmployee, getEmployeePP } from '../Requests';
import EmployeeFocusCard from './EmployeeFocusCard';

export default function ProfileCard({ }) {
  const [id, setId] = useState('');
  const [name, setName] = useState('');
  const [surname, setSurname] = useState('');
  const [email, setEmail] = useState('');
  const [birthDate, setBirthDate] = useState('');
  const [gender, setGender] = useState('');
  const [work, setWork] = useState('');
  const [subordinates, setSubordinates] = useState([]);
  const [profilePicture, setProfilePicture] = useState(null);

  const [isModalVisible, setModalVisible] = useState(false);
  const { colors } = useTheme();

  useEffect(() => {
    fetchUserData();
  }, []);

  useEffect(() => {
    if (id === '')
      return;
    getEmployeePP(id).then((data) => {
      const fileReaderInstance = new FileReader();
      fileReaderInstance.readAsDataURL(data);
      fileReaderInstance.onload = () => {
        setProfilePicture(fileReaderInstance.result);
      }
    }).catch((error) => {
      console.error(error);
    });
  }, [id]);

  const fetchUserData = async () => {
    if (birthDate !== '')
      return;
    getMe().then((data) => {
      setId(data.id);
      setName(data.name);
      setSurname(data.surname);
      setEmail(data.email);
      setBirthDate(data.birth_date);
      setGender(data.gender);
      setWork(data.work);
      setSubordinates(data.subordinates);
    }).catch((error) => {
      console.error(error);
    });
  };

  const openModal = () => {
    setModalVisible(true);
  };

  const closeModal = () => {
    setModalVisible(false);
  };

  return (
    <View>
      <TouchableOpacity onPress={openModal}>
        <View style={[styles.container, { backgroundColor: colors.card }]}>
          <Image alt="" source={profilePicture !== null ? { uri: profilePicture } : require('../../assets/Blank-profile.png')} style={styles.avatar} />

          <View style={styles.profileBody}>
            <Text style={{ fontSize: 18, fontWeight: '600', color: colors.text }}>{name} {surname}</Text>
            <Text style={styles.description}>{email}</Text>
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
    marginTop: 12,
    borderRadius: 12,
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'flex-start',
  },
  avatar: {
    width: 60,
    height: 60,
    borderRadius: 9999,
    marginRight: 12,
  },
  description: {
    marginTop: 2,
    fontSize: 16,
    fontWeight: '400',
    color: '#858585',
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
  popupImg: {
    width: 200,
    height: 200,
    borderRadius: 9999,
  }
});
