#include<iostream>
using namespace std;



class ICharacter{
    public:
    virtual string getAbilities()=0;
};

class Mario:public ICharacter{
    public:
    string getAbilities(){
        return "Mario";
    }
};

class ICharacterDecorator:public ICharacter{
    public:
    ICharacter*character;
    ICharacterDecorator(ICharacter*character){
        this->character=character;
    }
    virtual string getAbilities()=0;

};

class HeightUpDecorator:public ICharacterDecorator{
      public:
      HeightUpDecorator(ICharacter*character):ICharacterDecorator(character){}

      string getAbilities(){
        return character->getAbilities()+"after height up";
      }
};

class GunPowerDecorator:public ICharacterDecorator{
    public:
    GunPowerDecorator(ICharacter*character):ICharacterDecorator(character){};
    string getAbilities(){
        return character->getAbilities()+"with gun power";
    }
};


int main(){
    ICharacter*character = new Mario();
    cout<<"Basic character:"<<character->getAbilities()<<endl;

    character= new HeightUpDecorator(character);
    cout<<"After height up:"<<character->getAbilities()<<endl;

    character= new GunPowerDecorator(character);
    cout<<"After Gun Power:"<<character->getAbilities()<<endl;
}


