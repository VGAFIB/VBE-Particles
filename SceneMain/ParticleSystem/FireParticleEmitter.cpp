#include "FireParticleEmitter.hpp"

FireParticleEmitter::FireParticleEmitter(int particlesPerSecond) : ParticleEmitter(particlesPerSecond) {
}

Particle FireParticleEmitter::makeParticle(float frameTimePassed, float deltaTime, vec3f position) {
	vec2f vel = glm::diskRand(1.0f);
	Particle pt;
	pt.life = 1;
	pt.startSize =1;
	pt.endSize = 0.5;
	pt.startCol = vec4f(1, Utils::randomFloat(0, 0.4), 0.01, 0.7);
	pt.endCol = vec4f(1, 0.4, 0.09, 0);
	pt.p = vec3f(position.x+vel.x/5.0f,position.y,position.z+vel.y/5.0f);
	pt.v = vec3f(vel.x,-3,vel.y);
	pt.a = vec3f(0,20,0);
	return pt;
}
