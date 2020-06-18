window.DefaultLangList = ['zh', 'vi'];

const i18n = require('LanguageData');
i18n.init('vi');

window.LanguageData = i18n;

cc.log('[globallang.js], window.i18n.curLang: ' + window.i18n.curLang);