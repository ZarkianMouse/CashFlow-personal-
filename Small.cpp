// holds Small Deal Card logic

// Note: Need to fix Stock Distribution
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include "GenFun.hpp"
#include "Stock.hpp"
#include "Business.hpp"

using std::cout;
const int SMCARDS = 38;

void small(std::list<Stock> &stock, std::list<Business> &busi)
{

    int s = rand() % SMCARDS;

    if (s < 20)
    {
        int size = stock.size();
        if (size == 0)
        {
            cout << "There are no more stock options left\n\n";
            return;
        }

        int st = rand() % size;
        int count = 0;

        std::list<Stock>::iterator it = stock.begin();
        while (count < st)
        {
            ++it;
            ++count;
        }

        Stock s = *it;
        int changeType = rand()%100;
        if (changeType < 20)
        {
            cout << "Stock available for current player to purchase\n"
                 << "and all players to sell is:\n";
            s.print();
            return;
        }
        if (changeType >= 20 && changeType < 95)
        {
            s.setValue(rand()%5 + 1);
            cout << "Stock available for current player to purchase\n"
                 << "and all players to sell is:\n";
            s.print();
            *it = s;
            return;
        }
        if (changeType >= 95)
        {
            s.setValue(10+rand()%5);
            cout << "Stock available for current player to purchase\n"
                 << "and all players to sell is:\n";
            s.print();
            *it = s;
            return;
        }


    }

    if (s >= 20 && s < 31)
    {
        int size = busi.size();

        if (size == 0)
        {
            cout << "There are no businesses available for purchase\n";
            return;
        }
        int bu = rand() % size;

        int count = 0;
        std::list<Business>::iterator it = busi.begin();

        do {
            ++it;
            ++count;
        } while(count < bu);

        Business b = *it;

        b.print();

        cout << "Was this purchased?\n";
        char YN = isValid();

        if (YN == 'Y' || YN == 'y')
        {
            it = busi.begin();
            while (it != busi.end() )
            {
                if (b == *it)
                {
                    busi.erase(it);
                    return;
                }
                ++it;
            }
        }
        return;

    }
    if (s == 31)
    {
        cout << "You can purchase a locked filing cabinet\n"
             << "Pay $500 and roll 1 die: \n"
             << "Die = 1-5, you find nothing of interest\n"
             << "Die = 6, you find 10 Gold Coins.  Add these to Asset sheet\n\n";
    }
    if (s == 32)
    {
        cout << "A Distant relative passes away, naming you in the will\n"
             << "Pay $750 for travel and roll 1 die: \n"
             << "Die = 1-5, you get an old cat...meow\n"
             << "Die = 6, you are bequeathed 10 Gold Coins.  Add these to Asset Sheet\n\n";
    }
    if (s == 33)
    {
        cout << "Your sister-in-law is downsized and needs quick cash to pay rent\n"
             << "She promises $10,000 after she finds a new job\n"
             << "Pay $5,000 if you choose to help, and roll 1 die:\n"
             << "Die = 1-3, She doesn't pay you back/You're out $5,000\n"
             << "Die = 4-6, She pays you back $10,000, but family reunions are still awkward\n\n";
    }
    if (s == 34)
    {
        cout << "Friend needs quick cash\n"
             << "They will sell you 10 Gold Coins for $3,000\n\n";
    }
    if (s == 35)
    {
        cout << "Coin collector liquidates to get cash for tax issue\n"
             << "They will sell you 5 Gold Coins for $1,000\n\n";
    }
    if (s == 36 || s == 37)
    {
        cout << "Multi-Level Marketing Buy-In\n"
             << "Pay $500 and write down that you have this card\n"
             << "Every PayDay, roll 1 die:\n"
             << "Die = 1-3, No returns this month\n"
             << "Die = 4-6, Collect $500, Congrats\n\n";
    }

    return;
}
