const ButtonSet = cc.Class({
    name: 'ButtonSet',
    properties: {
        language: '',
        normal: cc.SpriteFrame,
        pressed: cc.SpriteFrame,
        hover: cc.SpriteFrame,
        disabled: cc.SpriteFrame,
    }
});

module.exports = ButtonSet;