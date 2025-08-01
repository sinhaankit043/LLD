#include<iostream>
#include<vector>
#include<string>
using namespace std;


class ISubscriber{
    public:
    virtual void update()=0;
};
class IChannel{
    public:
     virtual void subscribe(ISubscriber*subscriber)=0;
     virtual void unSubscribe(ISubscriber*subscriber)=0;
     virtual void notifySubscriber()=0;

};

class Channel : public IChannel{
    private:
      string name;
      string latestVideo;
      vector<ISubscriber*>subscribers;

      public:
       Channel(string name){
        this->name=name;
       }

       void subscribe(ISubscriber*subscriber){
         if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
            subscribers.push_back(subscriber);
         }
       }

        void unSubscribe(ISubscriber*subscriber){
            auto it=find(subscribers.begin(),subscribers.end(),subscriber);
            if(it!=subscribers.end()){
            subscribers.erase(it);
         }
       }
       void notifySubscriber(){
        for(auto it: subscribers){
            it->update();
        }
       }

       void uploadVideo(string title){
        this->latestVideo=title;
        notifySubscriber();
       }

       void getVideoInfo(){
        cout<<"video tile"<<this->latestVideo<<"is uploaded in channel"<<this->name<<endl;
       }
};

class Subscriber : public ISubscriber{
    private:
      string name;
      Channel* channel;
    
    public: 
      Subscriber(string name, Channel*channel){
        this->name=name;
        this->channel=channel;
      }  

      void update(){
        cout<<this->name<<"!.A new video is posted with ";
        channel->getVideoInfo();
      }
};

int main(){
    Channel *channel= new Channel("Low Level Design");
    ISubscriber*s1= new Subscriber("Ankit",channel);
    ISubscriber*s2= new Subscriber("Aman",channel);
    channel->subscribe(s1);
    channel->subscribe(s2);
    channel->uploadVideo("observer design pattern");
    channel->unSubscribe(s2);
    channel->uploadVideo("decorator design pattern");
    return 0;


}