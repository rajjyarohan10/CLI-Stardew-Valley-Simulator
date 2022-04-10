/*******************************************
 * File: Tree.cpp
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * E-mail: rajjyarohan@gmail.com
 *
 * This file contains the member functions for Class Tree
 ***********************************************/


#include "Tree.h"


// Tree() (Default Constructor)
// Uses AgItem default constructor, A tree is created
Tree::Tree() {
    // Uses AgItem default constructor
    m_age = 0; // from header
}


// ~Tree()
// Tree exists, All fruit is purged from tree
Tree::~Tree() {

    Fruit *deletePtr = nullptr; // helper pointer
    for (unsigned int i = 0; i < m_fruit.size(); ++i) {
        // Deallocating
        deletePtr = m_fruit.at(i);
        delete deletePtr;
    }
    m_fruit.resize(0); // resizing vector

}


// Tick(bool)
// Tree exists, Returns amount of fruit harvested each season
void Tree::Tick(bool food) {

    // Tree is not Mature yet and ages
    if(GetType() != TREE_SIZE[3]) {
        // Incrementing m_age in seasons
        m_age++;
    }

    // Tree is older than 12 and grows a one fruit a season
    if(GetType() != TREE_SIZE[0]) {
        // Incrementing m_age in seasons
        m_age++;

        // Growing fruit
        Fruit *fruitPtr = new Fruit(); // dynamically allocating
        m_fruit.push_back(fruitPtr); // populating vector
        cout << "New fruit added.\n" << endl;
    }

    // Tree is 60 seasons old and is cut down (IsHarvestable)
    if(GetIsHarvestable() == true) {
        // Harvest Function Call
        Harvest();

        // Adding 1 last fruit to m_fruit
        Fruit *fruitPtr = new Fruit(); // dynamically allocating
        m_fruit.push_back(fruitPtr); // populating vector
        cout << "Last fruit from an old tree added.\n" << endl;

    }


}


// Harvest() [virtual]
// Tree exists, Fruit is returned(1 farm food) or dead tree(0 worth and 0 farm food)
int Tree::Harvest() {

    // Harvesting for 1 fruit
    return 1;

}


// GetType() [virtual]
// None, Returns string name of the subtype(Tree)
string Tree::GetType() {

    // Returning Subtype [age in months]
    if(m_age <= SEASONS_TO_FRUIT) {
        // Seedling
        return TREE_SIZE[0];

    }else if((m_age > 12) && (m_age <= 24 )) {
        // Sapling
        SetSize(1);
        return TREE_SIZE[1];

    }else if((m_age > 24) && (m_age <= 36)) {
        // Pole
        SetSize(2);
        return TREE_SIZE[2];

    }else if(m_age >= 36) {
        // Mature
        SetSize(3);
        return TREE_SIZE[3];
    }

    return " "; // to prevent flags
}


// overloaded operator<<
// Returns output stream with this format:
//                                          Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count: 0
ostream& Tree::operator<< (ostream &output) {

    // Getting Status for Harvestable [Using Tree Size]
    string harStatus; // helper variable
    if(m_age >= SEASONS_TO_HARVEST) {
        harStatus = "Harvestable";
        bool helpBool = true;
        SetIsHarvestable(helpBool); // flipping bool
    }else{
        harStatus = "Not Harvestable";
    }

    // Getting Status for Fruiting [Using Tree Size]
    string fruitStat; // helper variable
    if(m_age >= 12) {
        fruitStat = "Fruiting";
    }else{
        fruitStat = "Not Fruiting";
    }

    // Getting Status for Fruit Count
    int count = 0;
    if(m_fruit.size() != 0) {
        count = m_fruit.size();
    }

    // Printing Status
    output << "Tree" << CONCAT << GetType() << CONCAT << harStatus << CONCAT << fruitStat << CONCAT << "Fruit Count: "
            << count << endl;
    return output;

}