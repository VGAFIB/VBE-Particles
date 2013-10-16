#ifndef PARTICLEEMITTER_HPP
#define PARTICLEEMITTER_HPP

#include "Commons.hpp"
#include "Particle.hpp"

class ParticleSystem;
class ParticleEmitter : public GameObject {
	public:
		ParticleEmitter(int particlesPerSecond);

		void update(float deltaTime);
		vec3f pos;
		vec3f rot; //wat

		int getParticlesPerSecond() {return floor(1.0f/period);}
		void setParticlesPerSecond(int particlesPerSecond) {period = 1.0f/particlesPerSecond;}

	protected:
		virtual Particle makeParticle();
	private:
		void spawnParticle(float frameTimePassed, float deltaTime);

		float period;
		ParticleSystem* sys;
		vec3f oldWorldPos;
		vec3f currWorldPos;
		float state;
};

#endif // PARTICLEEMITTER_HPP
