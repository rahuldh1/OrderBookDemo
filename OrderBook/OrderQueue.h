#pragma once

#include <string>
#include <queue>
#include <mutex>

#include "Order.h"

class OrderQueue
{
public:
	OrderQueue(void) {}
	~OrderQueue(void) {}

	void putOrderInQueue(const Order& order)
	{
		mutexForQueue.lock();
		incomingOrders.push(order);
		mutexForQueue.unlock();
	}


	Order* getOrderFromQueue()
	{
		Order* pOrder = nullptr;
		if(mutexForQueue.try_lock())
		{
			if(!incomingOrders.empty())
			{
				pOrder = new Order(incomingOrders.front());
				incomingOrders.pop();			
			}
			mutexForQueue.unlock();
		}
		return pOrder;
	
	}
	
private:
	std::queue<Order> incomingOrders;
	std::mutex mutexForQueue;
};

