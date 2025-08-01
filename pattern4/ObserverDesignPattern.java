package pattern4;
import java.util.ArrayList;
import java.util.List;

interface ISubscriber{
    void update();
}
interface IChannel{
    void subscribe(ISubscriber subscriber);
    void unsubscribe(ISubscriber subscriber);
    void notifySubscriber();
}

class Channel implements IChannel{
    private List<ISubscriber>subscribers;
    private String name;
    private String latestVideo;
     
    Channel(String name){
      this.name=name;
      this.subscribers=new ArrayList<>();
    }
    public void subscribe(ISubscriber subscriber){
        if(!subscribers.contains(subscriber)){
            subscribers.add(subscriber);
        }

    }
    public void unsubscribe(ISubscriber subscriber){
          if(subscribers.contains(subscriber)){
            subscribers.remove(subscriber);
        }

    }
    public void notifySubscriber(){
        for(ISubscriber sub:subscribers){
            sub.update();
        }
    }
    public void uploadVideo(String title){
        this.latestVideo=title;
        notifySubscriber();
    }
    public String getVideo(){
        return "latest video "+latestVideo+" uploaded by"+name;
    }
}

class Subscriber implements ISubscriber{
    private String name;
    private Channel channel;
    public Subscriber(String name,Channel channel){
        this.name=name;
        this.channel=channel;
    }
    public void update(){
      System.out.println("hey"+name+"please checkout"+channel.getVideo());
    }

}


public class ObserverDesignPattern {
    public static void main(String[] args) {
        Channel channel = new Channel("LLD Tutorial");
        Subscriber s1 = new Subscriber("Ankit", channel);
        Subscriber s2 = new Subscriber("Aman", channel);
        Subscriber s3 = new Subscriber("Piyush", channel);
        channel.subscribe(s1);
        channel.subscribe(s2);
        channel.subscribe(s3);

        channel.uploadVideo("Observer Design Pattern");
        channel.unsubscribe(s3);
        channel.uploadVideo("Decorator Design Pattern");

    }
}
