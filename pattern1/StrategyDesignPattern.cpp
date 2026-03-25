#include<iostream>
 using namespace std;



 //clang++ -std=c++17 StrategyDesignPattern.cpp -o StrategyDesignPattern && ./StrategyDesignPattern
 
 
 class Talkable{
    public:
    virtual void talk()=0;
};
 class NormalTalk:public Talkable{
    public:
    void talk(){
        cout<<"normal Talk"<<endl;
    }
 };
  class StandardTalk:public Talkable{
    public:
    void talk(){
        cout<<"Standard Talk"<<endl;
    }
 };

  
 class Flyable{
    public:
    virtual void fly()=0;
};
 class NormalFly:public Flyable{
    public:
    void fly(){
        cout<<"normal fly"<<endl;
    }
 };
  class StandardFly:public Flyable{
    public:
    void fly(){
        cout<<"Standard fly"<<endl;
    }
 };

 class Robot{

    Talkable*talkbehaviour;
    Flyable*flybehaviour;
    public:
    Robot(Talkable* t,Flyable*f){
        this->talkbehaviour=t;
        this->flybehaviour=f;
    }
    void talk(){
        talkbehaviour->talk();
    }
    void fly(){
        flybehaviour->fly();
    }
 };
 class CompanionRobot :public Robot{
    public:
    CompanionRobot(Talkable*t,Flyable*f): Robot(t,f){}
 };


 int main(){
  Robot*r1= new CompanionRobot(new StandardTalk(),new NormalFly());
  r1->talk();
  r1->fly();
  return 0;
 }