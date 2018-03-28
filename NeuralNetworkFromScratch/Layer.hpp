#pragma once
#include <vector>
#include "Neuron.hpp"
namespace znko {
	class Layer
	{
	public:
		std::vector<Neuron> neurons;
	public:
		Layer();
		virtual ~Layer();
		Layer(const Layer &source) = delete;
		Layer(const Layer &&source) = delete;
		Layer operator=(const Layer &source) = delete;
		Layer operator=(const Layer &&source) = delete;

		void UpdateOutputWeights(void);
	};
}