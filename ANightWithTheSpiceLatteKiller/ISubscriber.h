#include "IObserver.h"

#pragma once
class ISubscriber {
public:
	virtual ~ISubscriber() {};
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};



