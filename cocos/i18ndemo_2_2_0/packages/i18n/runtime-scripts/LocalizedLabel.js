const LabelSet = require('LabelSet');

cc.Class({
    extends: cc.Component,

    editor: {
        executeInEditMode: true,
        inspector: 'packages://i18n/inspector/localized_label.js',
        menu: 'i18n/LocalizedLabel'
    },

    properties: {
        LabelSet: {
            default: [],
            type: LabelSet
        }
    },

    onLoad () {
        if (CC_EDITOR) {
            if (this.LabelSet.length == 0) {
                for ( const value of window.DefaultLangList ) {
                    let set = new LabelSet();
                    set.language = value;
                    this.LabelSet.push(set);
                }
            }
        }

        this.fetchRender();
    },

    fetchRender () {
        let label = this.getComponent(cc.Label);
        if (label) {
            this.label = label;
            this.updateByLang(window.i18n.curLang);
            return;
        }
    },

    getLabelSetByLang (lang) {
        for ( const value of this.LabelSet) {
            if (value.language === lang) {
                return value;
            }
        }
    },

    updateByLang (language) {
        if (!this.label) {
            // cc.error('Failed to update localized sprite, sprite component is invalid!');
            return;
        }

        let labelset = this.getLabelSetByLang(language);
        if (!labelset) {
            return;
        }

        this.label.font = labelset.font;
        this.label.string = labelset.string;
    }
});