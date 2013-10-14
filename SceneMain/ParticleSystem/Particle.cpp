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
{
	life = 1;
	startingLife = 1;
	
	startSize = 0.0;
	endSize = 0.6;
	startCol = vec4f(1, 0, 0.05, 1);
	endCol = vec4f(3, 0.1, 0, 0);
	
}

void Particle::update(float deltaTime)
{
	v += a*deltaTime;
	p += v*deltaTime;
	life -= deltaTime;
}

void Particle::render(Particle::Vertex* vtx) const
{
	float size = (startSize * (life) + endSize*(startingLife - life)) / startingLife;
	vec4f col = (startCol * (life) + endCol*(startingLife - life)) / startingLife;

	for(int i = 0; i < 6; i++)
	{
		Particle::Vertex& v = vtx[i];
		v.pos = p;
		v.tex = texcoords[i];
		v.col = col;
		v.size = size;
	}
}
