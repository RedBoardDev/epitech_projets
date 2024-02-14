import en from '../Translations/en.json';
import fr from '../Translations/fr.json';

let language = 'en';

const languages = {
  en: en,
  fr: fr,
};

export function t(key) {
  return languages[language][key];
}

export function changeLanguage(newLanguage) {
  language = newLanguage;
}
