#pragma once

namespace znko {
	class Neuron;

	class Connection
	{
	private:
		double weight;
		double dWeight;
		Neuron *source;
		Neuron *target;

	public:
		Connection();
		Connection(const Connection &source) = delete;
		Connection(const Connection &&source) = delete;
		Connection operator=(const Connection &source) = delete;
		Connection operator=(const Connection &&source) = delete;
		virtual ~Connection();

	};
}