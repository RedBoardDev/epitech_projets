import React, { useState } from 'react';
import { StyleSheet, Text, View, SafeAreaView, Platform, Linking } from 'react-native';
import { useTheme } from '@react-navigation/native';
import { Ionicons } from '@expo/vector-icons';
import MapView, { Marker, Callout } from 'react-native-maps';

export default function MapScreen() {
  const [region, setRegion] = useState({ latitude: 47.738426767733046, latitudeDelta: 0.009817227176291965, longitude: 7.32946103038522, longitudeDelta: 0.008446771174708267 });
  const [markers, setMarkers] = useState([
    { title: 'Epitech', description: 'Ecole informatique Mulhouse - Epitech', coordinate: { latitude: 47.73840679720672, longitude: 7.327713030425616, }, },
    { title: 'Le Quai', description: 'Résidence Etudiante Mulhouse - Le Quai', coordinate: { latitude: 47.73796525557793, longitude: 7.332261719217589, }, }
  ]);
  const { colors } = useTheme();

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

  const openGPS = (marker) => {
    const link = Platform.select({
      ios: `maps://app?daddr=${marker.coordinate.latitude}+${marker.coordinate.longitude}`,
      android: `google.navigation:q=${marker.coordinate.latitude}+${marker.coordinate.longitude}`
    });
    Linking.openURL(link);
  };

  const renderMarker = (marker, index) => (
    <Marker
      key={index}
      coordinate={marker.coordinate}
      title={marker.title}
      description={marker.description}
      onCalloutPress={() => openGPS(marker)}
    >
      <Callout style={styles.callout}>
        <View>
          <Text style={{ color: 'black', fontWeight: 'bold' }}>{marker.title}</Text>
          <Text style={{ color: 'black' }}>{marker.description}</Text>
        </View>
        <Ionicons name={'navigate-outline'} size={20} color={colors.primary} style={styles.icon} />
      </Callout>
    </Marker>
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
          showsMyLocationButton={true}
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
  callout: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    marginTop: 16,
  },
  icon: {
    marginLeft: 16,
    marginRight: 4,
  },
});
