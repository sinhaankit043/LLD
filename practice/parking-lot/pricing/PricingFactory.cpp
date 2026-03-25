#include "PricingFactory.hpp"

Pricing* PricingFactory::createPricing(VehicleType type) {
    if (type == VehicleType::BIKE) {
        return new BikePricing();
    }
    if (type == VehicleType::CAR) {
        return new CarPricing();
    }
    return new TruckPricing();
}