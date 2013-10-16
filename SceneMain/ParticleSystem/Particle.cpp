#include "Particle.hpp"

static vec2f texcoords[6] = {
	vec2f(-1, -1),
	vec2f(1, -1),
	vec2f(1, 1),
	vec2f(-1, -1),
	vec2f(1, 1),
	vec2f(-1, 1),
};

Particle::Particle(const float& lifeSpan,
				   const float& startSize, const float& endSize,
				   const vec4f& startCol, const vec4f& endCol,
				   const vec3f& v, const vec3f& a)
	: life(1), lifeMultiplier(1/std::max(lifeSpan,0.01f)),
	  startSize(startSize), endSize(endSize),
	  startCol(startCol), endCol(endCol),
	  p(0.0f), v(v), a(a){
}

void Particle::update(float deltaTime) {
	p += v*deltaTime + a*deltaTime*deltaTime*0.5f;
	v += a*deltaTime;
	life -= deltaTime*lifeMultiplier;
}

void Particle::render(Particle::Vertex* vtx) const {
	float size = (startSize*life + endSize*(1-life));
	vec4f col = (startCol*life + endCol*(1-life));
	for(int i = 0; i < 6; i++) {
		Particle::Vertex& v = vtx[i];
		v.pos = p;
		v.tex = texcoords[i];
		v.col = col;
		v.size = size;
	}
}
