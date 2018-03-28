#pragma once
#include "Object.h"

namespace znko {
	class Neuron;

	class Synapse : Object
	{
	private:
		double weight;
		double dWeight;
		Neuron *source;
		Neuron *target;

	public:
		Synapse();
		Synapse(const Synapse &source) = delete;
		Synapse(const Synapse &&source) = delete;
		Synapse operator=(const Synapse &source) = delete;
		Synapse operator=(const Synapse &&source) = delete;
		virtual ~Synapse();

	};
}
