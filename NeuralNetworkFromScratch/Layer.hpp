#pragma once
#include <vector>
#include "Neuron.hpp";
namespace Znko {
	class Layer
	{
	public:
		std::vector<Neuron> neurons;
	public:
		Layer();
		virtual ~Layer();

		void UpdateOutputWeights(void);
	};
}