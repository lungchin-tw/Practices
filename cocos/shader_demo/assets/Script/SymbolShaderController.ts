const {ccclass, property} = cc._decorator;

@ccclass
export default class SymbolShaderController extends cc.Component {
    
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
    Ambient: cc.Color = cc.Color.WHITE;
    
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
        let alpha = 0;
        let bound_alpha = this.Ambient.getA() / 255.0;
        if ( this._duration > this.Delay ) {
            alpha = (this._duration - this.Delay) * this.Speed;
            if ( alpha >= 1.0 ) {
                this._duration = 0;
            }

            if (alpha > bound_alpha) {
                alpha = bound_alpha;
            }
        }
        
        let ambient = new cc.Vec4( 
            (this.Ambient.getR() / 255.0),
            (this.Ambient.getG() / 255.0),
            (this.Ambient.getB() / 255.0),
            alpha
        );

        this._material.setProperty('ambient', ambient);
    }

    onDisable() {
        this._material = null;
    }
}
