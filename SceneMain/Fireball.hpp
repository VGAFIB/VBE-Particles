#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "Commons.hpp"

class Fireball : public GameObject {
	public:
		Fireball();

		void update(float deltaTime);
		void draw() const;

		Model model;
};

#endif // FIREBALL_HPP
