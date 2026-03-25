#include<iostream>
using namespace std;


class Burger{
    public:
    virtual void prepare()=0;

};

class BasicBurger:public Burger{
       public:
       void prepare(){
        cout<<"Preparing basic burger";
       }
};

class StandardBurger:public Burger{
       public:
       void prepare(){
        cout<<"Preparing standard burger";
       }
};


class BurgerFactory{
    public:
     virtual  Burger*createBurger(string &type)=0;
};

class ConcreteBurgerFactory:public BurgerFactory{
    public:
      Burger*createBurger(string &type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else return nullptr;
      }
};




int main(){
    string type="standard";
     ConcreteBurgerFactory *factory= new ConcreteBurgerFactory();
     Burger*burger= factory->createBurger(type);
     burger->prepare();


    return 0;
}