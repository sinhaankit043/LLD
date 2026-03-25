#include "ParkingLot.hpp"
#include "Vehicle.hpp"

#include "Payment.hpp"
#include <unistd.h>

int main() {
    ParkingLot* lot = ParkingLot::getInstance();

    ParkingFloor* floor1 = new ParkingFloor(1);
    floor1->addSpot(new ParkingSpot(1, SpotType::SMALL));
    floor1->addSpot(new ParkingSpot(2, SpotType::MEDIUM));

    lot->addFloor(floor1);

    Vehicle* vehicle =
        VehicleFactory::createVehicle("KA-123", VehicleType::BIKE);

    Ticket* ticket = lot->parkVehicle(vehicle);

    sleep(2);

    PaymentStrategy* strategy =
        new PaymentStrategy(new CardPayment());

    lot->exitVehicle(ticket, strategy);

    return 0;
}


//Command to run in parking-lot directory

//  g++ -std=c++17 -I./models -I./parking -I./pricing -I./payment \
main.cpp models/*.cpp parking/*.cpp pricing/*.cpp payment/*.cpp \
-o app


//then

// ./app