#ifndef COMMONS_HPP
#define COMMONS_HPP
#include "VBE/includes.hpp"
#include "VBE/modules/particles.hpp"

namespace Utils {
	extern std::mt19937 mersenne;
	//Returns random float in [min, max)
	inline float randomFloat(float min, float max) {
		return ((mersenne() & 0x7FFFFFFF) / float(0x7FFFFFFF))*(max-min)+min;
	}
}

#endif // COMMONS_HPP
