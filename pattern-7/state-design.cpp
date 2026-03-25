
#include<iostream>
using namespace std;


class VendingMachine;


class VendingState{
   public:

   virtual VendingState*insertCoin(VendingMachine*machine,int coin)=0;
   virtual VendingState*selectItem(VendingMachine*machine)=0;
   virtual VendingState*dispence(VendingMachine*machine)=0;
   virtual VendingState*refill(VendingMachine*machine, int quantity)=0;
  
};

class VendingMachine{
    public:
    VendingState*currentState;
    int itemCount;
    int itemPrice;
    int insertedCoin;

    VendingState* noCoinState;
    VendingState* hasCoinState;
    VendingState* dispenceState;
    VendingState* soldOutState;

    VendingMachine(int itemCount,int itemPrice);
   

    void setInsertedCoin(int coin){
        this->insertedCoin=coin;
    }

    void addCoin(int coin){
        this->insertedCoin+=coin;
    }

    void decrementItemCount(){
        this->itemCount--;
    }

    void refillItem(int quantity){
        this->itemCount+=quantity;
    }

    void insertCoin(int coin);

    void selectItem();

    void dispence();

    void refill(int quantity);




};

class NoCoinState:public VendingState{
   public:

      VendingState*insertCoin(VendingMachine*machine,int coin){
          machine->setInsertedCoin(coin);
          cout << "Coin inserted. Current balance: Rs " << coin <<endl;
          return machine->hasCoinState;
      }
      VendingState*selectItem(VendingMachine*machine){
           cout<<"Plese insert Coin"<<endl;
           return machine->noCoinState;
      }
      VendingState*dispence(VendingMachine*machine){
         cout<<"Plese insert Coin"<<endl;
           return machine->noCoinState;
      }
      VendingState*refill(VendingMachine*machine, int quantity){
         cout<<" Item Refilling... "<<endl;
         machine->refillItem(quantity);
        return machine->noCoinState;
      }


};

class HasCoinState:public VendingState{
   public:

      VendingState*insertCoin(VendingMachine*machine,int coin){
          cout<<"Please Select Item"<<endl;
          return machine->hasCoinState;
      }
      VendingState*selectItem(VendingMachine*machine){
         if(machine->insertedCoin>=machine->itemPrice){
            cout<<"Item selecte. Dispencing..."<<endl;
            int change =machine->insertedCoin-machine->itemPrice;
            if(change>0){
                cout<<"Change retured Rs"<<change<<endl;
            }
            machine->insertedCoin=0;
            return machine->dispenceState;

         }
         else{
            int needed= machine->itemPrice-machine->insertedCoin;
            cout<<"Insufficent coin. Please insert"<<needed<<"coin"<<endl;
            return machine->hasCoinState;
         }
      }
      VendingState*dispence(VendingMachine*machine){
        cout<<"Please select item"<<endl;
        return machine->hasCoinState;
      }
      VendingState*refill(VendingMachine*machine, int quantity){
        cout<<"Refilling item with quantity"<<quantity<<endl;
        machine->refillItem(quantity);
        return machine->hasCoinState;
      }


};

class DispenceState:public VendingState{
   public:

      VendingState*insertCoin(VendingMachine*machine,int coin){
          return machine->dispenceState;
      }
      VendingState*selectItem(VendingMachine*machine){
        return machine->dispenceState;
      }
      VendingState*dispence(VendingMachine*machine){
           cout<<"Item dispenced"<<endl;
           machine->decrementItemCount();
           if(machine->itemCount>0)return machine->noCoinState;
           else return machine->soldOutState;
      }
      VendingState*refill(VendingMachine*machine, int quantity){
        cout<<"can't refill in this state"<<endl;
        return machine->dispenceState;
      }


};

class SoldOutState:public VendingState{
   public:

      VendingState*insertCoin(VendingMachine*machine,int coin){
         return machine->soldOutState;

      }
      VendingState*selectItem(VendingMachine*machine){
        return machine->soldOutState;
      }
      VendingState*dispence(VendingMachine*machine){
        return machine->soldOutState;
      }
      VendingState*refill(VendingMachine*machine, int quantity){
          cout<<"Item refilling.."<<endl;
          machine->refillItem(quantity);
          return machine->noCoinState;
      }


};

 VendingMachine:: VendingMachine(int itemCount,int itemPrice){
        this->itemCount= itemCount;
        this->itemPrice = itemPrice;
        this->noCoinState = new NoCoinState();
        this->hasCoinState = new HasCoinState();
        this->dispenceState = new DispenceState();
        this->soldOutState = new SoldOutState();

        if(itemCount>0){
            currentState=this->noCoinState;
        }
        else {
            currentState= this->soldOutState;
        }

    }

     void VendingMachine:: insertCoin(int coin){
        currentState=currentState->insertCoin(this,coin);
    }

    void VendingMachine::selectItem(){
        currentState= currentState->selectItem(this);
    }

    void VendingMachine::dispence(){
        currentState=currentState->dispence(this);
    }

    void VendingMachine::refill(int quantity){
        currentState=currentState->refill(this,quantity);
    }






int main(){
    VendingMachine*machine= new VendingMachine(10,5);
    machine->insertCoin(10);
    machine->selectItem();
    machine->dispence();
    return 0;
}



