package pattern2;

public class Singleton {
    private static Singleton instance=null;
    private Singleton(){
      System.out.println("singleton constructor called");
    }
  
    public static Singleton getInstance() {
        if (instance == null) {
            synchronized (Singleton.class) {
                if (instance == null) {
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
    public static void main(String[]args){
        Singleton s1=Singleton.getInstance();
        Singleton s2=Singleton.getInstance();
        System.out.println(s1==s2);
    }
}


