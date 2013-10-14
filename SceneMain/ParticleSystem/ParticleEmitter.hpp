#ifndef PARTICLEEMITTER_HPP
#define PARTICLEEMITTER_HPP

#include "Commons.hpp"
#include "Particle.hpp"

class ParticleSystem;
class ParticleEmitter : public GameObject
{
	public:
		ParticleEmitter();

		Particle p;
		float period;

		void update(float deltaTime);

		vec3f pos;

	private:
		void spawnParticle(float t, float deltaTime);

		ParticleSystem* sys;
		vec3f oldWorldPos;
		vec3f currWorldPos;
		float state;
};

#endif // PARTICLEEMITTER_HPP
