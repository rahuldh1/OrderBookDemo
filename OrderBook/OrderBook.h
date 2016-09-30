#pragma once

#include "OrderStore.h"
#include "OrderQueue.h"
#include "OrderMatcher.h"


class OrderBook
{
public:
	OrderBook(OrderQueue* pOrderQueueParam);
	~OrderBook();

	void run();

private:
	OrderStore orderStore;
	OrderQueue* pOrderQueue;
	OrderMatcher* pOrderMatcher;
};
