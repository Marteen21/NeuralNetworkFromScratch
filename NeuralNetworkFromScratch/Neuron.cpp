#include "stdafx.h"
#include <cmath>
#include "Neuron.hpp"

namespace znko {
	double Neuron::eta = 0.15; // overall net learning rate
	double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]

	double Neuron::TransferFunction(double x)
	{
		return tanh(x);
	}

	double Neuron::TransferFuncitonDerivative(double x)
	{
		return 1.0 - x * x;
	}

	Neuron::Neuron() : Object ()
	{
	}

	Neuron::~Neuron()
	{
	}

	const std::vector<Synapse*>& Neuron::GetInboundConnectionsConst(void) const
	{
		return this->inboundConnections;
	}

	std::vector<Synapse*>& Neuron::GetInboundSynapses(void)
	{
		return this->inboundConnections;
	}

	const std::vector<Synapse*>& Neuron::GetOutboundConnectionsConst(void) const
	{
		return this->outboundConnections;
	}

	std::vector<Synapse*>& Neuron::GetOutboundSynaptics(void)
	{
		return this->outboundConnections;
	}

	double Neuron::GetOutputValue(void) const
	{
		return this->outputValue;
	}

	double Neuron::GetGradient(void) const
	{
		return this->gradient;
	}
}
