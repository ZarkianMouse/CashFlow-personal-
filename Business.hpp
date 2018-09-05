// Holds Business class
#pragma once

#include <iosfwd>

class Business {
public :
    Business();
    Business(std::string, int, int, int, int);

    void operator=(Business);
    friend bool operator==(Business, Business);
    void print();

private :
    std::string type;
    int cost;
    int mortgage;
    int down;
    int flow;
};

