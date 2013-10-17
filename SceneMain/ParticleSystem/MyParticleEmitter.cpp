#include "MyParticleEmitter.hpp"

MyParticleEmitter::MyParticleEmitter(int particlesPerSecond) : ParticleEmitter(particlesPerSecond) {
}

void MyParticleEmitter::update(float deltaTime) {
	ParticleEmitter::update(deltaTime);
}

Particle MyParticleEmitter::makeParticle(float frameTimePassed, float deltaTime, vec3f position) {
	vec4f color = vec4f(0, 0.1, 0.9, 1.0f);
	Particle pt;
	pt.life = 0.5;
	pt.startSize =0;
	pt.endSize = 0.4;
	pt.startCol = color;
	pt.endCol = color;
	pt.endCol.w = 0;
	pt.p = position;
	pt.v = glm::ballRand(20.5f);
	pt.a = vec3f(0, 5, 0);
	return pt;
}
