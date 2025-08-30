#include <iostream>
#include <memory>
#include "loader.h"
#include "strategy_sma.h"
#include "strategy_buyandhold.h"
#include "strategy_meanreversion.h"

using namespace std;

int main() {
    string filename = "date.txt";
    unique_ptr<Strategy> strategy;

    cout << "Pick strategy:\n";
    cout << "1. SMA\n";
    cout << "2. Buy & Hold\n";
    cout << "3. Mean Reversion\n";
    cout << "Pick: ";

    int choice;
    cin >> choice;
    if (!cin || choice < 1 || choice > 3) {
        cout << "Invalid input.\n";
        return 1;
    }

    if (choice == 1) {
        strategy = make_unique<SmaStrategy>(5);
    }
    else if (choice == 2) {
        strategy = make_unique<BuyAndHoldStrategy>();
    }
    else if (choice == 3) {
        strategy = make_unique<MeanReversionStrategy>(10, 0.02);
    }
    else {
        cout << "Invalid strategy.\n";
        return 1;
    }

    Loader::streamFromTxt(filename, strategy.get());
    strategy->printSummary();
    return 0;
}
