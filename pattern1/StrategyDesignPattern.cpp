#include<iostream>
 using namespace std;
 
 
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

 class Robot{

    Talkable*talkbehaviour;
    public:
    Robot(Talkable* t){
        this->talkbehaviour=t;
    }
    void talk(){
        talkbehaviour->talk();
    }
 };
 class CompanionRobot :public Robot{
    public:
    CompanionRobot(Talkable*t): Robot(t){}
 };


 int main(){
  Robot*r1= new CompanionRobot(new StandardTalk());
  r1->talk();
  return 0;
 }