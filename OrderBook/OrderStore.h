
#pragma once

#include <map>
#include <list>
#include <iostream>
#include "Order.h"

typedef std::multimap<std::string, Order> UnmatchedOrdersMultimap;
typedef std::pair<std::string, Order> UnmatchedOrdersPair;

class OrderStore
{
private:
	UnmatchedOrdersMultimap UnmatchedOrders;

public:
	std::list<Order> getUnmatchedOrdersForSingleStock(std::string Stock, ORDER_SIDE Side);

	void addUnmatchedOrder(Order order)
	{
		UnmatchedOrders.insert(UnmatchedOrdersPair(order.Stock, order));
	}

	void removeMatchedOrder(Order order);

};