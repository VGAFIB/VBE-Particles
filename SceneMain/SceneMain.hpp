#ifndef SCENEMAIN_HPP
#define SCENEMAIN_HPP
#include "Commons.hpp"

class ParticleSystem;
class Game;

class SceneMain : public GameObject {
	public:
		SceneMain();
		~SceneMain();
		void update(float deltaTime);

	private:
		bool loadResources();
		float debugCounter;
		int fpsCount;
		float radius;

		ParticleSystem* particles;
};

#endif // SCENEMAIN_HPP
