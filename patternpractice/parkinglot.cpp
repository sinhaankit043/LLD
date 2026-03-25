#include<iostream>
#include <unistd.h>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;


/*
  ParkingLot
  ParkingFloor
  ParkingSpot
  Vehicle
  Ticket
  Payment
 
*/

enum class VehicleType{BIKE,CAR,TRUCK};
enum class SpotType{SMALL,MEDIUM,LARGE};

class Vehicle{
   public:
  string plateNumber;
  VehicleType type;
 
  Vehicle(string &plateNumber,VehicleType type){
    this->plateNumber=plateNumber;
    this->type=type;
  }
};

class VehicleFactory{
    public:
    static Vehicle*createVehicle(string num,VehicleType type){
      return new Vehicle(num,type);
    }
};


/*
 Pricing Strategy
*/

class Pricing{
  public:
  virtual int calculateFee(time_t startTime, time_t endTime)=0;
};

class BikePricing:public Pricing{
  public:

  int calculateFee(time_t startTime,time_t endTime){
    int hours= ceil(difftime(startTime,endTime));
    return hours*10;
  }
};

class CarPricing:public Pricing{
  public:

  int calculateFee(time_t startTime,time_t endTime){
    int hours= ceil(difftime(startTime,endTime));
    return hours*20;
  }
};

class TruckPricing:public Pricing{
  public:

  int calculateFee(time_t startTime,time_t endTime){
    int hours= ceil(difftime(startTime,endTime));
    return hours*30;
  }
};

class PricingStrategy{
  public:
  Pricing*pricing;
  PricingStrategy(Pricing*pricing){
      this->pricing=pricing;
  }

  int calculateFee(time_t startTime,time_t endTime){
    return pricing->calculateFee(startTime,endTime);
  }
};

/*
Pricing Factory to create class to Pricing
*/

class PricingFactory{
  public:
  static Pricing*createPricing(VehicleType type){
    if(type==VehicleType::BIKE)return new BikePricing();
    if(type==VehicleType::CAR)return new CarPricing();
    return new TruckPricing();
  }
};


/*
 Payment Strategy
*/

class PaymentType{
  public:
  virtual void pay(int amount)=0;
  
};

class CardPayment:public PaymentType{
  public:
  void pay(int amount){
    if(amount>0){
      cout<<"Amount of Rs"<<amount<<"is paid successfully through card"<<endl;
    }
    else cout<<"Invalid Amount to be paid through Card"<<endl;
  }
};


class UPIPayment:public PaymentType{
  public:
  void pay(int amount){
    if(amount>0){
      cout<<"Amount of Rs"<<amount<<"is paid successfully through UPI"<<endl;
    }
    else cout<<"Invalid Amount to be paid through UPI"<<endl;
  }
};

class PaymentStrategy{
  public:
  PaymentType*paymentType;
  PaymentStrategy(PaymentType*paymentType){
    this->paymentType=paymentType;
  }

  void pay(int amount){
    paymentType->pay(amount);
  }
};




class ParkingSpot{
    public:
    int id;
    SpotType spot;
    bool isOccupied;
  
    ParkingSpot(int id,SpotType spot){
      this->id=id;
      this->spot=spot;
      this->isOccupied=false;
    }

    bool canFit(Vehicle*v){
      if(v->type == VehicleType::BIKE && spot==SpotType::SMALL)return true;
      if(v->type == VehicleType::CAR && spot == SpotType:: MEDIUM)return true;
      if(v->type == VehicleType::TRUCK && spot == SpotType:: LARGE)return true;
      else return false;
    }

    bool canPark(Vehicle*v){
      if(!isOccupied && canFit(v)){
        isOccupied=true;
        return true;
      }
      else return false;
    }

    void removeVehicle(){
      isOccupied=false;
    }

    bool isFree(){
      return !isOccupied;
    }

};



class ParkingFloor{
  public:
    int floorNumber;
    vector<ParkingSpot*>spots;

    ParkingFloor(int floorNumber){
      this->floorNumber=floorNumber;
    }

    void addSpot(ParkingSpot*spot){
      spots.push_back(spot);
    }

    bool park(Vehicle*v){
      for(auto spot:spots){
        if(spot->canPark(v))return true;
      }
        return false;
    }

};

class Ticket{
  public:
  int id;
  Vehicle*vehicle;
  ParkingSpot*spot;
  time_t entryTime;

  Ticket(int id,Vehicle*v,ParkingSpot*s){
    this->id=id;
    this->vehicle=v;
    this->spot=s;
    this->entryTime=time(0);
  }
};



class ParkingLot{
     public:
     static ParkingLot*instance;
     vector<ParkingFloor*>floors;
     int ticketCounter=0;

     ParkingLot(){};

     public:
     static ParkingLot*getInstance(){
      if(instance==NULL){
        instance= new ParkingLot();
      }
       return instance;
     }


     void addFloors(ParkingFloor*floor){
      floors.push_back(floor);
     }


     Ticket* parkVehicle(Vehicle*v){
      for(auto floor:floors){
         for(auto spot:floor->spots){
          if(spot->canPark(v)){

            cout<<"Vehicle Parked"<<endl;
            return new Ticket(++ticketCounter,v,spot);
          }
         }
      }
      cout<<"No spot available"<<endl;
      return nullptr;
     }

     void exitVehicle(Ticket* ticket,PaymentStrategy*paymentMethod){
       time_t exitTime=time(0);

       Pricing*pricing =PricingFactory::createPricing(ticket->vehicle->type);
       PricingStrategy*pricingStrategy=new PricingStrategy(pricing);
       int fee=pricingStrategy->calculateFee(ticket->entryTime,exitTime);
       fee+=20;

      paymentMethod->pay(fee);

      ticket->spot->removeVehicle();
      cout<<"Spot Vacated"<<endl;

     }



};


ParkingLot* ParkingLot::instance=nullptr;




int main(){
  ParkingLot*lot=ParkingLot::getInstance();
  
  ParkingFloor*floor1=new ParkingFloor(1);
  floor1->addSpot(new ParkingSpot(1,SpotType::SMALL));
  floor1->addSpot(new ParkingSpot(2,SpotType::MEDIUM));
  lot->addFloors(floor1);

  Vehicle* vehicle1=VehicleFactory::createVehicle("KA-123",VehicleType::BIKE);
   Vehicle* vehicle2=VehicleFactory::createVehicle("KA-124",VehicleType::BIKE);

  


  Ticket*ticket1=lot->parkVehicle(vehicle1);
   Ticket*ticket2=lot->parkVehicle(vehicle2);


  sleep(2);

  PaymentStrategy*strategy= new PaymentStrategy(new CardPayment());


  lot->exitVehicle(ticket1,strategy);
    Vehicle* vehicle3=VehicleFactory::createVehicle("KA-125",VehicleType::BIKE);
     Ticket*ticket3=lot->parkVehicle(vehicle3);

  return 0;

}