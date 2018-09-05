// holds logic for CashFlow market

#include <iostream>
#include <cstdlib>
#include <list>
#include "GenFun.hpp"
#include "Stock.hpp"
#include "Business.hpp"

using std::cout;
const int MCARDS = 40; // market cards



void market(std::list<Stock> &stock, std::list<Business> &smBusi, std::list<Business> &bigBusi)
{
    int s = rand() % MCARDS;
    // Apartment only
    if (s < 3)
    {
        cout << "Apartment buyer offers $"
             << 25000 + ((rand() % 200) * 100)
             << " per unit for any sized complex\n";

        sellBack(bigBusi);
    }
    // Apartment only (12+ unit)
    if (s == 3)
    {
        cout << "Apartment buyer offers $30,000"
             << " per unit for any complex"
             << " with 12 or more units\n";

        sellBack(bigBusi);
    }
    // Apartment and Plex (range-based)
    if (3 < s && s < 10)
    {
        cout << "Buyer offers $"
             << 1000 + ((rand() % 200) * 100)
             << " + the original cost for"
             << " any sized plex or apartment complex\n";

        sellBack(bigBusi);
    }
    // Apartment and Plex (percentage-based)
    if (10 <= s && s < 13)
    {
        int p = 5 + rand() % 15;
        cout << "Buyer offers " << p
             << "% + the original cost for"
             << " any sized plex or apartment complex\n";

        sellBack(bigBusi);
    }
    // House 3bed/2bath (range-based)
    if (13 <= s && s < 17)
    {
        cout << "3Br/2Ba House Buyer offers $"
             << 5000 + ((rand() % 150) * 100)
             << " + the original cost\n";

        sellBack(bigBusi);
    }
    // House 3bed/2bath (percentage-based)
    if (17 <= s && s < 20)
    {
        int p = 10 + rand() % 10;
        cout << "3Br/2Ba House Buyer offers " << p
             << "% + the original cost\n";

        sellBack(bigBusi);
    }
    // House 2bed/1bath (percentage-based)
    if (20 <= s && s < 22)
    {
        int p = 10 + rand() % 10;
        cout << "2Br/1Ba House Buyer offers " << p
             << "% + the original cost\n";


        sellBack(smBusi);
    }
    // House and Condo 2bed/1bath (range-based)
    if (22 <= s && s < 24)
    {
        cout << "2Br/1Ba House or Condo Buyer offers $"
             << 45000 + ((rand() % 200) * 100) << '\n';

       sellBack(smBusi);
    }
    // Stock Fluctuations
    if (24 <= s && s < 28)
    {

        int size = stock.size();
        if (size == 0)
        {
            cout << "There are no more stocks available\n\n";
            return;
        }

        // randomly determines which stock is affected
        int st = rand() % size;
        int count = 0;
        std::list<Stock>::iterator it = stock.begin();
        while (count < st)
        {
            ++it;
            ++count;
        }
        Stock s = *it;

        // determines which stock market fluctuation occurs
        int p = rand() % 100;

        // split
        if (p < 40) // 40% chance
        {
            cout << s.getName() << " splits.\n"
                 << "Double your shares\n\n";
        }
        // reverse split
        if (40 <= p && p < 80) // 40% chance
        {
            cout << s.getName() << " reverse splits\n"
                 << "Halve the number of shares you possess\n";
        }
        // stock crashes
        if (80 <= p && p < 100) // 20% chance
        {
            cout << "The value of " << s.getName() << " crashes\n"
                 << "Reduce the number of shares you have to zero.\n"
                 << "The stock is no longer available for the rest of the game\n\n";

            int canSell = rand()%3;
            if (canSell > 1)
            {
                cout << "You may sell all of your stock at current value: $"
                     << s.getValue() << "\n\n";
            }
            else
            {
                cout << "Business indicates that they don't have enough to pay\n"
                     << "stock investors at assigned market value.\n\n";
            }

            it = stock.begin();
            while (it != stock.end() )
            {
                if (s == *it)
                {
                    stock.erase(it);
                    return;
                }
                ++it;
            }


        }
    }
    // Gold Collector
    if (s == 28) cout << "Collector offers $500 per gold coin\n\n";
    if (s == 29) cout << "Collector offers $1000 per gold coin\n\n";
    // Bank buys gold
    if (s == 30) cout << "Central Bank offers $1000 per gold coin\n\n";
    if (30 < s && s < 33)  cout << "Central Bank offers $2000 per gold coin\n\n";
    // Tenant Property damage
    if (33 <= s && s < 35)
    {
        cout << "Tenant damages property\n"
             << "Make one time payment of $500\n\n";
    }
    if (s == 35)
    {
        cout << "Tenant damages property\n"
             << "Make one time payment of $1000\n\n";
    }
    // Sewer line break
    if (s == 36)
    {
        cout << "Sewer line breaks, causing damage to property\n"
             << "Make one time payment of $1000\n\n";
    }
    if (s == 37)
    {
        cout << "Sewer line breaks, causing damage to property\n"
             << "Make one time payment of $2000\n\n";
    }
    // Business booms
    if (s == 38)
    {
        cout << "Business booms\n"
             << "Businesses with cashflow of $1000 or less\n"
             << "increase  cashflow by $250\n\n";
    }
    if (s == 39)
    {
        cout << "New management increases business productivity\n"
             << "Businesses with cashflow of $1000 or less\n"
             << "increase  cashflow by $400\n\n";
    }

    return;
}
