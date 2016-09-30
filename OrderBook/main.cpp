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


	//TEST ORDER
	orderQueue.putOrderInQueue( Order("Trader1","Stock1",100,ORDER_SIDE::SELL) );
	orderQueue.putOrderInQueue( Order("Trader2","Stock1",200,ORDER_SIDE::BUY) );
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	orderQueue.putOrderInQueue( Order("Trader3","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader5","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader6","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader7","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader8","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader9","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader10","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader11","Stock1",100,ORDER_SIDE::BUY) );
	orderQueue.putOrderInQueue( Order("Trader12","Stock1",100,ORDER_SIDE::BUY) );
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	orderQueue.putOrderInQueue( Order("Trader4","Stock1",300,ORDER_SIDE::SELL) );


	t.join();
	return 0;
}