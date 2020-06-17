'use strict';

Vue.component('localized-button', {
  template: `
    <cc-array-prop :target.sync="target.ButtonSet"></cc-array-prop>
    <ui-prop name="Update Scene">
        <ui-button class="green tiny" @confirm="refresh">Refresh</ui-button>
    </ui-prop>
  `,

  props: {
    target: {
      twoWay: true,
      type: Object,
    },
  },

  methods: {
    refresh: function () {
      console.log('[localized-sprite], window.i18n.curLang: ' + window.i18n.curLang);
      cc.log('[localized-sprite], window.i18n.curLang: ' + window.i18n.curLang);
      window.languagedata.updateSceneRenderers();
    }
  }
});