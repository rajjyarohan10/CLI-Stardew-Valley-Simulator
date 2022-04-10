/*******************************************
 * File: Fruit.h
 * Author: Rajjya Rohan Paudyal
 * Date: 04/01/2021
 * E-mail: rajjyarohan@gmail.com
 *
 * Fruit Class manages Fruits 
 ***********************************************/

#ifndef FRUIT_H
#define FRUIT_H
#include <string>
using namespace std;

class Fruit {
public:
    
  // Name: Fruit
  // Desc: Creates a fruit with a color
  // Preconditions:  None
  // Postconditions: A fruit is created that is red (cannot access the color anyway)
  Fruit();
    
private:
  string m_color;
};

#endif
