#ifndef MYPARTICLEEMITTER_HPP
#define MYPARTICLEEMITTER_HPP

#include "ParticleEmitter.hpp"

class MyParticleEmitter : public ParticleEmitter {
	public:
		MyParticleEmitter(int particlesPerSecond);

		void update(float deltaTime);

		vec4f color;
	private:
		vec4f oldColor;
		Particle makeParticle(float frameTimePassed, float deltaTime);
};

#endif // MYPARTICLEEMITTER_HPP
