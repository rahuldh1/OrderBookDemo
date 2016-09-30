#include "stdafx.h"

#include "OrderStore.h"

	std::list<Order> OrderStore::getUnmatchedOrdersForSingleStock(std::string Stock, ORDER_SIDE Side)
	{
		std::list<Order> unmatchedOrdersSingleStock;
		std::pair <UnmatchedOrdersMultimap::const_iterator, UnmatchedOrdersMultimap::const_iterator> ret;
		ret = UnmatchedOrders.equal_range( Stock );

		if( !( ( ret.first == UnmatchedOrders.end( ) ) && ( ret.second == UnmatchedOrders.end( ) ) ) )
		{
			for (auto it = ret.first; it != ret.second; ++it)
			{
				if(it->second.Side != Side)
					unmatchedOrdersSingleStock.push_back(it->second);
			}
		}

		return unmatchedOrdersSingleStock;
	}

	void OrderStore::removeMatchedOrder(Order order)
	{
		std::pair <UnmatchedOrdersMultimap::const_iterator, UnmatchedOrdersMultimap::const_iterator> ret;
		ret = UnmatchedOrders.equal_range( order.Stock );

		if( !( ( ret.first == UnmatchedOrders.end( ) ) && ( ret.second == UnmatchedOrders.end( ) ) ) )
		{
			for (auto it = ret.first; it != ret.second; ++it)
			{
				if(it->second.Side == order.Side)
				{
					UnmatchedOrders.erase(it);
					break;
				}
			}
		}
		
	}