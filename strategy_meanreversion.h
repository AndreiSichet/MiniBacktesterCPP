#pragma once
#include "strategy.h"
#include <deque>
#include <iostream>

class MeanReversionStrategy : public Strategy {
private:
    std::deque<double> closes;
    int period;
    double threshold;
    bool positionOpen = false;
    double sum = 0.0;

public:
    MeanReversionStrategy(int p = 10, double t = 0.02) : period(p), threshold(t) {}

    void onCandle(const Candle& candle) override {
        closes.push_back(candle.getClose());
        sum += candle.getClose();

        if (closes.size() > period) {
            sum -= closes.front();
            closes.pop_front();
        }

        if (closes.size() < period) return;

        double sma = sum / period;
        double deviation = (candle.getClose() - sma) / sma;

        if (!positionOpen && deviation < -threshold) {
            trades.push_back({ candle.getDate(), candle.getClose(), true });
            std::cout << "BUY @ " << candle.getClose() << " on " << candle.getDate() << "\n";
            positionOpen = true;
        }
        else if (positionOpen && deviation > threshold) {
            trades.push_back({ candle.getDate(), candle.getClose(), false });
            std::cout << "SELL @ " << candle.getClose() << " on " << candle.getDate() << "\n";
            positionOpen = false;
        }
    }

    void printSummary() const override {
        std::cout << "Mean Reversion Strategy: " << trades.size() / 2 << " trades executed.\n";
        double pnl = 0.0;
        for (size_t i = 0; i + 1 < trades.size(); i += 2)
            pnl += trades[i + 1].price - trades[i].price;
        std::cout << "PnL: " << pnl << std::endl;
    }
};


