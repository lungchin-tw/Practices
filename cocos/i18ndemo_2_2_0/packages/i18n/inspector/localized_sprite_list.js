'use strict';

Vue.component('localized-sprite-list', {
  template: `
    <cc-array-prop :target.sync="target.SpriteFrameListSet"></cc-array-prop>
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
        console.log('[localized-sprite-list], window.i18n.curLang: ' + window.i18n.curLang);
        cc.log('[localized-sprite-list], window.i18n.curLang: ' + window.i18n.curLang);
        window.LanguageData.updateSceneRenderers();
    }
  }
});