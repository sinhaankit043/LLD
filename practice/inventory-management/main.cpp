// #pragma once
#include<iostream>
#include"Product.hpp"
#include "Warehouse.hpp"
#include "InventoryManager.hpp"

using namespace std;

int main(){

   InventoryManager*inventoryManager= InventoryManager::getInstance();
   Warehouse*w1= new Warehouse("warehouse-1");
   Warehouse*w2= new Warehouse("warehouse-2");

   inventoryManager->addWarehouse(w1);
   inventoryManager->addWarehouse(w2);

   Product *laptop= ProductFactory::createProduct("Dell-123",500000,10,4,ProductCategory::Electronics);
   Product *tShirt= ProductFactory::createProduct("TS-101",500,4,2,ProductCategory::Clothing);

   w1->addProduct(laptop,5);
   w2->addProduct(tShirt,3);

   inventoryManager->getProductBySku("Dell-123");
   

    return 0;
}