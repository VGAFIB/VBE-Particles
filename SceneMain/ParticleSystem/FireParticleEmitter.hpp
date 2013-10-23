#ifndef FIREPARTICLEEMITTER_HPP
#define FIREPARTICLEEMITTER_HPP
#include "Commons.hpp"

class FireParticleEmitter : public ParticleEmitter {
	public:
		FireParticleEmitter(int particlesPerSecond);
		Particle makeParticle(float frameTimePassed, float deltaTimem, vec3f position);
};

#endif // FIREPARTICLEEMITTER_HPP
