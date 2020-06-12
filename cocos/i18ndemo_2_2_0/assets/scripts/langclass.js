const i18n = require('LanguageData');

cc.Class({
    extends: cc.Component,

    properties: {
        language: 'zh',
    },

    onLoad: function() {
        i18n.init(this.language);
    }
});