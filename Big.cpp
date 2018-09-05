// Holds Big Deal Card logic

#include <iostream>
#include <cstdlib>
#include <list>
#include "GenFun.hpp"
#include "Business.hpp"

using std::cout;

void big(std::list<Business> &busi)
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
