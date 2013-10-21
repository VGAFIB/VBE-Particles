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


	vec3 front = normalize(gl_in[0].gl_Position.xyz);
	vec3 vel = vec3(geom_vel[0],0.0f);
	vec3 up = cross(front,vel);

	// the rotation and scale matrix that represents the velocity and billboard effect of the particle
	mat3 transform = mat3(1.0);

	if(length(up) < 0.0001) {
		up = vec3(0.0, 1.0, 0.0);
		vec3 right = normalize(cross(front,up));
		up = cross(front, right);
		transform = mat3(right,up,front);
	}
	else {
		up = normalize(up);
		vec3 right = normalize(cross(front,up));
		float len = length(vel);
		transform = mat3(right*(1+len*0.4),up,front);
	}

	for(int i = 0; i < 4; i++) {
		// copy attributes
		vec3 disp = transform*vec3(texCoords[i], 0.0);
		gl_Position = projectionMatrix * (gl_in[0].gl_Position + vec4(disp * geom_size[0], 0.0));
		vTexCoord = texCoords[i];
		vColor = geom_color[0];
		// done with the vertex
		EmitVertex();
	}
	EndPrimitive();
}
