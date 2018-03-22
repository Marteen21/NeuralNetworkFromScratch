#pragma once
#include "Neuron.hpp";

namespace Znko {
	class Connection
	{
	private:
		double weight;
		double dWeight;
		Neuron* source;
		Neuron* target;

	public:
		Connection();
		virtual ~Connection();

	};
}