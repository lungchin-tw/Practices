'use strict';

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
        let i18n = window.require('LanguageData');
        i18n.updateSceneRenderers();
    }
  }
});