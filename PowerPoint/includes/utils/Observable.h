//#pragma once
//
//#include "IObserver.h"
//
//#include <memory>
//#include <vector>
//
//template<typename T>
//class Observable
//{
//public:
//	void attach(std::shared_ptr<IObserver<T>> observer)
//	{
//		m_observers.push_back(observer);
//	}
//
//	void detach(const ObsPtr& obs) {
//		m_observers.erase(
//			std::remove_if(
//				m_observers.begin(), m_observers.end(),
//				[&](const std::weak_ptr<IObserver<T>>& o) {
//					return o.lock() == obs;
//				}),
//			m_observers.end()
//		);
//	}
//
//protected:
//	void notify(const T& value) 
//	{
//		for (auto& w : observers) 
//		{
//			if (auto obs = w.lock())
//				obs->update(value);
//		}
//	}
//
//private:
//	std::vector<std::weak_ptr<IObserver<T>>> m_observers;
//};
