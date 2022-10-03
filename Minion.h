// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3 

#ifndef MINION_H
#define MINION_H

#include <iostream> 
using namespace std; 

class Minion // Minion class for copying ability
{
    private: 

        int sword; //Increases atack value
        int shield; //Increases health 
        
    public: 

        Minion();
        
        void setShield(int shield_); // set shield
        int getShield(); // return shield

        void setSword(int sword_); // set sword
        int getSword(); // return sword
}; 

#endif