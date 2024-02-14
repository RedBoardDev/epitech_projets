import React from 'react';

import {
  Image,
} from 'react-native';

const ICONS = {
  'home.png': require('../../assets/icons/home.png'),
  'home-outline.png': require('../../assets/icons/home-outline.png'),
  'robot.png': require('../../assets/icons/robot.png'),
  'robot-outline.png': require('../../assets/icons/robot-outline.png'),
  'settings.png': require('../../assets/icons/settings.png'),
  'settings-outline.png': require('../../assets/icons/settings-outline.png'),
  'list.png': require('../../assets/icons/list.png'),
};

export default function Icon({ name, size, color = 'black', style = {} }) {
  const source = ICONS[name];

  return (
    <Image source={source} style={[style, { width: size, height: size }]} tintColor={color} />
  );
}
