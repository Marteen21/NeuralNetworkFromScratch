#pragma once
#include <vector>
#include "Neuron.hpp"
#include "Object.h"

namespace znko {
	class Net : Object
	{
	public:
		std::vector<Neuron> neurons;
		Net* previousNet;
		Net* nextNet;
	public:
		Net();
		virtual ~Net();
		Net(const Net &source) = delete;
		Net(const Net &&source) = delete;
		Net operator=(const Net &source) = delete;
		Net operator=(const Net &&source) = delete;
	};
}
