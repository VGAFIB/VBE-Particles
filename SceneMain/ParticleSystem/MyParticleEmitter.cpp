#include "MyParticleEmitter.hpp"

MyParticleEmitter::MyParticleEmitter(int particlesPerSecond) : ParticleEmitter(particlesPerSecond) {
}

void MyParticleEmitter::update(float deltaTime) {
	ParticleEmitter::update(deltaTime);
}

Particle MyParticleEmitter::makeParticle(float frameTimePassed, float deltaTime, vec3f position) {
	(void) frameTimePassed;
	(void) deltaTime;
	vec4f color = vec4f(0, 0.1, 0.9, 1.0f);
	vec3f vel = glm::sphericalRand(3.5f);
	vec3f lol = (currWorldPos == oldWorldPos)? vec3f(0,1,0) : glm::normalize(currWorldPos - oldWorldPos);
	Particle pt;
	pt.life = 0.2;
	pt.startSize = 0;
	pt.endSize = 0.4;
	pt.startCol = color;
	pt.endCol = color;
	pt.endCol.w = 0;
	pt.v = lol + vel;
	pt.p = position + pt.v/10.0f;
	pt.a = lol;
	return pt;
}
