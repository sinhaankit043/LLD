#include "Pricing.hpp"
#include <cmath>

int BikePricing::calculateFee(time_t s, time_t e) {
    int hours = ceil((e - s) / 3600.0);
    return hours * 10;
}

int CarPricing::calculateFee(time_t s, time_t e) {
    int hours = ceil((e - s) / 3600.0);
    return hours * 20;
}

int TruckPricing::calculateFee(time_t s, time_t e) {
    int hours = ceil((e - s) / 3600.0);
    return hours * 30;
}