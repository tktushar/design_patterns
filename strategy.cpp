#include <iostream>
#include <map> 
#include <vector>
using namespace std;

enum class Indicator{
    bollinger,
    macd,
};

struct TradingStrategy{
    virtual void calculate(){};
    virtual void plot(){}
    virtual void 
}