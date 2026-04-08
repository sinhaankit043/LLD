#include<iostream>
using namespace std;


class IImage{
   public:

   virtual void display()=0;
};

class RealImage :public IImage{
    string filename;
     public:
     RealImage(string filename){
        this->filename=filename;
     }

     void display(){
        cout<<"Real Image is displaying  for  filename"<<filename<<endl;
     }

};


class ImageProxy:public IImage{
    public:
      RealImage*realImage;
      string filename;

      ImageProxy(string filename){
        this->filename=filename;
        realImage=nullptr;
      }

      void display(){
        //Lazy initializationdc 
        if(realImage==nullptr){
            realImage= new RealImage(filename);
        }
        realImage->display();
      }


};

int main(){
    IImage*image1= new ImageProxy("sample.jpg");
    image1->display();
}


/*


clang++ -std=c++17 virtualproxy.cpp -o virtualproxy && ./virtualproxy  
*/
