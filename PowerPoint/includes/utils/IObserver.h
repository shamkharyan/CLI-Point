#pragma once

template<typename T, typename EventType>
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual void update(const T& value, EventType event) = 0;
};

