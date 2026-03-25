#include "Ticket.hpp"
#include "Vehicle.hpp"
#include "ParkingSpot.hpp"

Ticket::Ticket(int id, Vehicle* v, ParkingSpot* s) {
    this->id = id;
    this->vehicle = v;
    this->spot = s;
    this->entryTime = time(0);
}