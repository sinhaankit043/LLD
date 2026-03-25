#include "Vehicle.hpp"

Vehicle::Vehicle(string plateNumber, VehicleType type) {
    this->plateNumber = plateNumber;
    this->type = type;
}

Vehicle* VehicleFactory::createVehicle(string num, VehicleType type) {
    return new Vehicle(num, type);
}