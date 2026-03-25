#pragma once
#include<iostream>
#include "Warehouse.hpp"
using namespace std;



class InventoryManager{
    public:
    static InventoryManager* instance;
    vector<Warehouse*>warehouses;



    static InventoryManager*getInstance();
    void addWarehouse(Warehouse*warehouse);

    Product* getProductBySku(string sku);


};