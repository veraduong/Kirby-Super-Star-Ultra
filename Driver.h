// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3 

#ifndef DRIVER_H
#define DRIVER_H

#include <iostream> 
#include "KirbyBoss.h"
#include "Minion.h"
using namespace std; 

class Driver
{
    private:

        string items[5]; // items from text file
        int itemCost[5]; // cost from text file - Points will determine which items the user can buy
        int itemValue[5]; // Value that's added to Kirby's stats
        int itemValuePos; // Keeps track of where to add the value of the item in the item value array
        Minion minions[6]; // add to Kirby's stats from minions
        int points; // Points will be determined by the number of minions defeated
        
    public:

        Driver(); // constructor

        void setPoints(int pointValue); // set points
        int getPoints(); // get points

        int block(int defenseValue); // Kirby can block. Weakens the damage from an attack

        int kirbyAttackMinion();// Kirby can choose to strike or copy minion
        int kirbyAttackBoss(int attackValue);// Attack value will be assigned at random. Energy will be taken (Only for the boss)
        int copy(); // copy minion's ability
        bool kirbyDodge();// Whether kirby completely dodges an attack or not will be 50% chance

        int displayMenu(); // main menu display
        int visitStore(); // Reading from the storeFile and writing to the inventoryFile
        int buyItem(int points); // takes in points and item will be added to inventory
        void viewDescription(); // description of store item
        void viewInventory(); // Displays the items kirby has in his inventory
        void viewEnemy(string enemyFile); // Displays description of the enemy for each stage
        int activateItem(); // Type in item name to activate it and update stats

        int randomNumbers(int min, int max); // function generates random numbers
}; 

#endif