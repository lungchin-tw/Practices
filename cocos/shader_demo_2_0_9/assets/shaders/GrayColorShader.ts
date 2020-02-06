let shader = {
    name: "GrayColor",

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
    varying vec2 uv0;
    
    void main() {
        vec4 o = texture2D(texture, uv0);
        float avg = (o.r + o.g + o.b) * 0.33333;
        gl_FragColor = vec4(avg, avg, avg, o.a);
    }`,
}

export default shader;