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

const renderEngine = cc.renderer.renderEngine;
const renderer = renderEngine.renderer;
const gfx = renderEngine.gfx;
const Material = renderEngine.Material;

@ccclass
export default class ScreenCoordMatl extends Material {

    _effect = null;
	_mainTech = null;
    _texture = null;
    
    constructor() {
        super(true);

        /**
         * Register Shader
         */
        let shader = {
            name: "ScreenCoord",

            vs: `
            uniform mat4 viewProj;
            attribute vec3 a_position;

            attribute vec2 a_uv0;
            varying vec2 uv0;

            const float tail_len = 0.25;
            const float tail_head = 0.625;
            const float tail_uv = 0.5;

            void main () {
                vec4 pos = viewProj * vec4(a_position, 1);
                gl_Position = pos;
                uv0 = a_uv0;
                float cx = ( (pos.x / pos.z) + 1. ) * 0.5;
                float tail_end = tail_head - tail_len;
                uv0.x = ((cx - tail_end) / tail_len) * tail_uv;
            }`,

            fs: `
            uniform sampler2D texture;
            varying vec2 uv0;
            void main() {
                gl_FragColor = texture2D(texture, uv0);
            }`,
        };

        if (cc.renderer._forward) {
            cc.renderer._forward._programLib.define(shader.name, shader.vs, shader.fs, []);
        } else {
            cc.game.once(cc.game.EVENT_ENGINE_INITED, function () {
                cc.renderer._forward._programLib.define(shader.name, shader.vs, shader.fs, []);
            });
        }

        /**
         * Build Pass
         */
        let pass = new renderer.Pass(shader.name);
		pass.setDepth(false, false);
		pass.setCullMode(gfx.CULL_NONE);
		pass.setBlend(
			gfx.BLEND_FUNC_ADD,
			gfx.BLEND_SRC_ALPHA, gfx.BLEND_ONE_MINUS_SRC_ALPHA,
			gfx.BLEND_FUNC_ADD,
			gfx.BLEND_SRC_ALPHA, gfx.BLEND_ONE_MINUS_SRC_ALPHA
		);

		// var Technique = function Technique(stages, parameters, passes, layer) 
		// 1.stages参数用来设置_stageIDs 引擎中都是transparent 具体意义不明待解答
		// 2.parameters sprite必带 textrue color
		// 3 pass 上面的标准来 单pass	
		// 4.lay无用
		this._mainTech = new renderer.Technique( ['transparent'], [{ name: 'texture', type: renderer.PARAM_TEXTURE_2D }], [ pass ] );

		// Effect
		this._effect = new renderer.Effect(	[this._mainTech], {}, [] );
		this._texture = null;
    }

    get effect() {
		return this._effect;
    }
    
    get texture() {
		return this._texture;
	}

	set texture(value) {
		if (this._texture !== value) {
			this._texture = value;
			this._effect.setProperty('texture', value.getImpl());
			this._texIds['texture'] = value.getId();
		}
	}
}
