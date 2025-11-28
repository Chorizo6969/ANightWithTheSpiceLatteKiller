#pragma once
#include <string>


class IObserver {
public:
	virtual ~IObserver() {};
	virtual void Update(int value) = 0;
};