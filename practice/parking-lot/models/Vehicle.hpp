#pragma once
#include <string>
using namespace std;

enum class VehicleType { BIKE, CAR, TRUCK };

class Vehicle {
public:
    string plateNumber;
    VehicleType type;

    Vehicle(string plateNumber, VehicleType type);
};

class VehicleFactory {
public:
    static Vehicle* createVehicle(string num, VehicleType type);
};