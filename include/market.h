#ifndef MARKET_H
#define MARKET_H

#include "share.h"
#include "wallet.h"
#include <vector>

class Market {
public:
    std::vector<Share> shares;

    // std::vector<Wallet> wallets;

    int size() const { return (int)shares.size(); }
};

#endif