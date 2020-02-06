let shader = {
    name: "UVAnim",

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
    void main() {
        vec4 o = texture2D(texture, uv0);
        gl_FragColor = o;
    }`,
}

export default shader;