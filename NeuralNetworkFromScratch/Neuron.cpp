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

	const std::vector<Synapse*>& Neuron::GetInboundSynapsesConst(void) const
	{
		return this->inboundSynapses;
	}

	std::vector<Synapse*>& Neuron::GetInboundSynapses(void)
	{
		return this->inboundSynapses;
	}

	const std::vector<Synapse*>& Neuron::GetOutboundSynapsesConst(void) const
	{
		return this->outboundSynapses;
	}

	std::vector<Synapse*>& Neuron::GetOutboundSynaptics(void)
	{
		return this->outboundSynapses;
	}

	double Neuron::GetOutputValue(void) const
	{
		return this->outputValue;
	}

	double Neuron::GetGradient(void) const
	{
		return this->gradient;
	}

	void Neuron::FeedForward(void)
	{
		double sum = 0.0;
		Neuron* postSynapticNeuron = this;
		for (std::vector<Synapse*>::iterator it = inboundSynapses.begin(); it != inboundSynapses.end(); ++it) {
			Synapse* synapse = *it;
			Neuron* preSynapticNeuron = synapse->GetPresynapticNeuron();
			sum += preSynapticNeuron->outputValue * synapse->GetWeight ();
		}
		postSynapticNeuron->outputValue = Neuron::TransferFunction(sum);
	}

	double Neuron::SumDOW()
	{
		double sum = 0.0;
		Neuron* preSynapticNeuron = this;
		// Sum our contributions of the errors at the nodes we feed
		for (std::vector<Synapse*>::iterator it = outboundSynapses.begin(); it != outboundSynapses.end(); ++it) {
			Synapse* synapse = *it;
			Neuron* postSynapticNeuron = synapse->GetPostsynapticNeuron();
			sum += synapse->GetWeight() * postSynapticNeuron->GetGradient();
		}
		return sum;
	}

	void Neuron::calcHiddenGradients()
	{
		double dow = SumDOW();
		this->gradient = dow * Neuron::TransferFuncitonDerivative(this->outputValue);
	}


	void Neuron::calcOutputGradients(double targetVals)
	{
		double delta = targetVals - this->outputValue;
		this->gradient = delta * Neuron::TransferFuncitonDerivative(this->outputValue);
	}
}
