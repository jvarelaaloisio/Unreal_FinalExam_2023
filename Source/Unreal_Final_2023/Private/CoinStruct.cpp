#include "CoinStruct.h"

FCoinStruct::FCoinStruct()
    : Quantity(0)
{}

void FCoinStruct::Add(int Qty) {
    Quantity += Qty;
}

void FCoinStruct::SetQuantity(int newValue) {
    Quantity = newValue;
}