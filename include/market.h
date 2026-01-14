#ifndef MARKET_H
#define MARKET_H

#include "share.h"
#include "wallet.h"
#include <vector>

class Market {
public:
    std::vector<Share> shares;
    double time_steps = 1*252;
    // std::vector<Wallet> wallets;
    double market_optimisim = 0; // includes news, market predictions etc. This value is between -1,1 -> -1 means declining markets for example bad news covid... 1 optimistic market predictions
    int size() const { return (int)shares.size(); }
};

#endif