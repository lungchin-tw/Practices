const {ccclass, property} = cc._decorator;

@ccclass
export default class SpriteShaderUpdate extends cc.Component {
    
    @property
    _component = null;
    
    @property({
        type: cc.RenderComponent
    })
    get component () {
        return this._component;
    }

    set component (comp) {
        this._component = comp;
        if (this._component) {
            this._material = this._component.sharedMaterials[0];
        }
    }

    @property
    OffsetX = 0;

    @property
    ExtendX = 0;

    @property
    SpeedX = 10;

    _material: cc.Material = null;
    _posx = 0;

    onEnable() {
        if (this.component) {
            this._material = this.component.sharedMaterials[0];
        }

        this._posx = 0;
    }

    update(dt) {
        if (this._material) {
            this.move(dt);
        }
    }

    move(dt) {
        this._posx += (dt * this.SpeedX);
        
        let cur = (this._posx + this.OffsetX)
        let bound = (1 + this.ExtendX)
        if ( cur > bound ) {
            this._posx = 0;
        }
        this._material.setProperty('posx', cur);
    }

    onDisable() {
        this._material = null;
    }
}
