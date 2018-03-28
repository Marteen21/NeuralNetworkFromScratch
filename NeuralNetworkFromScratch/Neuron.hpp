#pragma once
#include <vector>
#include "Synapse.hpp"
#include "Object.h"

namespace znko {
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
		std::vector<Synapse*> outboundConnections;
		std::vector<Synapse*> inboundConnections;
	public:
		//Constructors and destructor
		Neuron();
		Neuron(const Neuron &source) = delete;
		Neuron(const Neuron &&source) = delete;
		Neuron operator=(const Neuron &source) = delete;
		Neuron operator=(const Neuron &&source) = delete;
		virtual ~Neuron();
		//Setters and getters
		const std::vector<Synapse*>& GetInboundConnections(void) const;
		const std::vector<Synapse*>& GetOutboundConnections(void) const;
	};
}
