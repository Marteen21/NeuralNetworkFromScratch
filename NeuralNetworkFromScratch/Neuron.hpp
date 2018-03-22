#pragma once
#include <vector>
#include "Connection.hpp"

namespace Znko {
	class Neuron
	{
		//Static members
	private:
		static double eta;
		static double alpha;
		static double transferFunction(double x);
		static double transferFuncitonDerivative(double x);
		//Class members
	private:
		std::vector<Connection> outputConnections;
	public:
		Neuron();
		virtual ~Neuron();
	};
}