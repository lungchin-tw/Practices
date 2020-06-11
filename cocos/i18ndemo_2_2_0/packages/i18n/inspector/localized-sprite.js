'use strict';

// require('LanguageData');

Vue.component('localized-sprite', {
  template: `
    <cc-array-prop :target.sync="target.spriteFrameSet"></cc-array-prop>
  `,

  props: {
    target: {
      twoWay: true,
      type: Object,
    },
  },

  methods: {
    refresh: function () {
        cc.log('window.i18n.curLang: ' + window.i18n.curLang);
        console.log('window.i18n.curLang: ' + window.i18n.curLang);
        let i18n = window.require('LanguageData');
        i18n.updateSceneRenderers();
    }
  }
});