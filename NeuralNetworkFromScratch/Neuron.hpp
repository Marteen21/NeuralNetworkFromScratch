#pragma once
#include <vector>
#include "Synapse.hpp"
#include "Object.h"

namespace znko {
	class Layer;

	class Neuron : Object
	{
		//Static members
	private:
		static double eta;
		static double alpha;
		static double TransferFunction(double x);
		static double TransferFuncitonDerivative(double x);
		//Class members
	private:
		double outputValue;
		double gradient;
		std::vector<Synapse*> outboundSynapses;
		std::vector<Synapse*> inboundSynapses;
	public:
		//Constructors and destructor
		Neuron();
		Neuron(const Neuron &source) = delete;
		Neuron(const Neuron &&source) = delete;
		Neuron operator=(const Neuron &source) = delete;
		Neuron operator=(const Neuron &&source) = delete;
		virtual ~Neuron();
		//Setters and getters
		const std::vector<Synapse*>&	GetInboundSynapsesConst (void) const;
		std::vector<Synapse*>&			GetInboundSynapses (void);

		const std::vector<Synapse*>&	GetOutboundSynapsesConst(void) const;
		std::vector<Synapse*>&			GetOutboundSynaptics(void);

		double							GetOutputValue(void) const;
		double							GetGradient(void) const;

		void							FeedForward(void);
		double SumDOW();
		void calcHiddenGradients();
		void calcOutputGradients(double targetVals);
	public:
		static double GetEta(void) { return eta; }
		static double GetAlpha(void) { return alpha; }
	};
}
