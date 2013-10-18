#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "Commons.hpp"

class Fireball : public GameObject {
	public:
		Fireball();

		void update(float deltaTime);
		void draw() const;

		vec3f pos;
		vec3f vel;
		Model model;
};

#endif // FIREBALL_HPP
