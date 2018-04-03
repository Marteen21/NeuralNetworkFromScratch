#include "stdafx.h"
#include "Synapse.hpp"

namespace znko {
	Synapse::Synapse() : Object ()
	{
	}

	Synapse::~Synapse()
	{
	}

	double Synapse::GetDeltaWeight(void) const
	{
		return this->dWeight;
	}

	void Synapse::AddWeight(const double deltaWeight)
	{
		this->weight += deltaWeight;
	}

	void Synapse::SetDeltaWeight(const double deltaWeight)
	{
		this->dWeight = deltaWeight;
	}

	Neuron * Synapse::GetPresynapticNeuron(void) const
	{
		return this->presynapticNeuron;
	}

	Neuron * Synapse::GetPostsynapticNeuron(void) const
	{
		return this->postsynapticNeuron;
	}
}
