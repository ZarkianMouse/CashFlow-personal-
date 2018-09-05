// Holds Business class definitions
#include <iostream>
#include "Business.hpp"

Business::Business()
    : type("blank"), cost(0), mortgage(0), down(0), flow(0)
{}
Business::Business(std::string s, int c, int m, int d, int f)
    : type(s), cost(c), mortgage(m), down(d), flow(f)
{}

void Business::operator=(Business b)
{
    type = b.type;
    cost = b.cost;
    mortgage = b.mortgage;
    down = b.down;
    flow = b.flow;
}

bool operator==(Business a, Business b)
{
   return a.type == b.type && a.cost == b.cost && a.mortgage == b.mortgage && a.down == b.down && a.flow == b.flow;
}

void Business::print()
{
    std::cout << "Type: " << type << '\n'
              << "Cost: $" << cost << "\t\t"
              << "Mortgage: $" << mortgage << '\n'
              << "Down Payment: $" << down << '\t'
              << "Cash Flow: $" << flow << '\n';
}
