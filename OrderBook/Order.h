#pragma once

#include <string>
#include <iostream>

enum ORDER_SIDE {BUY, SELL};

struct Order
{
	std::string Trader;
	std::string Stock;
	long Quantity; 
	ORDER_SIDE Side; //(Buy or Sell)

	Order(std::string TraderParam,std::string StockParam,long QuantityParam,ORDER_SIDE SideParam) :
		Trader (TraderParam),
		Stock (StockParam),
		Quantity (QuantityParam),
		Side (SideParam)
	{}

	friend std::ostream &operator<<( std::ostream &output, const Order &order )
      { 
		  const char* s = 0;
		#define PROCESS_VAL(p) case(p): s = #p; break;
			switch(order.Side)
			{
				PROCESS_VAL(BUY);     
				PROCESS_VAL(SELL);     
			}
		#undef PROCESS_VAL


		  output << "Trader : " << order.Trader << " Stock : " << order.Stock  << " Quantity : " << order.Quantity  << " ORDER_SIDE : " << s;
		  return output;            
      }
};