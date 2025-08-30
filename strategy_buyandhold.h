#pragma once
#include "strategy.h"
#include <iostream>

class BuyAndHoldStrategy : public Strategy {
private:
    bool bought = false;

public:
    void onCandle(const Candle& candle) override {
        if (!bought) {
            std::cout << "BUY & HOLD @ " << candle.getClose() << " on " << candle.getDate() << "\n";
            bought = true;
        }
    }
    void printSummary() const override {
        std::cout << "Buy & Hold Strategy: 1 trade executed.\n";
        if (!trades.empty()) {
            double pnl = trades.back().price - trades.front().price;
            std::cout << "PnL: " << pnl << std::endl;
        }
    }

};
