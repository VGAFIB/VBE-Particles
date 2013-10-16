#include "ParticleEmitter.hpp"
#include "ParticleSystem.hpp"
#include "glm/gtc/random.hpp"

ParticleEmitter::ParticleEmitter(int particlesPerSecond)
	: pos(0.0f), period(1.0f/particlesPerSecond),
	  sys(NULL), oldWorldPos(pos), currWorldPos(pos), state(0.0f) {
	sys = (ParticleSystem*) getGame()->getObjectByName("ParticleSystem");
}

void ParticleEmitter::update(float deltaTime) {
	VBE_ASSERT(period > 0, "Invalid particle emitter period. Period must be bigger than 0.");
	currWorldPos = vec3f(fullTransform*vec4f(pos,1.0));
	while(state < deltaTime) {
		state += period;
		spawnParticle(state, deltaTime);
	}
	state -= deltaTime;
	oldWorldPos = currWorldPos;
}

Particle ParticleEmitter::makeParticle() {
	return Particle(1.01+cos(GLOBALCLOCK.getElapsedTime().asSeconds())*1,1,0,vec4f(1, 0, 0.01, 0.7),vec4f(1, 0.4, 0.01, 0),
					vec3f(glm::diskRand(10.0f),0.0f),
					vec3f(glm::diskRand(0.0f),0.0f));
}

void ParticleEmitter::spawnParticle(float frameTimePassed, float deltaTime) {
	float t2 = frameTimePassed/deltaTime;
	Particle pt = makeParticle();
	pt.p = oldWorldPos * (1-t2) + currWorldPos * t2;
	pt.update(deltaTime-frameTimePassed); //update for the rest of the frame time
	sys->addParticle(pt);
}
