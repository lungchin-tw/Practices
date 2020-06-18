const SpriteFrameListSet = cc.Class({
    name: 'SpriteFrameListSet',
    properties: {
        language: '',
        SpriteFrameList:{
            default: [],
            type: cc.SpriteFrame
        } 
    }
});

module.exports = SpriteFrameListSet;