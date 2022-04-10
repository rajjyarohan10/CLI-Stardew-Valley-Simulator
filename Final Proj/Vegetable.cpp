/*******************************************
 * File: Vegetable.cpp
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * E-mail: rajjyarohan@gmail.com
 *
 * This file contains the member functions for Vegetable Class
 ***********************************************/

#include "Vegetable.h"

// Vegetable
// Uses AgItem default constructor, A vegetable is created.
Vegetable::Vegetable() {

    // Uses AgItem default constructor

}


// Harvest
// IsHarvestable, Returns integer size of vegetable for food
int Vegetable::Harvest() {

    // Printing output
    cout << "The Vegetable was Harvested\n";

    // Harvesting Vegetable
    // NOTE: on Tick() function

    // Returning Size to increment food
    return GetSize();
}


// Tick
// Vegetable either grows or becomes harvestable
void Vegetable::Tick(bool) {

    // Checking Vegetable Size
    if(GetSize() >= MAX_VEG_SIZE) {

        // MAX Size Reached
        bool isHarv = true; // variable to pass
        SetIsHarvestable(isHarv);

        // Harvest Function Call
        SetWorth(Harvest()); // returning the size of harvested food


    }else{

        // Still Growing
        SetSize(GetSize() + 1); // Incrementing size

    }


}


// GetType
// None, Returns string name of subtype (Vegetable)
string Vegetable::GetType() {

    // Returning subtype (Vegetable)
    if(GetSize()  == 0) { // using -1 to fix index
        // Seedling
        return Veg_Size[0];

    }else if(GetSize() == 1) {
        // Medium
        return Veg_Size[1];

    }else if(GetSize() == 2) {
        // Fully Mature
        return Veg_Size[2];

    }

    return " "; // Preventing warnings from compiler
}


// overloaded operator<< [virtual]
// None, Returns output stream with this format
//                  Vegetable | Not Harvestable | Seedling
ostream& Vegetable::operator<<(ostream &output) {

    // Getting Status for Harvestable [Using Vegetable Size]
    string harStatus; // helper variable
    if(GetSize() == MAX_VEG_SIZE) {
        harStatus = "Harvestable";
    }else{
        harStatus = "Not Harvestable";
    }

    // Printing Status
    output << "Vegetable" << CONCAT << harStatus << CONCAT << GetType() << endl;
    return output;

}
