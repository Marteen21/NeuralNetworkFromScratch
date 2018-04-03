#pragma once
#include "Object.h"

namespace znko {
	class Neuron;

	class Synapse : Object
	{
	private:
		double weight;
		double dWeight;
		Neuron* presynapticNeuron;
		Neuron* postsynapticNeuron;

	public:
		Synapse();
		Synapse(const Synapse &source) = delete;
		Synapse(const Synapse &&source) = delete;
		virtual ~Synapse();
		Synapse operator=(const Synapse &source) = delete;
		Synapse operator=(const Synapse &&source) = delete;

		double GetDeltaWeight(void) const;
		void AddWeight(const double deltaWeight);
		void SetDeltaWeight(const double deltaWeight);

		Neuron* GetPresynapticNeuron(void) const;
		Neuron* GetPostsynapticNeuron(void) const;

	};
}
