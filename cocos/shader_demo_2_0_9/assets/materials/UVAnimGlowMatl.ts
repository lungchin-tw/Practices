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
export default class UVAnimGlowMatl extends Material {

    _effect = null;
	_mainTech = null;
    _texture = null;
    
    constructor( start ) {
        super(true);
        
        /**
         * Register Shader
         */
        let shader = {
            name: "UVAnimGlow",

            vs: `
            uniform mat4 viewProj;
            attribute vec3 a_position;
            attribute vec2 a_uv0;
            varying vec2 uv0;

            uniform float su;
            
            void main () {
                vec4 pos = viewProj * vec4(a_position, 1);
                gl_Position = pos;
                uv0 = a_uv0;
                uv0.x += su;
            }`,

            fs: `
            uniform sampler2D texture;
            varying vec2 uv0;

            const float glow_range_unit = 0.001;
            const float glow_intensity = 5.0;
            const float num_glow_slices = 10.0;
            const float num_glow_ranges = 5.0;
            const float glow_alpha_threshold = 0.9;

            vec4 calc_glow_color( vec4 clr ) {
                vec4 final_clr = clr;
                if ( final_clr.a > glow_alpha_threshold ) {
                    return final_clr;
                }

                final_clr = vec4(0.,0.,0.,0.);
                float num_repeat = num_glow_ranges * num_glow_slices;
                float degree_slice = 360. / num_glow_slices;
                for ( float range = 0.; range < num_glow_ranges; range++ ) {
                    if ( range >= num_glow_ranges ) {
                        break;
                    }

                    float dist = (range * glow_range_unit);
                    for ( float slice = 0.; slice < num_glow_slices; slice++ ) {
                        if ( slice >= num_glow_slices ) {
                            break;
                        }

                        float rad = radians( slice * degree_slice );
                        vec2 offset = normalize(vec2( cos(rad), sin(rad) )) * dist;
                        final_clr += texture2D(texture, (uv0 + offset));
                    }
                }

                if ( final_clr.a > 0. ) {
                    final_clr.rgb *= ( glow_intensity / num_repeat );
                    final_clr.a /= num_repeat;
                    return final_clr;
                } else {
                    return final_clr;
                }
            }

            void main() {
                vec4 o = texture2D(texture, uv0);
                gl_FragColor = calc_glow_color(o);
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
		this._mainTech = new renderer.Technique( 
            ['transparent'], 
            [
                { name: 'texture', type: renderer.PARAM_TEXTURE_2D },
                { name: 'su', type: renderer.PARAM_FLOAT }
            ], 
            [ pass ] 
        );

		// Effect
		this._effect = new renderer.Effect(	[this._mainTech], { 'su': start }, [] );

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
