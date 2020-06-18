const SpriteFrameSet = require('SpriteFrameSet');

cc.Class({
    extends: cc.Component,

    editor: {
        executeInEditMode: true,
        inspector: 'packages://i18n/inspector/localized-sprite.js',
        menu: 'i18n/LocalizedSprite'
    },

    properties: {
        spriteFrameSet: {
            default: [],
            type: SpriteFrameSet
        }
    },

    onLoad () {
        if (CC_EDITOR) {
            if (this.spriteFrameSet.length == 0) {
                for ( const value of window.DefaultLangList ) {
                    let set = new SpriteFrameSet();
                    set.language = value;
                    this.spriteFrameSet.push(set);
                }
            }
        }

        this.fetchRender();
    },

    fetchRender () {
        let sprite = this.getComponent(cc.Sprite);
        if (sprite) {
            this.sprite = sprite;
            this.updateSprite(window.i18n.curLang);
            return;
        }
    },

    getSpriteFrameByLang (lang) {
        for (let i = 0; i < this.spriteFrameSet.length; ++i) {
            if (this.spriteFrameSet[i].language === lang) {
                return this.spriteFrameSet[i].spriteFrame;
            }
        }
    },

    updateSprite (language) {
        if (!this.sprite) {
            this.fetchRender();
            if (!this.sprite){
                cc.error('Failed to update localized sprite, sprite component is invalid!');
                return;
            }
        }

        let spriteFrame = this.getSpriteFrameByLang(language);

        if (!spriteFrame && this.spriteFrameSet[0]) {
            spriteFrame = this.spriteFrameSet[0].spriteFrame;
        }

        this.sprite.spriteFrame = spriteFrame;
    }
});