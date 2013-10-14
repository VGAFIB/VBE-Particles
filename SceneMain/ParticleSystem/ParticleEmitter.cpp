#include "ParticleEmitter.hpp"
#include "ParticleSystem.hpp"

#include "glm/gtc/random.hpp"

ParticleEmitter::ParticleEmitter(): pos(0.0f), sys(NULL), oldWorldPos(pos), currWorldPos(pos) {
	period = 1.0f / 30000; //30k particles per second
	sys = (ParticleSystem*) getGame()->getObjectByName("ParticleSystem");
	setName("pe");
	state = 0.0f;
}

void ParticleEmitter::update(float deltaTime) {
	currWorldPos = vec3f(fullTransform*vec4f(pos,1.0));

	while(state < deltaTime) {
		state += period;
		spawnParticle(state, deltaTime);
	}
	state -= deltaTime;

	oldWorldPos = currWorldPos;
}

void ParticleEmitter::spawnParticle(float t, float deltaTime) {
	float t2 = t/deltaTime;
	Particle pt;
	pt.p = oldWorldPos * (1-t2) + currWorldPos * t2;
	pt.v = glm::ballRand(5.0f);
	pt.a = vec3f(-pt.v.x*3-200, pt.v.y*3, pt.v.z);
	t = deltaTime-t;
	pt.update(t);
	sys->addParticle(pt);
}
