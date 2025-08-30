#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include "candle.h"
#include "strategy.h"

class Loader {
public:
    static void streamFromTxt(const std::string& filename, Strategy* strategy) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file \"" << filename << "\".\n";
            return;
        }

        std::string line;
        int lineNumber = 0;
        int validCount = 0;

        while (std::getline(file, line)) {
            ++lineNumber;
            if (line.empty()) continue;

            std::stringstream ss(line);
            std::string date;
            double open, high, low, close;
            double volume = 0.0;  

            
            if (!(ss >> date >> open >> high >> low >> close)) {
                std::cerr << "Warning: line " << lineNumber
                    << " is not valid: \"" << line << "\"\n";
                continue;
            }

            
            if (ss >> volume) {
                Candle c(date, open, high, low, close, volume);
                strategy->onCandle(c);
            }
            else {
                Candle c(date, open, high, low, close);
                strategy->onCandle(c);
            }

            ++validCount;
        }

        std::cout << "Finished loading. " << validCount
            << " valid candles processed from \"" << filename << "\".\n";
    }
};

