const {ccclass, property} = cc._decorator;

@ccclass
export default class PaylineShaderController extends cc.Component {
    
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
    Loop = true;

    @property
    Delay = 2;
    
    @property
    Speed = 0.5;

    @property
    TailLen = 0.5;
    
    _material: cc.Material = null;
    _duration = 0;

    onEnable() {
        if (this.component) {
            this._material = this.component.sharedMaterials[0];
        }

        this._duration = 0;
    }

    update(dt) {
        if (this._material) {
            this.move(dt);
        }
    }

    move(dt) {
        this._duration += dt;
        let dist = 0;
        if ( this._duration > this.Delay ) {
            dist = (this._duration - this.Delay) * this.Speed;
        }

        if ( dist > 1 + this.TailLen ) {
            this._duration = 0;
        }

        this._material.setProperty('dist', dist);
    }

    onDisable() {
        this._material = null;
    }
}
