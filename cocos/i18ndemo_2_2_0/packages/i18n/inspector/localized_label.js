'use strict';

Vue.component('localized-label', {
  template: `
    <cc-array-prop :target.sync="target.LabelSet"></cc-array-prop>
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
        console.log('[localized-label], window.i18n.curLang: ' + window.i18n.curLang);
        cc.log('[localized-label], window.i18n.curLang: ' + window.i18n.curLang);
        window.LanguageData.updateSceneRenderers();
    }
  }
});