// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <chrono>
#include "OrderBook.h"

int _tmain(int argc, _TCHAR* argv[])
{
	OrderQueue orderQueue;
	OrderBook orderBook(&orderQueue);
	
	std::thread t(&OrderBook::run, orderBook);


	//TEST ORDER (1 million Buy and Sell orders on multiple stocks are placed)
	orderQueue.putOrderInQueue( Order("Trader1","Stock1",250000,ORDER_SIDE::SELL) );
	orderQueue.putOrderInQueue( Order("Trader2","Stock2",250000,ORDER_SIDE::SELL) );
	orderQueue.putOrderInQueue( Order("Trader3","Stock3",250000,ORDER_SIDE::SELL) );
	orderQueue.putOrderInQueue( Order("Trader5","Stock1",250000,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader6","Stock2",250000,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader4","Stock4",250000,ORDER_SIDE::SELL) );
	orderQueue.putOrderInQueue( Order("Trader7","Stock3",250000,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader8","Stock4",250000,ORDER_SIDE::BUY) );



	t.join();
	return 0;
}