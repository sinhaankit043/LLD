#include "Payment.hpp"

/*
  Card Payment Implementation
*/
void CardPayment::pay(int amount) {
    if (amount > 0) {
        cout << "Amount of Rs " << amount
             << " is paid successfully through Card" << endl;
    }
}

/*
  UPI Payment Implementation
*/
void UPIPayment::pay(int amount) {
    if (amount > 0) {
        cout << "Amount of Rs " << amount
             << " is paid successfully through UPI" << endl;
    }
}

/*
  Payment Strategy Implementation
*/
PaymentStrategy::PaymentStrategy(PaymentType* paymentType) {
    this->paymentType = paymentType;
}

void PaymentStrategy::pay(int amount) {
    paymentType->pay(amount);
}