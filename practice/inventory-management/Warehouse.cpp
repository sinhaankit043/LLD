// #pragma once
#include<iostream>
#include "Warehouse.hpp"
#include "Product.hpp"
using namespace std;

Warehouse::Warehouse(string id){
    this->id=id;
}

void Warehouse::addProduct(Product*product,int quantity){
     string sku=product->sku;
     if(mapSkuToProduct.find(sku)!=mapSkuToProduct.end()){
       Product* existingProduct=mapSkuToProduct[sku];
       existingProduct->addStock(quantity);
     }
     else{
        mapSkuToProduct[sku]=product;

     } 
}

void Warehouse::removeProduct(Product*product,int quantity){
     string sku=product->sku;
     if(mapSkuToProduct.find(sku)!=mapSkuToProduct.end()){
       Product* existingProduct=mapSkuToProduct[sku];
       if(existingProduct->quantity>=quantity){
            existingProduct->removeStock(quantity);
       }
       else{
        cout<<"Product quantiy not avaiable"<<endl;
       }
      
     }
     else{
       cout<<"No such product found with sku"<<product->sku<<"in the warehouse"<<endl;

     } 
}

Product*Warehouse:: getProductBySku(string sku){
    if(mapSkuToProduct.find(sku)!=mapSkuToProduct.end()){
        return  mapSkuToProduct[sku];
    }
    else return nullptr;
}

