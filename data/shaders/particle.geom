#version 420

layout (points) in;
layout (triangle_strip, max_vertices = 256) out;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

in vec4 geom_color[];
in float geom_size[];

out vec2 vTexCoord;
out vec4 vColor;

const vec2[4] texCoords = {
	vec2( 1, 1),
	vec2(-1, 1),
	vec2( 1,-1),
	vec2(-1,-1)
};

void main() {
	for(int i = 0; i < 4; i++) {
		// copy attributes
		gl_Position = projectionMatrix * (gl_in[0].gl_Position + vec4(texCoords[i] * geom_size[0], 0.0, 0.0));
		vTexCoord = texCoords[i];
		vColor = geom_color[0];
		// done with the vertex
		EmitVertex();
	}
	EndPrimitive();
}
