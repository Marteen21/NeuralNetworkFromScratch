#include "stdafx.h"
#include "Layer.hpp"


znko::Layer::Layer() : Object ()
{
}


znko::Layer::~Layer()
{
}

void znko::Layer::UpdateInboundSynapseWeights(void)
{
	for (unsigned n = 0; n < neurons.size(); n++) {
		Neuron &postsynapticNeuron = neurons[n];
		std::vector<Synapse*>& inboundSynapses = postsynapticNeuron.GetInboundSynapses();
		for (std::vector<Synapse*>::iterator it = inboundSynapses.begin(); it != inboundSynapses.end(); ++it) {
			Synapse* synapse = *it;
			Neuron& presynapticNeuron = *(synapse->GetPostsynapticNeuron());
			const double oldDeltaWeight = synapse->GetDeltaWeight();
			double newDeltaWeight =
				// Individual input, magnified by the gradient and train rate:
				Neuron::GetEta ()
				* presynapticNeuron.GetOutputValue()
				* postsynapticNeuron.GetGradient()
				// Also add momentum = a fraction of the previous delta weight
				+ Neuron::GetAlpha()
				* oldDeltaWeight;
			synapse->SetDeltaWeight(newDeltaWeight);
			synapse->AddWeight(newDeltaWeight);
		} 
	}
}


void znko::Layer::FeedForward(void)
{
	double sum = 0.0;

	// Sum the previous layer's outputs (which are our inputs)
	// Include the bias node from the previous layer.

	for (unsigned n = 0; n < neurons.size(); n++) {
		Neuron& neuron = neurons[n];
		//sum += neuron.GetOutputValue() * neuron.G

	}
	//for (unsigned n = 0; n < prevLayer.size(); ++n)
	//{
	//	sum += prevLayer[n].getOutputVal() *
	//		prevLayer[n].m_outputWeights[m_myIndex].weight;
	//}

	//m_outputVal = Neuron::transferFunction(sum);
}

