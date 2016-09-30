#pragma once

#include <iostream>

#include "Order.h"
#include "OrderQueue.h"
#include "OrderStore.h"

class OrderMatcher
{
public:
	OrderMatcher(OrderStore& orderStoreParam);
	~OrderMatcher(void);

	void matchOrder(Order* pIncomingOrder);

private:
	void notifyTrader(const std::string& Trader)
	{
		std::cout << "Order of Trader " << Trader << " successful !" << std::endl;
	}

	OrderStore& orderStore;
};

