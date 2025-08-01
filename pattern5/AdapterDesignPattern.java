package pattern5;
//Adaptee
class LegacyCode{
    public void getCustomerDataInfo(String id){
        System.out.println("customer data fetched for id "+id);
    }
}

//target interface
interface CustomerDataFetcher{
     void getCustomerData(String id,String name);
}


//Adapter
class LegacyCodeAdapter implements CustomerDataFetcher{
    LegacyCode legacyCode;
    LegacyCodeAdapter(LegacyCode legacy){
         this.legacyCode=legacy;
    }
    public void getCustomerData(String id, String name){
        legacyCode.getCustomerDataInfo(id);
    }
}

public class AdapterDesignPattern {
    public static void main(String []args){
        LegacyCodeAdapter l1=new LegacyCodeAdapter(new LegacyCode());
        l1.getCustomerData("123", "tata");
    }
    
}
