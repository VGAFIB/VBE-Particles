#include "Myparticleemitter.hpp"

MyParticleEmitter::MyParticleEmitter(int particlesPerSecond) : ParticleEmitter(particlesPerSecond), color(1.0f), oldColor(1.0f) {
}

void MyParticleEmitter::update(float deltaTime) {
	ParticleEmitter::update(deltaTime);
	oldColor = color;
}

Particle MyParticleEmitter::makeParticle(float frameTimePassed, float deltaTime) {
	float ratio = frameTimePassed/deltaTime;
	vec3f acc(0.0f);
	if(oldWorldPos != currWorldPos)
		acc = glm::normalize(glm::cross(oldWorldPos-currWorldPos,vec3f(0,0,(Utils::randomInt(-1,1) >= 0?1:-1 ))))*0.1f;
	return Particle(1,0,20,oldColor*ratio + color*(1-ratio),vec4f(0.0f),
					vec3f(0.0f),
					-1000.0f*acc);
}
