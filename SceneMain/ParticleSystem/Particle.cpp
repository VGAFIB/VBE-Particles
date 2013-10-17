#include "Particle.hpp"

static vec2f texcoords[6] = {
	vec2f(-1, -1),
	vec2f(1, -1),
	vec2f(1, 1),
	vec2f(-1, -1),
	vec2f(1, 1),
	vec2f(-1, 1),
};

Particle::Particle()
	: life(1), lifeLeft(1),
	  startSize(1), endSize(1),
	  startCol(1.0f), endCol(1.0f),
	  p(0.0f), v(0.0f), a(0.0f){
}

void Particle::update(float deltaTime) {
	p += v*deltaTime + a*deltaTime*deltaTime*0.5f;
	v += a*deltaTime;
	lifeLeft -= deltaTime*(1/life);
}

void Particle::render(Particle::Vertex& vtx) const {
	float size = (startSize*lifeLeft + endSize*(1-lifeLeft));
	vec4f col = (startCol*lifeLeft + endCol*(1-lifeLeft));
	vtx.pos = p;
	vtx.vel = v;
	vtx.col = col;
	vtx.size = size;
}
