#pragma once
#include<iostream>
#include "Product.hpp"
using namespace std;


class Warehouse{
    public:
    string id;
    unordered_map<string,Product*>mapSkuToProduct;

    Warehouse(string id);

    void addProduct(Product*product, int quantity);

    void removeProduct(Product*product, int quantity);

    Product*getProductBySku(string sku);

    
    
};
