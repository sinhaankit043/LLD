#pragma once
#include "Vehicle.hpp"

enum class SpotType { SMALL, MEDIUM, LARGE };

class ParkingSpot {
public:
    int id;
    SpotType type;
    bool isOccupied;

    ParkingSpot(int id, SpotType type);

    bool canFit(Vehicle* v);
    bool canPark(Vehicle* v);
    void removeVehicle();
    bool isFree();
};