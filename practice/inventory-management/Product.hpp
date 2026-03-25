#pragma once
#include<iostream>
using namespace std;

enum class ProductCategory{Electronics,Clothing,Groceries};

class Product{
    public:
    string sku;
    int price;
    int quantity;
    int thresholdQty;
    ProductCategory category;

    Product(string sku,int price,int quantity,int thresholdQty,ProductCategory category);
    
    void addStock(int quantity);
    void removeStock(int quantity);


};



class ProductFactory{
    public:
    static Product* createProduct(string sku,int price,int quantity,int thresholdQty,ProductCategory category);
};