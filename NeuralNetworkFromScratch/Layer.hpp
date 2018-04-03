#pragma once
#include <vector>
#include "Neuron.hpp"
#include "Object.h"

namespace znko {
	class Layer : Object
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

		void UpdateInboundSynapseWeights(void);
		void FeedForward(void);
	};
}
