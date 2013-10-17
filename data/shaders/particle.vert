#version 420

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

in vec3 a_position;
in vec3 a_vel;
in vec4 a_color;
in float a_size;

out vec2 geom_vel;
out vec4 geom_color;
out float geom_size;

void main () {
	gl_Position = modelViewMatrix * vec4(a_position, 1.0);
	geom_color = a_color;
	geom_size = a_size;
	geom_vel = (mat3(modelViewMatrix)*a_vel).xy;
}
