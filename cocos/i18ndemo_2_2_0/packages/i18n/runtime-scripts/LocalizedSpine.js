const SpineSet = require('SpineSet');


cc.Class({
    extends: cc.Component,

    editor: {
        executeInEditMode: true,
        inspector: 'packages://i18n/inspector/localized-spine.js',
        menu: 'i18n/LocalizedSpine'
    },

    properties: {
        SpineSet: {
            default: [],
            type: SpineSet,
        }
    },

    onLoad () {
        this.fetchRender();
    },

    fetchRender () {
        let skeleton = this.getComponent(sp.Skeleton);
        if (skeleton) {
            this.skeleton = skeleton;
            this.updateByLang(window.i18n.curLang);
            return;
        }
    },

    updateByLang (language) {
        if (!this.skeleton) {
            this.fetchRender();
            if (!this.skeleton){
                cc.error('Failed to update localized skeleton, skeleton component is invalid!');
                return;
            }
        }

        let spineset = this.getSpineSetByLang(language);
        if (!spineset) {
            return;
        }
    }, 

    getSpineSetByLang (lang) {
        for (let i = 0; i < this.SpineSet.length; ++i) {
            if (this.SpineSet[i].language === lang) {
                return this.SpineSet[i];
            }
        }
    }
});