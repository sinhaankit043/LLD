#include<iostream>
#include<vector>
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

class Channel:public IChannel{

    private:
    string name;
    vector<ISubscriber*>subscribers;
    string latestVideo;

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
        for(auto it:subscribers){
            it->update();
        }
    }

    void uploadVideo(string name){
         this->latestVideo=name;
         notifySubscriber();
    }

    void getLatestVideo(){
        cout<<"The recent video uploaded is "+this->latestVideo<<"by channel "+this->name<<endl;
    }

};


class Subscriber:public ISubscriber{
    private:
    string name;
    Channel*channel;
    public:

    Subscriber(string name, Channel*channel){
        this->name=name;
        this->channel=channel;
    }

    void update(){
        channel->getLatestVideo();
    }
};


int main(){
    Channel*channel=new Channel("LLD By Ankit");

    ISubscriber*subs1=new Subscriber("Ankit",channel);
     ISubscriber*subs2=new Subscriber("Aman",channel);
     channel->subscribe(subs1);
      channel->subscribe(subs2);

      channel->uploadVideo("Observer Pattern");







    return 0;

}




