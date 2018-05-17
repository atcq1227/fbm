#version 150

const mat2 m = mat2( 0.80,  0.60, -0.60,  0.80 );

uniform sampler2DRect tex;
uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;
uniform vec3 fftIter;
uniform vec2 fftIter2;
uniform vec2 time;

vec2 p;
vec2 q;
vec2 r;

in vec2 vUv;

out vec4 fragColor;

float random (in vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*
                 43758.5453123);
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);
    
    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    
    vec2 u = f * f * (3.0 - 2.0 * f);
    
    return mix(a, b, u.x) +
    (c - a)* u.y * (1.0 - u.x) +
    (d - b) * u.x * u.y;
}

#define OCTAVES 6

float fbm (in vec2 st) {
    // Initial values
    float value = 0.0;
    float amplitude = .5;
    float frequency = 1;
    //
    // Loop of octaves
    for (int i = 0; i < OCTAVES; i++) {
        value += amplitude * noise(st);
        st *= 2.;
        amplitude *= .5;
    }
    return value;
}

//Based on code from Inigo Quilez (iq)
float pattern( in vec2 p )
{
    q = vec2( fbm( p + vec2(0.0,0.0) ),
                  fbm( p + vec2(5.2,1.3) ) );
    
    r = vec2( fbm( p + 4.0*q + vec2(1.7,9.2) ),
                  fbm( p + 4.0*q + vec2(8.3,2.8) ) );
    
    r += (time / 50);
    
    return fbm( p + 4.0*r);
}

void main() {
    vec2 uv = vUv * u_resolution;
    
    vec2 st = uv/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;
    
    vec3 color = vec3(0.0);
    
    vec4 newColor = vec4(0.0);
    
    vec4 finalColor = vec4(0.0);
    
    color += vec3(pattern(st)) * mix(vec3(20,187,80), vec3(224,11,71), 0.01) / vec3(25,25,25);
    color += mix(vec3(pattern(color.xy), pattern(color.xy), pattern(color.xy)), vec3(20,187,80), 1) / vec3(25,25,25);
    color = clamp(color, 0, 200);
                 
    fragColor = vec4((color * vec3(187,20,80) / vec3(256,256,256)), 1.0);
}
