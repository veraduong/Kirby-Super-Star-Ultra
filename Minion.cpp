// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3

#include <iostream> 
#include "Minion.h"
using namespace std; 

Minion::Minion() // initialize to zero
{
    shield = 0;
    sword = 0;
}

void Minion::setShield(int shield_) // set shield
{
    shield = shield_;
}

int Minion::getShield() // return shield
{
    return shield;
}

void Minion::setSword(int sword_) // set sword
{
    sword = sword_;
}

int Minion::getSword() // return sword
{
    return sword;
}
