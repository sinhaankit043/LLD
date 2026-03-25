#pragma once
#include "Pricing.hpp"
#include "Vehicle.hpp"

class PricingFactory {
public:
    static Pricing* createPricing(VehicleType type);
};