#include<iostream>
using  namespace std;

//Adaptee
class LegacyCode{
    public:
    void getCustomerDataInfo(string id){
      cout<<"customer data fetched for id"<<id<<endl;
    }
};
//target interface or new system
class interface{
    public:
     virtual void getCustomerData(string id, string name)=0;
};
//Adapter
class LegacyCodeAdapter : public interface{
    LegacyCode*legacyCode;
    public:
    LegacyCodeAdapter( LegacyCode* legacyCode){
        this->legacyCode=legacyCode;
    }
    void getCustomerData(string id, string name){
        legacyCode->getCustomerDataInfo(id);
    }
     
};

int main(){

    LegacyCodeAdapter *legacyAdapter= new LegacyCodeAdapter(new LegacyCode());
    legacyAdapter->getCustomerData("123","ankit");

    return 0;
}