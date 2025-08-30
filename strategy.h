#pragma once
#include "candle.h"
#include <vector>

struct Trade {
    std::string date;
    double price;
    bool isBuy; 
};
class Strategy {
public:
    std::vector<Trade> trades;
    virtual void onCandle(const Candle& candle) = 0;
    virtual void printSummary() const = 0;
    virtual ~Strategy() = default;
};
