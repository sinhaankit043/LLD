package pattern1;

//defination
//Defines a family of algorithm(Talkable,Walkable ) , put them in separate classes so that they can be changed at runtime

interface Talkable{
    void talk();
}
class NormalTalk implements Talkable{
    public void talk(){
        System.out.println("Normal Talk");
    }
}
class StandardTalk implements Talkable{
    public void talk(){
        System.out.println("Standard Talk");
    }
}

interface Walkable{
    void walk();
}

class NormalWalk implements Walkable{
    public void walk(){
        System.out.println("Normal Walk");
    }
}
class StandardWalk implements Walkable{
    public void walk(){
        System.out.println("Standard Walk");
    }
}

 abstract class Robot{
    Talkable talkbehaviour;
    Walkable walkbehaviour;
    Robot(Talkable t, Walkable w){
        this.talkbehaviour=t;
        this.walkbehaviour=w;
    }
    void talk(){
        talkbehaviour.talk();
    }
    void walk(){
        walkbehaviour.walk();
    }
}

class CompanionRobot extends Robot{
    CompanionRobot(Talkable t, Walkable w){
        super(t,w);
    }
}



public class StrategyDesignPattern {
    public static void main(String[]args){
        System.out.println("hey");
        Robot r1= new CompanionRobot(new NormalTalk(), new StandardWalk());
        r1.walk();
        r1.talk();
    }
}
