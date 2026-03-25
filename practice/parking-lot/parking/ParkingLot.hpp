#pragma once
#include <vector>
#include "ParkingFloor.hpp"
#include "Ticket.hpp"
#include "Pricing.hpp"
#include "Payment.hpp"
#include "PricingFactory.hpp"

class ParkingLot {
private:
    static ParkingLot* instance;
    vector<ParkingFloor*> floors;
    int ticketCounter;

    ParkingLot();

public:
    static ParkingLot* getInstance();

    void addFloor(ParkingFloor* floor);
    Ticket* parkVehicle(Vehicle* v);

    void exitVehicle(Ticket* ticket, PaymentStrategy* paymentMethod);
};