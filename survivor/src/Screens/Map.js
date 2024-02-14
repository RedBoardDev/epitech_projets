import React, { useEffect, useState } from 'react';
import { StyleSheet, Text, View, Button, ScrollView, FlatList, Switch, TouchableOpacity, DevSettings, SafeAreaView, Image, RefreshControl, AsyncStorage } from 'react-native';
import Modal from 'react-native-modal';
import { useTheme, DefaultTheme, DarkTheme } from '@react-navigation/native';
import { Ionicons } from '@expo/vector-icons';
import { t } from '../Translate';
import MapView, { Marker } from 'react-native-maps';

export default function MapScreen({ navigation }) {
  const [region, setRegion] = useState({ latitude: 47.738426767733046, latitudeDelta: 0.009817227176291965, longitude: 7.32946103038522, longitudeDelta: 0.008446771174708267 });
  const [markers, setMarkers] = useState([
    { title: 'Epitech', description: 'Ecole informatique Mulhouse - Epitech', coordinate: { latitude: 47.73840679720672, longitude: 7.327713030425616, }, },
    { title: 'Le Quai', description: 'Résidence Etudiante Mulhouse - Le Quai', coordinate: { latitude: 47.73796525557793, longitude: 7.332261719217589, }, }
  ]);
  const { colors } = useTheme();

  useEffect(() => {
    console.log(region);
  }, [region]);

  const onLongPress = (e) => {
    setMarkers([
      ...markers,
      {
        title: 'New marker',
        description: '',
        coordinate: e.nativeEvent.coordinate,
      },
    ]);
  };

  const renderMarker = (marker, index) => (
    <Marker
      key={index}
      coordinate={marker.coordinate}
      title={marker.title}
      description={marker.description}
    />
  );


  return (
    <SafeAreaView style={{ flex: 1 }}>
      <View style={styles.container}>
        <MapView
          style={styles.map}
          region={region}
          onRegionChangeComplete={setRegion}
          showsUserLocation={true}
          onLongPress={onLongPress}
        >
          {markers.map(renderMarker)}
        </MapView>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flexGrow: 1,
    flexShrink: 1,
    flexBasis: 0,
  },
  map: {
    width: '100%',
    height: '100%',
  },
});
