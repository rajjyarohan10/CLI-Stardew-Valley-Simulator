/*******************************************
 * File: Animal.cpp
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * E-mail: rajjyarohan@gmail.com
 *
 * This file contains the member functions for Animal Class
 ***********************************************/

#include "Animal.h"

// Animal() (Default Constructor)
// Uses AgItem default constructor, An animal (chicken) is created.
Animal::Animal() {
    m_name = "Chicken";
}


// Tick() [virtual]
// if farm has food, animal is automatically fed
void Animal::Tick(bool food) {

    // Sufficient Food
    if (food == true) {
        // Feeding the animal
        m_IsHungry = false; // already fed in Farm.cpp call
        SetSize(GetSize() + 1); // Incrementing Size
    }

    // Max Size
    if(GetSize() > ANIMAL_MAX_SIZE) {
        bool isHarv = true; // helper variable
        SetIsHarvestable(isHarv);

        // Harvest Function Call
        SetWorth(Harvest()); // returning value as the worth
    }

    // Animal not Fed (no Food)
    if(food == false) {
        // Size does not increase

        // If second no feed, is harvested
         if(m_IsHungry == true) { // This will run second time when animal is hungry

             // Setting Is Harvestable
             SetIsHarvestable(true);

             // Harvest Function Call
             SetWorth(Harvest()); // returning value as the worth (This overrides the worth)

         }

        // The Animal is Hungry
        m_IsHungry = true;

    }

}


// Harvest()
// IsHarvestable, Animal harvested and money is gained (worth * size)
int Animal::Harvest() {

    // Animal Harvest
    if(GetIsHarvestable() == true) { // When Harvestable

        // Printing output
        cout << "The Animal was Harvested" << endl;

        // Harvesting Animal
        // NOTE: on Tick () function

        // Fixing GetSize() if more than needed
        if(GetSize() > 3) {
            SetSize(3); // fixing size when overridden
        }

        // Gaining Money (worth * size) = 1 * size
        int newMoney = ( 1 * GetSize() ); // calculates to update new money with old
        return newMoney;

    }

    return 0; // To prevent warning flags

}


// GetType()
// None, Return string name of the subtype (Animal)
string Animal::GetType() {

    // Returning subtype
    if(GetSize() == 0) {
        // Born
        return ANIMAL_SIZE[0];
    }else if(GetSize() == 1) {
        // Infant
        return ANIMAL_SIZE[1];
    }else if(GetSize() == 2) {
        // Juvenile
        return ANIMAL_SIZE[2];
    }else if(GetSize() == 3) {
        // Adult
        return ANIMAL_SIZE[3];
    }else{
        // None
        return " ";
    }

}


// overloaded operator<<
// None, Returns output stream with this format
ostream& Animal::operator<<(ostream &output) {

    // Getting Status for Harvestable [Using Animal Size]
    string harStatus; // helper variable
    if(GetSize() == ANIMAL_MAX_SIZE) {
        // When the Animal is adult
        harStatus = "Harvestable";
    }else{
        harStatus = "Not Harvestable";
    }

    // Getting Status for Fed
    string fedStatus; // helper variable & initial value
    if(m_IsHungry == false) {
        // When fed
        fedStatus = "Fed";
    }else {
        // When not fed
        fedStatus = "Not Fed";
    }

    // Final Output
    output << "Animal" << CONCAT << m_name << CONCAT << harStatus << CONCAT << GetType()
           << CONCAT << fedStatus << endl;
    return output;


}

