// Holds Constants
#pragma once

#include <iosfwd>
#include "Stock.hpp"
#include "Business.hpp"

const Stock INIT_STOCK[4] {
    Stock("MYT4U"),
    Stock("ON2U"),
    Stock("OK4U"),
    Stock("GRO4US")
};

const Business INIT_SMALL[11] {
    Business("2/1 house", 35000, 33000, 2000, 220),
    Business("2/1 house", 45000, 43000, 2000, 250),
    Business("2/1 house", 65000, 60000, 5000, 160),
    Business("2/1 house", 50000, 47000, 3000, 100),
    Business("2/1 house", 50000, 48000, 2000, 200),
    Business("2/1 house", 50000, 46000, 4000, 200),
    Business("2/1 house", 30000, 29000, 1000, 0),
    Business("2/1 condo", 40000, 39000, 1000, 0),
    Business("2/1 condo", 40000, 35000, 5000, 220),
    Business("2/1 condo", 40000, 36000, 4000, 140),
    Business("2/1 condo", 55000, 50000, 5000, 160),
};

const Business INIT_BIG [36] {
    Business("Duplex", 250000, 234000, 16000, 900),
    Business("Duplex", 245000, 233000, 12000, 800),
    Business("Duplex", 170000, 152000, 18000, 900),
    Business("Duplex", 260000, 25000, 10000, 1100),
    Business("Duplex", 260000, 248000, 12000, 600),
    Business("4-plex", 300000, 280000, 20000, 1100),
    Business("4-plex", 340000, 308000, 32000, 1400),
    Business("4-plex", 290000, 275000, 15000, 800),
    Business("4-plex", 225000, 210000, 15000, 700),
    Business("4-plex", 280000, 264000, 16000, 1000),
    Business("4-plex", 370000, 360000, 10000, 900),
    Business("8-plex", 320000, 280000, 40000, 1700),
    Business("8-plex", 360000, 328000, 32000, 1800),
    Business("8-plex", 250000, 210000, 40000, 2000),
    Business("8-plex", 240000, 200000, 40000, 1800),
    Business("3/2 house", 325000, 307000, 18000, 900),
    Business("3/2 house", 225000, 211000, 14000, 750),
    Business("3/2 house", 350000, 330000, 20000, 1000),
    Business("3/2 house", 275000, 259000, 16000, 750),
    Business("3/2 house", 300000, 288000, 12000, 800),
    Business("3/2 house", 300000, 280000, 20000, 1000),
    Business("3/2 house", 270000, 255000, 15000, 800),
    Business("3/2 house", 275000, 260000, 15000, 800),
    Business("24-unit apt", 575000, 500000, 75000, 3600),
    Business("12-unit apt", 350000, 300000, 50000, 3000),
    Business("60-unit apt", 1200000, 1000000, 200000, 11000),
    Business("24-unit apt", 550000, 500000, 50000, 2400),
    Business("Limited Partner-sandwich shop", 30000, 0, 30000, 1700),
    Business("Limited Partner-pizza chain", 20000, 0, 20000, 1200),
    Business("Limited Partner-auto dealer", 30000, 0, 30000, 1500),
    Business("Limited Partner-doctor office", 25000, 0, 25000, 1300),
    Business("Automated-car wash", 125000, 100000, 25000, 18000),
    Business("Automated-laundromat", 150000, 120000, 30000, 2500),
    Business("Automated-arcade", 180000, 160000, 20000, 1600),
    Business("Pizza franchise", 500000, 400000, 100000, 5000),
    Business("Car wash", 350000, 300000, 50000, 2500)
};
