#version 420

layout (points) in;
layout (triangle_strip, max_vertices = 256) out;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

in vec2 geom_vel[];
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

	mat2 rot = mat2(1.0);

	vec2 v = geom_vel[0];
	float len = length(v);
	if(len > 0.0001)
	{
		len = 1+len*0.2;

		v = normalize(v);
		vec2 vl = vec2(-v.y,v.x);
		rot = mat2(v*len, vl);
	}

	for(int i = 0; i < 4; i++) {
		// copy attributes
		vec2 disp = rot*texCoords[i];
		gl_Position = projectionMatrix * (gl_in[0].gl_Position + vec4(disp * geom_size[0], 0.0, 0.0));
		vTexCoord = texCoords[i];
		vColor = geom_color[0];
		// done with the vertex
		EmitVertex();
	}
	EndPrimitive();
}
