#include <string>

#pragma once
class IObserver {
public:
	virtual ~IObserver() {};
	virtual void Update(int value) = 0;
};