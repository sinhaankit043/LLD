#include "ParkingSpot.hpp"

ParkingSpot::ParkingSpot(int id, SpotType type) {
    this->id = id;
    this->type = type;
    this->isOccupied = false;
}

bool ParkingSpot::canFit(Vehicle* v) {
    if (v->type == VehicleType::BIKE && type == SpotType::SMALL) return true;
    if (v->type == VehicleType::CAR && type == SpotType::MEDIUM) return true;
    if (v->type == VehicleType::TRUCK && type == SpotType::LARGE) return true;
    return false;
}

bool ParkingSpot::canPark(Vehicle* v) {
    if (!isOccupied && canFit(v)) {
        isOccupied = true;
        return true;
    }
    return false;
}

void ParkingSpot::removeVehicle() {
    isOccupied = false;
}

bool ParkingSpot::isFree() {
    return !isOccupied;
}