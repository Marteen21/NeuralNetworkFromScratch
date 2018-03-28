#include "stdafx.h"
#include "Layer.hpp"


znko::Layer::Layer() : Object ()
{
}


znko::Layer::~Layer()
{
}

void znko::Layer::UpdateOutputWeights(void)
{
	for (unsigned n = 0; n < neurons.size(); n++) {
		Neuron &neuron = neurons[n];
		const std::vector<Synapse*>& inboundSynapses = neuron.GetInboundConnections();
	}
}
