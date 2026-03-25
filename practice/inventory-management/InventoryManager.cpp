// #pragma once
#include "InventoryManager.hpp"
#include<iostream>
using namespace std;

InventoryManager* InventoryManager:: instance=nullptr;

InventoryManager* InventoryManager::getInstance(){
     if(instance==nullptr){
        instance=new InventoryManager();
     }
     return instance;
}

void InventoryManager:: addWarehouse(Warehouse*warehouse){
    warehouses.push_back(warehouse);
}

Product*InventoryManager ::getProductBySku(string sku){
      for(auto warehouse:warehouses){
        Product*product=warehouse->getProductBySku(sku);
        if(product!=nullptr){
            cout<<"Product found in warehouse"<<warehouse->id<<endl;
            return product;
        }
      }
      cout<<"No such product is present in warehouse"<<endl;
      return nullptr;
}
