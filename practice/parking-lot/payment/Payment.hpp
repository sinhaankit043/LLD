#pragma once
#include <iostream>
using namespace std;

/*
  Payment Strategy Interface
*/
class PaymentType {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentType() {}
};

/*
  Concrete Payment Types
*/
class CardPayment : public PaymentType {
public:
    void pay(int amount) override;
};

class UPIPayment : public PaymentType {
public:
    void pay(int amount) override;
};

/*
  Payment Strategy (Composition)
*/
class PaymentStrategy {
private:
    PaymentType* paymentType;

public:
    PaymentStrategy(PaymentType* paymentType);

    void pay(int amount);
};