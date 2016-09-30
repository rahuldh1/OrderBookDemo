#include "stdafx.h"

#include "OrderMatcher.h"


	OrderMatcher::OrderMatcher(OrderStore& orderStoreParam) 
		: orderStore(orderStoreParam)
	{}

	OrderMatcher::~OrderMatcher(void)
	{
	}

	void OrderMatcher::matchOrder(Order* pIncomingOrder)
	{
		std::cout << "Matching incoming order (" << *pIncomingOrder << ")..." << std::endl;

		// Get orders from orderStore for the particular stock (orders should be with order_side opposite to the order_side in incomingOrder)
		std::list<Order> unmatchedOrdersSingleStock = orderStore.getUnmatchedOrdersForSingleStock(pIncomingOrder->Stock, pIncomingOrder->Side);

		if(unmatchedOrdersSingleStock.empty())
		{
			std::cout << "No matching orders found in UnmatchedOrders. Adding the new order in Unmatched orders." << std::endl;
			orderStore.addUnmatchedOrder(*pIncomingOrder);
		}
		else
		{
			// Try to match the incoming order with the above selected orders
			long incomingQuantityLeft = pIncomingOrder->Quantity;
			long unmatchedQuantityLeft = 0;
			for(auto iter = unmatchedOrdersSingleStock.begin(); iter != unmatchedOrdersSingleStock.end(); ++iter)
			{
				unmatchedQuantityLeft = iter->Quantity;

				if(incomingQuantityLeft == unmatchedQuantityLeft)
				{
					incomingQuantityLeft = 0;
					notifyTrader(pIncomingOrder->Trader);

					unmatchedQuantityLeft = 0;
					notifyTrader(iter->Trader);	

					break;
				}
				else if(incomingQuantityLeft < unmatchedQuantityLeft)
				{
					unmatchedQuantityLeft = unmatchedQuantityLeft - incomingQuantityLeft;
					iter->Quantity = unmatchedQuantityLeft;

					incomingQuantityLeft = 0;
					notifyTrader(pIncomingOrder->Trader);

					break;
				}
				else // incomingQuantityLeft > unmatchedQuantityLeft
				{
					incomingQuantityLeft = incomingQuantityLeft - unmatchedQuantityLeft;

					unmatchedQuantityLeft = 0;
					orderStore.removeMatchedOrder(*iter);
					notifyTrader(iter->Trader);
				}
			}

			if(incomingQuantityLeft > 0)
			{
				pIncomingOrder->Quantity = incomingQuantityLeft;
				orderStore.addUnmatchedOrder(*pIncomingOrder);
			}
		}

	
	}