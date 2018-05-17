
#version 150

uniform vec2 uvIter;

in vec4 position;
in vec2 texcoord;

out vec2 vUv;

void main(){

	vUv = texcoord;

	gl_Position = position;

}
