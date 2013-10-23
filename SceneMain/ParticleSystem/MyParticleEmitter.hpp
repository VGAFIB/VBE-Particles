#ifndef MYPARTICLEEMITTER_HPP
#define MYPARTICLEEMITTER_HPP
#include "Commons.hpp"

class MyParticleEmitter : public ParticleEmitter {
	public:
		MyParticleEmitter(int particlesPerSecond);

		void update(float deltaTime);
	private:
		Particle makeParticle(float frameTimePassed, float deltaTime, vec3f position);
};

#endif // MYPARTICLEEMITTER_HPP
