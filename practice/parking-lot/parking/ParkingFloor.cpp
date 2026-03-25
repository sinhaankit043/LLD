#include "ParkingFloor.hpp"

ParkingFloor::ParkingFloor(int num) {
    this->floorNumber = num;
}

void ParkingFloor::addSpot(ParkingSpot* spot) {
    spots.push_back(spot);
}

bool ParkingFloor::park(Vehicle* v) {
    for (auto spot : spots) {
        if (spot->canPark(v)) return true;
    }
    return false;
}