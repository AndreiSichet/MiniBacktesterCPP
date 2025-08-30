# C++ Trading Strategy Backtester

## Description
This is a **C++ backtester** for trading strategies, built using **Object-Oriented Programming (OOP)** and **Standard Template Library (STL)**.  
The project allows you to test and compare different trading strategies on historical data stored in .txt files, providing detailed performance metrics for each strategy.


## Features
- OOP design with the following classes:
  - Strategy: abstract base class which defines the interface for a trading strategies.
  - Loader: loads historical market data from .txt files.
  - Candle: represents a single market data point.
- Efficient data handling using STL (vector, deque, standard algorithms).
- Support for multiple strategies (SMA, MeanReversion, etc.) – easily extensible.
- Automatic performance metrics calculation:
  - **Profit and Loss (PnL)**
  - **Number of trades executed**
  


