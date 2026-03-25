#pragma once
#include <vector>
#include "ParkingSpot.hpp"

class ParkingFloor {
public:
    int floorNumber;
    vector<ParkingSpot*> spots;

    ParkingFloor(int num);

    void addSpot(ParkingSpot* spot);
    bool park(Vehicle* v);
};