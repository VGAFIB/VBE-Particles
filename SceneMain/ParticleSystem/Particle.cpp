#include "Particle.hpp"

static vec2f texcoords[6] = {
	vec2f(-1, -1),
	vec2f(1, -1),
	vec2f(1, 1),
	vec2f(-1, -1),
	vec2f(1, 1),
	vec2f(-1, 1),
};

Particle::Particle() {
	life = Utils::randomFloat(1,1);
	startingLife = life;
	
	startSize = 0.1;
	endSize = 0.6;
	startCol = vec4f(1, 0, 0.05, 0.7);
	endCol = vec4f(3, 0.1, 0, 0);
}

void Particle::update(float deltaTime) {
	p += v*deltaTime + a*deltaTime*deltaTime*0.5f;
	v += a*deltaTime;
	life -= deltaTime;
}

void Particle::render(Particle::Vertex* vtx) const {
	float size = (startSize * (life) + endSize*(startingLife - life)) / startingLife;
	vec4f col = (startCol * (life) + endCol*(startingLife - life)) / startingLife;

	for(int i = 0; i < 6; i++) {
		Particle::Vertex& v = vtx[i];
		v.pos = p;
		v.tex = texcoords[i];
		v.col = col;
		v.size = size;
	}
}
