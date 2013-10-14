#include "ParticleEmitter.hpp"
#include "ParticleSystem.hpp"

#include "glm/gtc/random.hpp"

ParticleEmitter::ParticleEmitter(): pos(0.0f), sys(NULL), oldWorldPos(pos), currWorldPos(pos) {
	period = 1.0f / 30000; //30k particles per second
	sys = (ParticleSystem*) getGame()->getObjectByName("ParticleSystem");
	setName("pe");
}

void ParticleEmitter::update(float deltaTime) {
	currWorldPos = vec3f(fullTransform*vec4f(pos,1.0));

	state += deltaTime;
	while(state > period) {
		state -= period;
		spawnParticle(state/deltaTime);
	}

	oldWorldPos = currWorldPos;
}

void ParticleEmitter::spawnParticle(float t)
{
	Particle pt = p;
	pt.p = oldWorldPos * (1-t) + currWorldPos * t;
	pt.v = glm::ballRand(5.0f);
	pt.a = vec3f(-12-pt.v.x*3, -pt.v.y*3, -pt.v.z);

	sys->addParticle(pt);
}
