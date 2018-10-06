#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Constants.hpp"
#include "GenFun.hpp"
#include "Stock.hpp"
#include "Business.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

const int STOCK_SIZE = 4;
const int SMALL_SIZE = 11;
const int BIG_SIZE = 36;
int main()
{
    srand(time(NULL));

    cout << "Hello world!" << endl;

    list<Stock> stock;
    stock.assign(INIT_STOCK, INIT_STOCK+STOCK_SIZE);

    list<Business> smBusi;
    smBusi.assign(INIT_SMALL, INIT_SMALL+SMALL_SIZE);

    list<Business> bigBusi;
    bigBusi.assign(INIT_BIG, INIT_BIG+BIG_SIZE);

    bool loopFlag = true;

    do {
        char c;
        cout << "Choose your card:\n"
            << "A. Small Deal\n"
            << "B. Big Deal\n"
            << "C. Market\n"
            << "D. Doodad\n"
            << "E. End game\n"
            << "F. (Bankruptcy Support Center)\n";

        cin >> c;


        switch(toupper(c))
        {
            case 'A' : small(stock, smBusi);
                break;
            case 'B' : big(bigBusi);
                break;
            case 'C' : market(stock, smBusi, bigBusi);
                break;
            case 'D' : doodad();
                break;
            case 'E' : cout << "Thanks for playing\n"
                            << "Hope you had fun\n";
                     loopFlag = false;
                break;
            case 'F' : cout << "Welcome to the Bankruptcy Support Center\n";
                     bankruptcySellBack(smBusi, bigBusi);
                break;

            default : cout << "Invalid card\n";
                break;
        }

    } while (loopFlag);

    return 0;
}



