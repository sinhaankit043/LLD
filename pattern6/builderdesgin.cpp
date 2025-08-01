#include<iostream>
#include<map>
using namespace std;


class HTTPRequest{
  private:
      string url;
      string method;
      map<string,string>headers;

      HTTPRequest(){};

   public:
     friend class HTTPRequestBuilder ;  

     void execute(){

          cout<<"Executing "<<this->method<<"with url"<<this->url<<endl;

          cout<<"executing header"<<endl;

          for(auto& header: headers){
            cout<<header.first <<" "<< header.second<<endl;
          }
          
     }
};

class HTTPRequestBuilder{
   private:
      HTTPRequest req;
    
   public:
     HTTPRequestBuilder& withUrl(const string& url){
        req.url=url;
        return *this;
     }  
      HTTPRequestBuilder& withMethod(const string& method){
        req.method=method;
        return *this;
     }   
     HTTPRequestBuilder& withHeader(const string& key, const string& value){
         req.headers[key]=value;
        return *this;
     }  
     HTTPRequest build(){
        if(req.url.empty()){
            throw runtime_error("url is empty");
        }
        return req;
     }
};

int main(){

    HTTPRequest request= HTTPRequestBuilder()
       .withUrl("https://www.example.com")
       .withMethod("GET")
       .withHeader("Content-Type","application.json")
       .build();
     
     request.execute();  
}