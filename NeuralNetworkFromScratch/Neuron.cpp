#include "stdafx.h"
#include <cmath>
#include "Neuron.hpp"

namespace znko {
	double Neuron::eta = 0.15; // overall net learning rate
	double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]

	double Neuron::TransferFunction(double x)
	{
		return tanh(x);
	}

	double Neuron::TransferFuncitonDerivative(double x)
	{
		return 1.0 - x * x;
	}

	Neuron::Neuron()
	{
	}

	Neuron::~Neuron()
	{
	}
}