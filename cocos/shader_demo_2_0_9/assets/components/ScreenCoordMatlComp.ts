// Learn TypeScript:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/typescript.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/typescript.html
// Learn Attribute:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/reference/attributes.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - [Chinese] https://docs.cocos.com/creator/manual/zh/scripting/life-cycle-callbacks.html
//  - [English] http://www.cocos2d-x.org/docs/creator/manual/en/scripting/life-cycle-callbacks.html

const {ccclass, property} = cc._decorator;

import ScreenCoordMatl from '../materials/ScreenCoordMatl';

@ccclass
export default class ScreenCoordMatlComp extends cc.Component {

    @property(cc.Sprite)
    sprite: cc.Sprite = null;
    

    start () {
        if ( this.sprite == null ) {
            return;
        } else if ( this.sprite.spriteFrame == null ) {
            return;
        } else if (cc.game.renderType === cc.game.RENDER_TYPE_CANVAS) {
            return;
        }

        let mat = new ScreenCoordMatl();
        let sf = this.sprite.spriteFrame;
        if ( sf.textureLoaded() ) {
            if ( mat.texture !== sf.getTexture() ) {
                mat.texture = sf.getTexture();
                this.sprite._updateMaterial(mat);
            } else if ( mat !== this.sprite._material ) {
                this.sprite._updateMaterial(mat);
            }

            if (this.sprite._renderData) {
                this.sprite._renderData.material = mat;
            }

            // 1 << 4 等价于 cc.RenderFlow.FLAG_COLOR 可解决ts强迫症小红点 
            this.sprite.node._renderFlag |= cc.RenderFlow.FLAG_COLOR

            this.sprite.markForUpdateRenderData(true);
            this.sprite.markForRender(true);
        }
        else {
            this.sprite.disableRender();
        }
    }
}
