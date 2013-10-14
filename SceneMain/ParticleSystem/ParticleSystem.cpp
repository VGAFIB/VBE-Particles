#include "ParticleSystem.hpp"
#include "../PerspectiveCamera.hpp"
ParticleSystem::ParticleSystem()
{

	std::vector<Vertex::Element> elements;
	elements.push_back(Vertex::Element(Vertex::Attribute::Position   , Vertex::Element::Float, 3));
	elements.push_back(Vertex::Element(Vertex::Attribute::TexCoord   , Vertex::Element::Float, 2));
	elements.push_back(Vertex::Element(Vertex::Attribute::Color      , Vertex::Element::Float, 4));
	elements.push_back(Vertex::Element(Vertex::Attribute::get("a_size"), Vertex::Element::Float, 1));

	Vertex::Format format(elements);
	Mesh* mesh= new Mesh(format, 0, Mesh::STREAM);

	model.mesh = mesh;
	model.program = Programs.get("particle");

	setName("ParticleSystem");
}

void ParticleSystem::update(float deltaTime)
{
	for(std::list<Particle>::iterator it = particles.begin(); it != particles.end();)
	{
		it->update(deltaTime);
		if(it->life < 0)
			it = particles.erase(it);
		else
			++it;
	}
}

void ParticleSystem::draw() const
{
	if(particles.size() == 0)
		return;

	if(vtxs.size() < particles.size()*6)
		vtxs.resize(particles.size()*6);

	int i = 0;
	for(std::list<Particle>::const_iterator it = particles.begin(); it != particles.end(); it++)
	{
		it->render(&vtxs[i*6]);
		i++;
	}

	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	model.mesh->setVertexData(&vtxs[0], particles.size()*6);
	PerspectiveCamera* cam = static_cast<PerspectiveCamera*>(getGame()->getObjectByName("cam"));
	model.program->uniform("modelViewMatrix")->set(cam->view*fullTransform);
	model.program->uniform("projectionMatrix")->set(cam->projection);
	model.draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_TRUE);

}

void ParticleSystem::addParticle(Particle & p)
{
	particles.push_back(p);
}

