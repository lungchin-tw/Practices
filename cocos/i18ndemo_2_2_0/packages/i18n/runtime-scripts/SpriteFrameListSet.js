const SpriteFrameListSet = cc.Class({
    name: 'SpriteFrameListSet',
    properties: {
        language: '',
        SpriteFrameList:{
            default: [],
            type: cc.SpriteFrame
        } 
    },

    getSpriteFrameByIndex( index ) {
        if ((index < 0) || (index >= this.SpriteFrameList.length)) {
            return null;
        }

        return this.SpriteFrameList[index];
    }
});

module.exports = SpriteFrameListSet;