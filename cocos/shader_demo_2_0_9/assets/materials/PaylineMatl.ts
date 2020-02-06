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

import ShaderFactory from '../factory/ShaderFactory';

@ccclass
export default class PaylineMatl extends Material {

    _effect = null;
	_mainTech = null;
    _texture = null;
    
    constructor( payline_uv, payline_start, payline_len ) {
        super(true);

        ShaderFactory.init();
        let shader_name = "Payline";
        if ( ShaderFactory.shaderExists(shader_name) == false ) {
            console.error( "Shader Not Exist:", shader_name );
            return;
        }

        /**
         * Build Pass
         */
        let pass = new renderer.Pass(shader_name);
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
		this._mainTech = new renderer.Technique( 
            ['transparent'], 
            [
                { name: 'texture', type: renderer.PARAM_TEXTURE_2D },
                { name: 'payline_uv', type: renderer.PARAM_FLOAT },
                { name: 'payline_start', type: renderer.PARAM_FLOAT },
                { name: 'payline_len', type: renderer.PARAM_FLOAT },
                { name: 'move_dist', type: renderer.PARAM_FLOAT },
            ], 
            [ pass ] 
        );

        // Effect
		this._effect = new renderer.Effect(	
            [this._mainTech],
            {
                'payline_uv': payline_uv,
                'payline_start': payline_start,
                'payline_len': payline_len,
            },
            []
        );

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
