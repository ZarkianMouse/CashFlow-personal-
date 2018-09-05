// holds Stock class
#pragma once
#include <iosfwd>

class Stock {
  public :
    Stock();
    Stock(std::string);
    Stock(std::string, int);

    void setValue(int); // used for changes in stock value

    const std::string getName() {return name;}
    const int getValue() {return value;}

    void operator=(const Stock);

    void print();

    ~Stock();
  private :
    std::string name;
    int value;
};

bool operator==(Stock, Stock);
