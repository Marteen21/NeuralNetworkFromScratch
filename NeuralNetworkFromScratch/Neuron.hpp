#pragma once
#include <vector>
#include "Connection.hpp"

namespace znko {
	class Neuron
	{
		//Static members
	private:
		static double eta;
		static double alpha;
		static double TransferFunction(double x);
		static double TransferFuncitonDerivative(double x);
		//Class members
	private:
		//std::vector<Connection> outputConnections;
	public:
		Neuron();
		Neuron(const Neuron &source) = delete;
		Neuron(const Neuron &&source) = delete;
		Neuron operator=(const Neuron &source) = delete;
		Neuron operator=(const Neuron &&source) = delete;
		virtual ~Neuron();
	};
}