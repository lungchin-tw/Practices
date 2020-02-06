

import GrayColorShader from '../shaders/GrayColorShader';

let ShaderFactory = {
    _shaders: {},
    _initialized: false,

    init: function () {
        if ( this._initialized == true ) {
            return;
        }

        this._registerShader( GrayColorShader );
        this._initialized = true;
    },

    shaderExists: function( name ) {
        return ( this._shaders[name] != null );
    },

    _registerShader: function( shader ) {
        if (this._shaders[shader.name]) {
            console.error("_registerShader - shader already registered. ", shader.name);
            return;
        }

        if (cc.renderer._forward) {
            cc.renderer._forward._programLib.define(shader.name, shader.vs, shader.fs, []);
        } else {
            cc.game.once(cc.game.EVENT_ENGINE_INITED, function () {
                cc.renderer._forward._programLib.define(shader.name, shader.vs, shader.fs, []);
            });
        }

        this._shaders[shader.name] = shader;
    },
}

export default ShaderFactory;