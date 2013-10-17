#include "FireParticleEmitter.hpp"

FireParticleEmitter::FireParticleEmitter(int particlesPerSecond) : ParticleEmitter(particlesPerSecond) {
}

Particle FireParticleEmitter::makeParticle(float frameTimePassed, float deltaTime, vec3f position) {
	(void) frameTimePassed;
	(void) deltaTime;
	vec3f vel = glm::sphericalRand(3.0f);
	vec3f lol = (currWorldPos == oldWorldPos)? vec3f(0,1,0) : glm::normalize(oldWorldPos - currWorldPos);
	Particle pt;
	pt.life = 1;
	pt.startSize =1;
	pt.endSize = 0.5;
	pt.startCol = vec4f(1, Utils::randomFloat(0, 0.4), 0.01, 0.7);
	pt.endCol = vec4f(1, 0.4, 0.09, 0);
	pt.v = lol + vel;
	pt.p = position + pt.v/10.0f;
	pt.a = lol;
	return pt;
}
