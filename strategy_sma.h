#pragma once
#include <deque>
#include <iostream>
#include "strategy.h"

class SmaStrategy : public Strategy {
private:
    int period;
    std::deque<double> window;
    double sum = 0.0;  

public:
    SmaStrategy(int p) : period(p) {
        if (p <= 0) throw std::invalid_argument("Period must be positive");
    }

    void onCandle(const Candle& c) override {
        window.push_back(c.getClose());
        sum += c.getClose();

        if (window.size() > period) {
            sum -= window.front();
            window.pop_front();
        }

        if (window.size() == period) {
            double sma = sum / period;

            std::cout << c.getDate() << " | Close: " << c.getClose()
                << " | SMA(" << period << "): " << sma << std::endl;
        }
    }
    void printSummary() const override {
        std::cout << "SMA Strategy: " << trades.size() << " trades executed.\n";
        double pnl = 0.0;
        for (size_t i = 0; i + 1 < trades.size(); i += 2) {
            pnl += trades[i + 1].price - trades[i].price;
        }
        std::cout << "PnL: " << pnl << std::endl;
    }
};

