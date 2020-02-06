let shader = {
    name: "Payline",

    vs: `
    uniform mat4 viewProj;
    attribute vec3 a_position;

    attribute vec2 a_uv0;
    varying vec2 uv0;

    uniform float payline_uv;
    uniform float payline_start;
    uniform float payline_len;
    uniform float move_dist;

    void main () {
        vec4 pos = viewProj * vec4(a_position, 1);
        gl_Position = pos;
        uv0 = a_uv0;
        float cx = ( (pos.x / pos.z) + 1. ) * 0.5;
        float head = payline_start + move_dist;
        float tail = head - payline_len;
        uv0.x = ((cx - tail) * payline_uv) / payline_len;
    }`,

    fs: `
    uniform sampler2D texture;
    varying vec2 uv0;

    const float glow_range_unit = 0.002;
    const float glow_intensity = 5.0;
    const float num_glow_slices = 5.0;
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
}

export default shader;