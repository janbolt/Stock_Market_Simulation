# Stock Market Simulation

This project provides a C++ framework for simulating stock price movements and portfolio performance over time.  
All simulation **inputs are defined directly in the `InputValues` struct inside `simulation.h`**, and all simulation **outputs are written to a CSV file** for easy visualization and analysis. The use of input and output files as .h and .csv file will be adjusted to json file in future versions.

---

## Features

- Simulates multiple stocks using stochastic models  
- Supports Markov-chain–based and geometric brownian motion price simulations  
- Portfolio (“wallet”) simulation with customizable allocations  
- Fully configurable through the `InputValues` structure  
- Automatically exports results to a CSV file  

---

## Example Input Configuration

All input parameters are defined in `InputValues`:

```cpp
struct InputValues {
    int fund = 4000;
    int strategies = 2;
    std::vector<double> custom_allocation = {0.25, 0.25, 0.25, 0.25};
    std::vector<std::string> shares = {"Google", "Amazon", "Tesla", "Ferrero"};
    std::vector<double> variance = {0.04, 0.035, 0.03, 0.045};
    std::vector<double> expected_return = {0.10, 0.05, 0.2, 0.25};
    std::vector<double> initial_value = {10.34, 1.92, 5.23, 4.01};
    int time_steps = 365 * 1;
    int model = 1;

    void print() const;
};
