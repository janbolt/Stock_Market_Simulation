#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>

class Wallet {
public:
    // in each vector at position i we have another wallet in units Wallet.units[i][j] we access amount of shares for share i -> i representing share_id
    std::vector<std::string> name;
    std::vector<double> cash;
    std::vector<std::vector<double>> units;   
    std::vector<int> strategy_id;

    Wallet(const std::string& n, double funds, int strat, int numShares)
        : name(n), cash(funds), units(numShares, 0.0), strategy_id(strat) {}
};

#endif