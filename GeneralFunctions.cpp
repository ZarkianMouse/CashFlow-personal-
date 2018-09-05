// holds General Purpose Functions
// These may be used in other functions

#include <iostream>
#include "GenFun.hpp"
#include "Stock.hpp"
#include "Business.hpp"

using std::cin;
using std::cout;

char isValid()
{
    char YN;
    bool loopFlag = true;
    do {
        cin >> YN;
        if (YN != 'Y' && YN != 'y' && YN != 'N' && YN != 'n')
        {
            cout << "Invalid response\nPlease reenter\n";
        }
        else
            loopFlag = false;
    } while(loopFlag);
    return YN;
}

void sellBack(std::list<Business> &busi)
{
    bool loopFlag = true;

    do {
        cout << "Is anyone selling?\n";
        char YN = isValid();

        if (YN == 'Y' || YN == 'y')
        {
            std::string t;
            int c, d, f;

            cout << "Type of business: \n";
            while (t.length() == 0)
                getline(std::cin, t);
            cout << "Cost: ";
                cin >> c;
            cout << "\nDown Payment: ";
                cin >> d;
            cout << "\nCash Flow: ";
                cin >> f;


            Business b(t, c, c-d, d, f);
            busi.emplace_front(b);

            b.print();
            cout << "Sale of Property is successful\n\n";

        }
        else if (YN == 'N' || YN == 'n')
        {
            loopFlag = false;
            cout << '\n';
        }
        else
            cout << "Invalid entry\n";
    } while(loopFlag);
    return;
}

void bankruptcySellBack(std::list<Business> &smallBusi, std::list<Business> &bigBusi)
{
    bool loopFlag = true;
    char sellChoice;
    do {
        cout << "What type of business are you selling?\n"
             << "A. 2/1 house or condo\n"
             << "B. Other properties (apartments, plexes, 3/2 houses, etc.)\n"
             << "C. Finished Selling\n";
        cin >> sellChoice;

        switch (sellChoice)
        {
            case 'A' : sellBack(smallBusi);
                break;
            case 'a' : sellBack(smallBusi);
                break;
            case 'B' : sellBack(bigBusi);
                break;
            case 'b' : sellBack(bigBusi);
                break;
            case 'C' : loopFlag = false;
                break;
            case 'c' : loopFlag = false;
                break;
            default : cout << "Invalid choice\n";
                break;
        }
    } while (loopFlag);
    return;
}
