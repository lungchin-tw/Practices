let shader = {
    name: "AmbientColor",

    vs: `
    uniform mat4 viewProj;
    attribute vec3 a_position;
    attribute vec2 a_uv0;
    varying vec2 uv0;
    void main () {
        vec4 pos = viewProj * vec4(a_position, 1);
        gl_Position = pos;
        uv0 = a_uv0;
    }`,

    fs: `
    uniform sampler2D texture;
    uniform vec4 ambient;
    uniform float strength;
    varying vec2 uv0;
    void main() {
        vec4 o = texture2D(texture, uv0);
        vec3 final_rgb = (o.rgb * (1.0 - strength))  + (ambient.rgb * strength);
        o.rgb = final_rgb;
        gl_FragColor = o;
    }`,
}

export default shader;