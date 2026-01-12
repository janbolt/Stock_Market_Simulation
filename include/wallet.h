#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>

class Wallet {
public:
    std::string name;
    double cash;
    std::vector<double> units;   // units[i] = how many units of share i
    int strategy_id;

    Wallet(const std::string& n, double funds, int strat, int numShares)
        : name(n), cash(funds), units(numShares, 0.0), strategy_id(strat) {}
};

#endif