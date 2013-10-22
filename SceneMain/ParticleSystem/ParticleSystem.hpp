#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include "Particle.hpp"
#include "Commons.hpp"

class ParticleSystem : public GameObject {
	public:
		ParticleSystem();
		void update(float deltaTime);
		void draw() const;
		void addParticle(const Particle& p);
		int getParticleCount() const { return particles.size(); }
		void setTextureCount(unsigned int textureCount) { this->textureCount = textureCount; }

	private:
		std::list<Particle> particles;
		mutable std::vector<Particle::Vertex> vtxs;
		Model model;
		unsigned int textureCount;
};

#endif // PARTICLESYSTEM_HPP
