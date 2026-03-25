#pragma once
#include <ctime>

class Vehicle;
class ParkingSpot;

class Ticket {
public:
    int id;
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryTime;

    Ticket(int id, Vehicle* v, ParkingSpot* s);
};