#include "stdafx.h"

#include <chrono>
#include <thread>

#include "OrderBook.h"

	OrderBook::OrderBook(OrderQueue* pOrderQueueParam) : 
		pOrderQueue(pOrderQueueParam)
	{
		pOrderMatcher = new OrderMatcher(orderStore);
	}

	OrderBook::~OrderBook()
	{
	}

	void OrderBook::run()
	{
		while(1)
		{
			Order* pIncomingOrder = pOrderQueue->getOrderFromQueue();

			if(pIncomingOrder != nullptr)
			{
				pOrderMatcher->matchOrder(pIncomingOrder);
			}

			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}



