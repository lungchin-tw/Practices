'use strict';

Vue.component('localized-spine', {
  template: `
    <cc-array-prop :target.sync="target.SpineSet"></cc-array-prop>
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