// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3

#include <iostream> 
#include <ctime>
#include "KirbyBoss.h"
using namespace std; 

KirbyBoss::KirbyBoss() // starting stats
{
    health = 100;
    attackValue = 25;
    defenseValue = 25;
    energy = 100;
}

int KirbyBoss :: randomNumbers(int min, int max) // generate random numbers
{
    return (rand() % (max-min+1)) + min;;
}

void KirbyBoss::setHealth(int health_) // set Health
{
    health = health_;
}

int KirbyBoss::getHealth() // return health
{
    return health;
}

void KirbyBoss::setAttackValue(int attackValue_) // set Attack
{
    attackValue = attackValue_;
}
int KirbyBoss :: getAttackValue() // return attack
{
    return attackValue;
}

void KirbyBoss :: setDefenseValue(int defenseValue_) // set Defense val
{
    defenseValue = defenseValue_;
}

int KirbyBoss::getDefenseValue() // return defense val
{
    return defenseValue;
}

void KirbyBoss :: setEnergy(int energy_) // set Energy
{
    energy = energy_;
}
int KirbyBoss :: getEnergy() // return energy
{
    return energy;
}

void KirbyBoss :: displayKirbyStats() // call energy and health funct to display Kirby stats
{
    cout << "---Kirby---" << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Energy: " << getEnergy() << endl;
}

void KirbyBoss :: displayBossStats(string bossName) // call health funct to display Boss stats
{
    cout << "---" << bossName << "---" << endl;
    cout << "Health: " << getHealth() << endl;
}

int KirbyBoss :: bossAttack(int attackValue) // generate random attack value
{
    cout << "The boss will take a turn." << endl;
    srand(time(0));
    int bAttack_ = randomNumbers(1,attackValue);
    return bAttack_;
}