// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3 

#ifndef KIRBYBOSS_H
#define KIRBYBOSS_H

#include <iostream> 
#include "Minion.h"
using namespace std; 

class KirbyBoss // this class will be used for both Kirby and the Boss
{
    private: 

        int health;
        int attackValue;
        int defenseValue;
        int energy; 
        
    public: 

        KirbyBoss(); // constructor

        int randomNumbers(int min, int max); // rand numbers function

        void setHealth(int health_); // Kirby's Health
        int getHealth();

        void setAttackValue(int attackValue_); // Kirby's Attack 
        int getAttackValue();

        void setDefenseValue(int defenseValue_); // Kirby's Defense
        int getDefenseValue();

        void setEnergy(int energy_); // Kirby's Energy
        int getEnergy();

        void displayKirbyStats(); //Displays kirby's health and energy 
        void displayBossStats(string bossName);

        int bossAttack(int attackValue); // The attack value and defense value will be picked at random
}; 

#endif