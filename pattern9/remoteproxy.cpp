#include<iostream>
using namespace std;

class IDataService{
    public:

    virtual string fetchData()=0;
};

class RealDataService{
   public:

   string fetchData(){
    return "[RealDataServide] data is fetched";
   }
};


class DataServiceProxy:public IDataService{
     public:
     RealDataService*dataservice=nullptr;

     DataServiceProxy(){
        this->dataservice= new RealDataService();
     }

     string fetchData(){
        cout<<"Connecting to remote server"<<endl;
        return this->dataservice->fetchData();
     }

};

int main(){
    IDataService*dataservice= new DataServiceProxy();
    string data=dataservice->fetchData();
    cout<<data<<endl;
}

/*
   clang++ -std=c++17 remoteproxy.cpp -o remoteproxy && ./remoteproxy
*/

