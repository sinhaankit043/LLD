// #pragma once
#include<iostream>
#include "Product.hpp"
using namespace std;

Product ::Product(string sku,int price,int quantity,int thresholdQty,ProductCategory category){
    this->sku=sku;
    this->price=price;
    this->quantity=quantity;
    this->thresholdQty=thresholdQty;
    this->category=category;

}

void Product::addStock(int quantity){
     this->quantity+=quantity;
}

void Product::removeStock(int quantity){
     this->quantity-=quantity;
}



Product* ProductFactory:: createProduct(string sku,int price,int quantity,int thresholdQty,ProductCategory category){
    return new Product(sku, price,quantity, thresholdQty, category);
}