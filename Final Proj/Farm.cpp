/*******************************************
 * File: Farm.cpp
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * Section: 10/14
 * E-mail: rajjyarohan@gmail.com
 *
 * This file contains the member functions for Class Farm
 ***********************************************/


#include "Farm.h"


// Farm (Default Constructor)
// None, A farm is created
Farm::Farm() { // starting value
    m_food = 6;
    m_money = 0;
    m_season = 1;
}


// ~Farm()
// The farm is cleared out
Farm::~Farm() { // Deallocating Dynamic Memory

    AgItem *deletePtr = nullptr; // newPtr
    for (unsigned int i = 0; i < m_farm.size(); ++i) {
        deletePtr = m_farm.at(i);
        delete deletePtr; // deleting
    }
    m_farm.resize(0); // resizing the vector

}


// ChooseItem()
// None, returns 1 (animal), 2 (vegetable), or 3 (tree) (reprompts for anything else)
int Farm::ChooseItem() {

    // Input Validation
    bool validInput = false;
    while(validInput != true) {

        // Asking userInput
        cout << "Which agricultural item are you interested in?" << endl;
        cout << "1. Animal" << endl;
        cout << "2. Vegetable" << endl;
        cout << "3. Tree" << endl;
        int agItem;
        cin >> agItem;
        cout << endl;

        // Checking Input
        if(agItem == 1 || agItem == 2 || agItem == 3) {
            validInput = true;
            return agItem; // returns users choice
        }else{
            cout << "Invalid Input, Try Again!" << endl;
        }

    }
    return 0; // Protecting against Warning!
}


// AddItem(int type, int quantity)
// None, Adds 1 (animal), 2 (vegetable), or 3 (tree) to m_farm
void Farm::AddItem(int type, int quantity) {

    // Checking passed type
    if(type == 1) { // Animal

        // Loop to run quantity times
        for (int i = 0; i < quantity; ++i) {

            // Creating Animal and populating m_farm
            Animal *animalPtr = new Animal();
            m_farm.push_back(animalPtr);
            cout << "New Animal added to the farm.\n" << endl;

        }

    }else if(type == 2) { // Vegetable

        // Loop to run quantity times
        for (int i = 0; i < quantity; ++i) {

            // Creating Vegetable and populating m_farm
            Vegetable *vegPtr = new Vegetable();
            m_farm.push_back(vegPtr);
            cout << "New Vegetable added to the farm.\n" << endl;

        }

    }else if(type == 3) { // Tree

        // Loop to run quantity times
        for (int i = 0; i < quantity; ++i) {

            // Creating Tree and populating m_farm
            Tree *treePtr = new Tree();
            m_farm.push_back(treePtr);
            cout << "New Tree added to the farm.\n" << endl;

        }

    }

}


// Tick (int season)
// None, Time passes
void Farm::Tick(int time) { // Simulate Time

    // SEASONS RUN
    for (int index = 1; index <= time; ++index) {

        // Printing Season
        cout << "Seasons: " << index << endl;

        // Incrementing m_seasons
        m_season = m_season + 1;

        /// 1. Calling Tick for each item in m_farm
        // Loop to call respective Child Classes
        bool foodBool = false; // helper variable
        for (unsigned int i = 0; i < m_farm.size(); ++i) {

            // Checking if the Item is Animal
            int intANIMAL = 0; // helper count
            if((m_farm.at(i)->GetType() == "Born") || (m_farm.at(i)->GetType() == "Infant") || (m_farm.at(i)->GetType() == "Juvenile")
                || (m_farm.at(i)->GetType() == "Adult"))
            {
                // Incrementing when CHICKEN
                cout << m_farm.at(i)->GetType() << endl; // OUT HERE!
                intANIMAL++;
            }


            // Checking if the Item is Vegetable
            int intVEG = 0; // helper count
            if((m_farm.at(i)->GetType() == "Seedling") || (m_farm.at(i)->GetType() == "Medium")
                || (m_farm.at(i)->GetType() == "Fully Mature"))
            {
                // Incrementing when VEGETABLE
                intVEG++;
            }


            // Checking if the Item is Tree
            int intTree = 0; // helper count
            if((m_farm.at(i)->GetType() == "Seedling") || (m_farm.at(i)->GetType() == "Sapling")
                || (m_farm.at(i)->GetType() == "Pole") || (m_farm.at(i)->GetType() == "Mature"))
            {
                // Incrementing when TREE
                intTree++;
            }



            // ANIMAL ITEM
            if(intANIMAL != 0) {

                // Checking if the FARM has enough food
                if(m_food > 0) {
                    foodBool = true; // sending true for sufficient food
                    m_food--; // Animal is Fed
                }else{
                    foodBool = false; // no food
                }

            }

            // VEGETABLE ITEM
            if(intVEG != 0) {

                // Vegetable fed's itself
                foodBool = true;

            }

            // TREE ITEM
            if(intTree != 0) {

                // Tree fed's itself
                foodBool = true;

            }

            // Respective Child Class Function Call
            m_farm.at(i)->Tick(foodBool);

            // Adding Fruits when Trees become Mature
            // Identifying Tree
            if(intTree != 0) {
                // Increasing Food for Fruits
                if((m_farm.at(i)->GetIsHarvestable() == false) && (m_farm.at(i)->GetSize() != 0)) {
                    // When Tree is not old and is capable of producing fruits

                    // Adding 1 Fruit to m_food
                    m_food++;
                }
            }

            /// HARVESTING
            // Increasing Money from selling and HARVESTING
            if(m_farm.at(i)->GetIsHarvestable() == true) { // checking if it is harvested already

                // Identifying Animal
                if(intANIMAL != 0) {
                    // Increasing Funds for Animal
                    m_money = m_money + m_farm.at(i)->GetWorth(); // adding the profit
                }


                // Identifying Vegetable
                if(intVEG != 0) {
                    // Increasing Food for Vegetable
                    m_food = m_food + m_farm.at(i)->GetSize(); // adding food
                }


                /// 3. Removes anything harvested from m_farm

                // Harvesting (Removing from Farm)
                delete m_farm.at(i); // deleting memory
                m_farm.erase(m_farm.begin() + i); // erasing

            }

        }

        /// 4. Displaying the status automatically
        cout << endl;
        Status(); // calling status to display

    }


}


// Menu()
// None, If returns 5 quits
int Farm::Menu() {
    // Menu Function

    cout << "1. Add Item to raw" << endl;
    cout << "2. Add Two of Each Item to Farm" << endl;
    cout << "3. Simulate Time" << endl;
    cout << "4. Farm Status" << endl;
    cout << "5. Quit" << endl;
    int userInput;
    cin >> userInput;
    cout << endl;

    // Decision Making Branch
    if(userInput == 1) { // AddItem

        // AddItem Function Call and ChooseItem() for more options
        AddItem(ChooseItem(), 1); // (type, quantity)
        return 1; // keeping the menu running

    }else if(userInput == 2) { // Add Two of Each Item to Farm

        // Call AddItem to add 2 Items each
        for (int i = 0; i < 3; ++i) { // loop to add
            AddItem((i+1), 2); // (i+1) to fix input to AddItem, 2 quantity each
        }

        return 2; // keeping the menu running

    }else if(userInput == 3) { // Simulate Time

        // Asking time simulation value
        cout << "How many seasons to simulate?\n"; int simTime;
        cin >> simTime;
        // Call Tick()
        Tick(simTime); // passing user's input

        return 3; // keeping the menu running

    }else if(userInput == 4) { // Farm Status

        // Call Status()
        Status();

        return 4; // keeping the menu running
    }else if(userInput == 5) {
        // EXIT!
        return 5; // keeping the menu running
    }else{
        cout << "Invalid Input, only input 1-5 are allowed.\n" << endl;
        return 0;
    }

}


// StartSimulation()
// Displays welcome message, As long as meny doesn't return 5, keeps running
void Farm::StartSimulation() {
    // Displays MENU
    cout << "\nWelcome to Stardew Valley Simulator\n";

    // Menu Function Call
    while (Menu() != 5);
    cout << "Thank you for simulating Stardew Valley!" << endl;
}


// Status()
// None, Displays farm data
void Farm::Status() {

    //  Displaying Farm Data
    cout << "**** Farm Status ****"<< endl;
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl;
    cout << "Agricultural Items: " << endl;

    // When m_farm size = 0
    if(m_farm.size() == 0) {
        cout << "None\n" << endl;
    }

    // Iterating over m_farm
    for (unsigned int i = 0; i < m_farm.size(); ++i) {

        // Calling Overloaded Operator Child Classes
        (*m_farm.at(i)) << cout;

    }
    cout << endl; // spaces for better aesthetics

}
