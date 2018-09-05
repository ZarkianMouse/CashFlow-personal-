// holds definition for Stock class

#include <iostream>
#include <string>
#include <cstdlib>
#include "Stock.hpp"

Stock::Stock() :
    name("blank"), value(20)
{}

Stock::Stock(std::string n) :
    name(n), value(20)
{}

Stock::Stock(std::string n, int v) :
    name(n), value(v)
{}

void Stock::setValue(int v)
{
    int i = rand()%3;
    if (i < 2)
        v = -v;
    value += v;
    if (value < 1)
        value = 1;
    else if (value > 50)
        value = 50;
}

void Stock::print()
{
    std::cout << "Name: " << name << '\t'
              << "Value: $" << value << '\n';
    return;
}

void Stock::operator=(const Stock s)
{
    name = s.name;
    value = s.value;
}

Stock::~Stock()
{}


bool operator==(Stock a, Stock b)
{
    return a.getName() == b.getName() && a.getValue() == b.getValue();
}
