package pattern3;

interface Burger{
    void prepare();   
}
class NormalBurger implements Burger{
    public void prepare(){
        System.out.println("normal burger prepared");
    }
}

class ClassicBurger implements Burger{
    public void prepare(){
        System.out.println("classic burger prepared");
    }
}
class NormalWheatBurger implements Burger{
    public void prepare(){
        System.out.println("normal wheat burger prepared");
    }
}

class ClassicWheatBurger implements Burger{
    public void prepare(){
        System.out.println("classic wheat burger prepared");
    }
}
interface BurgerFactory{
    Burger createBurger(String type);
}

class SinghBurger implements BurgerFactory{
   public  Burger createBurger (String type){
        if(type.equalsIgnoreCase("basic")){
            return new NormalBurger();
        }
        else if(type.equalsIgnoreCase("classic")){
            return new ClassicBurger();
        }
        else{
            return null;
        }
    }
}
class KingBurger implements BurgerFactory{
   public  Burger createBurger (String type){
        if(type.equalsIgnoreCase("basic")){
            return new NormalWheatBurger();
        }
        else if(type.equalsIgnoreCase("classic")){
            return new ClassicWheatBurger();
        }
        else{
            return null;
        }
    }
}
public class FactoryPattern {
    public static void main(String[]args){
        String type="classic";
        BurgerFactory myFactory= new SinghBurger();
        Burger burger=myFactory.createBurger(type);
        BurgerFactory myFactory2=new KingBurger();
        Burger burger2=myFactory2.createBurger(type);


        burger.prepare();
        burger2.prepare();

    }
}
