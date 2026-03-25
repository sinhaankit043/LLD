#pragma once
#include <ctime>

class Pricing {
public:
    virtual int calculateFee(time_t startTime, time_t endTime) = 0;
};

class BikePricing : public Pricing {
public:
    int calculateFee(time_t startTime, time_t endTime);
};

class CarPricing : public Pricing {
public:
    int calculateFee(time_t startTime, time_t endTime);
};

class TruckPricing : public Pricing {
public:
    int calculateFee(time_t startTime, time_t endTime);
};