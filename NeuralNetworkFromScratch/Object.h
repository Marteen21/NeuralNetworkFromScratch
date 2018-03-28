#pragma once
namespace znko {
	class Object
	{
	public:
		Object();
		Object(const Object &source) = delete;
		Object(const Object &&source) = delete;
		Object operator=(const Object &source) = delete;
		Object operator=(const Object &&source) = delete;
		virtual ~Object();
	};
}