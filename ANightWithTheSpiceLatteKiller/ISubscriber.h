#pragma once
#include "IObserver.h"


class ISubscriber {
public:
	virtual ~ISubscriber() {};
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};



