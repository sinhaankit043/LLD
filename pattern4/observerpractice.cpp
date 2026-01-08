#include<iostream>
#include<vector>
using namespace std;

class ISubscriber{
    public:
    virtual void update()=0;
};

class IChannel{
    public:
    virtual void subscribe(ISubscriber* subscriber)=0;
    virtual void unSubscribe(ISubscriber*subscribe)=0;
    virtual void notifyAll()=0;

};
class Channel : public IChannel{
    public:
    string name;
    string latestVideo;
    vector<ISubscriber*> subscribers;

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

    void uploadVideo(string title){
       this->latestVideo=title;
       notifyAll();
    }

    void notifyAll(){
        for(auto it:subscribers){
            it->update();
        }
    }
    void getVideoInfo(){
        cout<<"A new video is uploaded at"+this->name +"with title"+this->latestVideo<<endl;
    }

};

class Subscriber : public ISubscriber{
    public:
    string name;
    Channel*channel;
    
    Subscriber(string name,Channel*channel){
        this->name=name;
        this->channel=channel;
    }

    void update(){
       cout<<"Hey "+this->name ,channel->getVideoInfo();
    }
};


int main(){
    Channel*channel= new Channel("Learn LLD");
    Subscriber*s1= new Subscriber("Ankit",channel);
    Subscriber*s2= new Subscriber("Aman",channel);
    channel->subscribe(s1);
    channel->subscribe(s2);
    channel->uploadVideo("Oberser design pattern");
}