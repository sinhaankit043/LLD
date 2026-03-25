#include "ParkingLot.hpp"

ParkingLot* ParkingLot::instance = nullptr;

ParkingLot::ParkingLot() {
    ticketCounter = 0;
}

ParkingLot* ParkingLot::getInstance() {
    if (!instance)
        instance = new ParkingLot();
    return instance;
}

void ParkingLot::addFloor(ParkingFloor* floor) {
    floors.push_back(floor);
}

Ticket* ParkingLot::parkVehicle(Vehicle* v) {
    for (auto floor : floors) {
        for (auto spot : floor->spots) {
            if (spot->canPark(v)) {
                return new Ticket(++ticketCounter, v, spot);
            }
        }
    }
    return nullptr;
}

void ParkingLot::exitVehicle(Ticket* ticket, PaymentStrategy* paymentMethod) {
    time_t exitTime = time(0);

    Pricing* pricing = PricingFactory::createPricing(ticket->vehicle->type);
    
    int fee = pricing->calculateFee(ticket->entryTime, exitTime);

    cout << "Total Fee: " << fee << endl;

    paymentMethod->pay(fee);

    ticket->spot->removeVehicle();

    cout << "Spot Vacated" << endl;
}