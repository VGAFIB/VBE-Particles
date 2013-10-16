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
		Particle(const float& lifeSpan,
						   const float& startSize, const float& endSize,
						   const vec4f& startCol, const vec4f& endCol,
						   const vec3f& v, const vec3f& a);
		bool isAlive() {return (life>0);}
		void update(float deltaTime);
		void render(Particle::Vertex* vtx) const;

	private:
		float life, lifeMultiplier;
		float startSize, endSize;
		vec4f startCol, endCol;
		vec3f p, v, a;

		friend class ParticleEmitter;
};

#endif
