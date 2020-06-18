const SpriteFrameListSet = require('SpriteFrameListSet');

cc.Class({
    extends: cc.Component,

    editor: {
        executeInEditMode: true,
        menu: 'i18n/LocalizedSpriteList'
    },

    properties: {
        SpriteIndex:{
            get () {
                return this._spriteIndex;
            },

            set (value) {
                this._spriteIndex = value;
                this.fetchRender();
            }
        },

        _spriteIndex: -1,

        SpriteFrameListSet: {
            default: [],
            type: SpriteFrameListSet
        },
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
        let sprite = this.getComponent(cc.Sprite);
        if (sprite) {
            this.updateSprite(sprite, this.SpriteIndex);
        }
    },

    getSpriteFrameListSetByLang (lang) {
        for (let i = 0; i < this.SpriteFrameListSet.length; ++i) {
            if (this.SpriteFrameListSet[i].language === lang) {
                return this.SpriteFrameListSet[i];
            }
        }
    },

    updateSprite (sprite, index) {
        if (!sprite) {
            return;
        }

        let set = this.getSpriteFrameListSetByLang(window.i18n.curLang);
        if (!set) {
            return;
        }

        sprite.spriteFrame = set.getSpriteFrameByIndex(index);
    }
});