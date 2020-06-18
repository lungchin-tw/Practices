const SpriteFrameListSet = require('SpriteFrameListSet');

cc.Class({
    extends: cc.Component,

    editor: {
        executeInEditMode: true,
        inspector: 'packages://i18n/inspector/localized_sprite_list.js',
        menu: 'i18n/LocalizedSpriteList'
    },

    properties: {
        SpriteFrameListSet: {
            default: [],
            type: SpriteFrameListSet
        }
    },

    onLoad () {
        if (CC_EDITOR) {
            if (this.SpriteFrameListSet.length == 0) {
                for ( const value of window.DefaultLangList ) {
                    let set = new SpriteFrameListSet();
                    set.language = value;
                    this.SpriteFrameListSet.push(set);
                }
            }
        }

        this.fetchRender();
    },

    fetchRender () {
        // let sprite = this.getComponent(cc.Sprite);
        // if (sprite) {
        //     this.sprite = sprite;
        //     this.updateSprite(window.i18n.curLang);
        //     return;
        // }
    },

    getSpriteFrameListSetByLang (lang) {
        for (let i = 0; i < this.SpriteFrameListSet.length; ++i) {
            if (this.SpriteFrameListSet[i].language === lang) {
                return this.SpriteFrameListSet[i];
            }
        }
    },

    updateSprite (language) {
        // if (!this.sprite) {
        //     return;
        // }

        // let set = this.getSpriteFrameListSetByLang(language);
        // if (!set) {
        //     return;
        // }
    }
});