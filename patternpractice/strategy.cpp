#include <iostream>
using namespace std;

class Talkable{
    public:
    virtual void talk()=0;
};
class NormalTalk:public Talkable{
    public:
    void talk(){
        cout<<"normal talk";
    }
};

class StandardTalk:public Talkable{
    public:
    void talk(){
        cout<<"standard talk";
    }
};

class Flyable{
    public:
    virtual void fly()=0;
};

class NormalFly:public Flyable{
      public:
      void fly(){
        cout<<"normal fly";
      }
};

class StandardFly:public Flyable{
    public:
    void fly(){
        cout<<"standard fly";
    }
};


class Robot{
    public:
    Talkable*talkbehaviour;
    Flyable*flybehaviour;

    Robot(Talkable*t,Flyable*f){
        this->talkbehaviour=t;
        this->flybehaviour=f;
    }

    void fly(){
        flybehaviour->fly();
    }

    void talk(){
        talkbehaviour->talk();
    }
};

class CompanionRobot:public Robot{
    public:
    CompanionRobot(Talkable*t,Flyable*f):Robot(t,f){};
};








int main() {
    // Write C++ code here

    Robot*r1=new CompanionRobot(new NormalTalk(),new StandardFly());
    r1->fly();
    r1->talk();
   

    return 0;
}