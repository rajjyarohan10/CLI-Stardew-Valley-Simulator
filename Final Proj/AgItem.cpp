/*******************************************
 * File: Aglterm.cpp
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * E-mail: rajjyarohan@gmail.com
 *
 * This file contains the member functions for Class Aglterm
 ***********************************************/


#include "AgItem.h"


// AgItem (Default constructor)
// Abstract class, Abstract class so used with child classes only
AgItem::AgItem() {
    m_size = 0;
    m_worth = 1; // AKA base worth
    m_isHarvestable = false;
}


// AgItem (Overloaded constructor)
// Abstract class, Abstract class so used with child classes only.
AgItem::AgItem(int size, int worth, bool IsHarvestable) {
    m_size = size;
    m_worth = worth;
    m_isHarvestable = IsHarvestable;
}


// ~AgItem [virtual]
// AgItem,Can be trivially implemented but required for subclass (tree)
AgItem::~AgItem() {}


// GetSize
// None, None
int AgItem::GetSize() {
    return m_size;
}


// GetWorth()
// None, None
int AgItem::GetWorth() {
    return m_worth;
}


// IsHarvestable()
// None, None
bool AgItem::GetIsHarvestable() {
    return m_isHarvestable;
}


// SetSize(int size)
// None, m_size is set
void AgItem::SetSize(int size) {
    m_size = size;
}


// Set IsHarvestable(int isAlive)
// None, m_isHarvestable is set
void AgItem::SetIsHarvestable(bool isAlive) {
    m_isHarvestable = isAlive;
}


// SetWorth(int worth)
// None, m_worth is set
void AgItem::SetWorth(int worth) {
    m_worth = worth;
}


// Tick (Purely Virtual)
// None, Implemented in child classes
void AgItem::Tick(bool) {
    // To be implemented in child class
}


// Harvest (Purely Virtual)
// None, Implemented in child classes
int AgItem::Harvest() {
    // To be implemented in child class
    return 0;
}


// GetType()
// None, Implemented in child classes
string AgItem::GetType() {
    return " EMPTY ";
}


// overloaded operator<< (Purely Virtual)
// None, Implemented in child class
ostream& AgItem::operator<< (ostream & os ) {
    os << "INSIDE! !\n";
    return os;
}






