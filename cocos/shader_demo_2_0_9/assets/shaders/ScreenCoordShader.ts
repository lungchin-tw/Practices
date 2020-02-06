let shader = {
    name: "ScreenCoord",

    vs: `
    uniform mat4 viewProj;
    attribute vec3 a_position;

    attribute vec2 a_uv0;
    varying vec2 uv0;
    
    const float tail_head = 0.625;
    const float tail_len = 0.25;
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
}

export default shader;