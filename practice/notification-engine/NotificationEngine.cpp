
#include<iostream>
using namespace std;



class INotification{
    public:
    virtual string getContent()=0;
    virtual ~ INotification(){};
};


class Notification:public INotification{

    private:
      string text;
    public:
  
    Notification(string msg){
        this->text=msg;
    }
    string getContent(){
        return this->text;
    }
};


//------------------------Decorator--------------------//


class INotificationDecorator:public INotification{
    public:
    INotification *notification;

    INotificationDecorator(INotification*notfication){
        this->notification=notfication;
    }

    virtual string getContent()=0;
    virtual ~INotificationDecorator(){}
};

class SignedNotification:public INotificationDecorator{

    public:
    SignedNotification(INotification*notification):INotificationDecorator(notification){}

    string getContent(){
        return notification->getContent()+"SIGNED_BY_AUTHORITY";
    } 
               
};


//---------------OBSERVER PATTERN----------------------------//


class IObserver{
   public:

   virtual void update()=0;
   virtual ~IObserver(){};
};

class IObservable{
    public:
    virtual void addObserver(IObserver*observer)=0;
    // virtual void removeObserver(IObserver*observer)=0;
    virtual void notifyObserver()=0;
    virtual ~IObservable(){};

};


//================CONCREATE OBSERVABLE=============



class NotificationObservable:public IObservable{

    private:
     vector<IObserver*>observers;
     INotification*currNotification;
    public:
   

    NotificationObservable(){
        this->currNotification=nullptr;
    }

    void addObserver(IObserver*observer){
        observers.push_back(observer);
    }

    void notifyObserver(){
        for(auto it:observers){
            it->update();
        }
    }

    void setNotification(INotification*notification){
        if(this->currNotification!=nullptr){
             delete currNotification;
        }
        this->currNotification=notification;
        notifyObserver();
        
      }

      string getContent(){
          return this->currNotification->getContent();
      }

       INotification* getNotification() {
        return this->currNotification;
    }

};


//=================================NOTIFICATION SERVICE =================================



class NotificationService{
     public:
     static NotificationService*instance;
     INotification*notification;
     NotificationObservable*observable;
     vector<INotification*>notifications;
     


     NotificationService(){
        this->observable=new NotificationObservable();
     }

     static NotificationService*getInstance(){
        if(instance==nullptr){
            instance = new NotificationService();
        }
        return instance;
     }

     void sendNotification(INotification*notification){
        notifications.push_back(notification);
        this->observable->setNotification(notification);
     }


};

NotificationService*NotificationService::instance=nullptr;


class INotificationStrategy{
    public:
    virtual void sendNotification(string msg)=0;
};

class SMSStrategy:public INotificationStrategy{
     public:
     string mobileNumber;

     SMSStrategy(string mNo){
        this->mobileNumber=mNo;
     }

     void sendNotification(string msg){
        cout<<"Message:"<< msg<<"is send to "<<mobileNumber<<"through sms"<<endl;
     }
};



//=============CONCREATE OBSERVER ======================

class NotificationEngine:public IObserver{
    public:
       NotificationObservable*notificationObservable;
       vector<INotificationStrategy*>notficationStrategies;

    NotificationEngine(){
        this->notificationObservable= NotificationService::getInstance()->observable;
         this->notificationObservable->addObserver(this);
    }



    void addNotificationStrategy(INotificationStrategy*strategy){
        this->notficationStrategies.push_back(strategy);
    }

    void update(){
        string msg= notificationObservable->getContent();
         for(auto strategy:notficationStrategies){
            strategy->sendNotification(msg);
         }
    }

};


int main(){
    INotification*notification= new Notification("Ordered delivered ");
    notification =new SignedNotification(notification);

    NotificationService*service = NotificationService::getInstance();

    NotificationEngine*notificationEngine= new NotificationEngine();

    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 987654321"));

    service->sendNotification(notification);

    return 0;
}











