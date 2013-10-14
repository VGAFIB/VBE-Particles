#ifndef _PARTICLES_H
#define _PARTICLES_H

#include "Commons.hpp"

class Particle {
	public:
		struct Vertex {
				vec3f pos;
				vec2f tex;
				vec4f col;
				float size;
		};

		vec3f p;
		vec3f v;
		vec3f a;

		float life, startingLife;

		float startSize, endSize;
		vec4f startCol, endCol;

		Particle();
		void interact(Particle& b, float deltaTime);
		void update(float deltaTime);
		void render(Particle::Vertex* vtx) const;
};


#endif
