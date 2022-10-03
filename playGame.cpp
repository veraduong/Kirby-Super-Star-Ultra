// CSCI 1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 8am - Telly Umada
// Project 3 - PlayGame

#include <iostream>
#include <ctime>
#include <string>
#include "KirbyBoss.h"
#include "Minion.h"
#include "Driver.h"

using namespace std;

int main()
{
    // Declares all the variables to be used in the game. 
    Driver driver;
    KirbyBoss kirby; 
    KirbyBoss whispy;
    KirbyBoss dedede;
    
    // Display's the story behind the game. 
    cout << "There’s trouble in Dreamland! The gluttonous King Dedede and his minions have stolen ALL the food in Dreamland!" << endl;
    cout << "Here comes our hero, riding in on the spring breeze. Some call him… Kirby. Let the adventure begin!" << endl;
    cout << endl;

    // Asks the user if they want to start the game
    cout << "Do you want to start the game? Enter Y or N" << endl;
    char answer;
    cin >> answer;

    // If the user chooses n or N, the game stops running. 
    if (answer == 'N' || answer == 'n')
    {
        cout << "Good bye!" << endl;
        return 0;
    }

    // Starts stage 1 as kirby encounters his first minion
    cout << "----Stage 1: Green Greens----" << endl;
    cout << "Kirby has encountered a minion called Sir Kibble!" << endl;
    cout << endl;
    cout << "Kirby must defeat minions before he gets to the boss... earn points by defeating minions, and you can use those points to buy items!" << endl;
    cout << "Kirby can attack minions by striking or copying..." << endl;
    // Explains what each of the actions kirby can take against a minion. 
    cout << "-Strike- is a basic attack and gives you +2 points. These points can be used to buy items in the store." << endl;
    cout << "-Copy- allows Kirby to swallow a minion and copy their power and gives you +1 points" << endl;
    cout << endl;

    // Kirby encounters his first minion. 
    int result01 = driver.kirbyAttackMinion();
    if(result01 == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the first minion! (+2 pts)" << endl;
    }
    else if(result01 == 2)
    {
        kirby.setHealth(kirby.getHealth() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the first minion and copied their power! Now he has increased health. (+1 pt)" << endl;
    }
    
    // Kirby encounters his second minion
    cout << "Kirby has encountered a second minion!" << endl;
    int result02 = driver.kirbyAttackMinion();
    if(result02 == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the second minion! (+2 pts)" << endl;
    }
    else if (result02 == 2)
    {
        kirby.setHealth(kirby.getHealth() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the second minion and copied their power! Now he has increased health. (+1 pt)" << endl;
    }
    
    // Kirby encounters his third minion.
    cout << "Kirby has encountered a third minion!" << endl;
    int result03 = driver.kirbyAttackMinion();
    if(result03 == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the last minion! (+2 pts)" << endl;
    }
    else if (result03 == 2)
    {
        kirby.setHealth(kirby.getHealth() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the last minion and copied their power! Now he has increased health. (+1 pt)" << endl;
    }

    // displays Kirby's current stats after defeating minions and he then meets the boss
    cout << endl;
    kirby.displayKirbyStats();
    cout << "Points: " << driver.getPoints() << endl;
    cout << endl;
    cout << "Kirby has reached the boss Whispy Woods!" << endl;
    cout << endl;
    cout << "Kirby can defend himself by dodging or blocking..." << endl;
    cout << "Blocking decreases the boss's attack power and gives you +2 points." << endl;
    cout << "Dodging gives Kirby a 50% chance of avoiding it completely and gives you +1 points." << endl;
    cout << endl;
    cout << "Whispy Woods has started attacking and is throwing apples at Kirby!" << endl;
    
    // Declares variables to be used when kirby fights the boss.
    int kDamage;
    int wDamage;
    
    while (kirby.getHealth() > 0 && whispy.getHealth() > 0) // Kirby keeps fighting boss while both health > 0
    {
        switch (driver.displayMenu())
        {        
            case 1: // option 1: Attack. After kirby attacks, the boss will take a turn. Boss attack value is random between 1-25
            {
                kDamage = driver.kirbyAttackBoss(kirby.getAttackValue() );
                whispy.setHealth(whispy.getHealth() - kDamage);
                kirby.setEnergy(kirby.getEnergy() - 10);
                
                if (whispy.getHealth() != 0)
                {
                    wDamage = whispy.bossAttack(whispy.getAttackValue());
                    cout << "Kirby has taken " << wDamage << " damage." << endl;
                    kirby.setHealth(kirby.getHealth() - wDamage);
                }

                if (kirby.getHealth() > 0 && whispy.getHealth() > 0) // stats
                {
                    kirby.displayKirbyStats();
                    cout << "Points: " << driver.getPoints() << endl;
                    whispy.displayBossStats("Whispy");
                }
                break;
            }
            case 2: // option 2: Defend. After kirby chooses to block, the boss will take a turn. 
            {
                cout << "Do you want to..." << endl;
                cout << "1. Block" << endl;
                cout << "2. Dodge" << endl;
                int choice1;
                cin >> choice1;
                
                if (choice1 == 1) // block will lessen the attack damage of the boss
                {
                    wDamage = whispy.bossAttack(whispy.getAttackValue()) - driver.block(kirby.getDefenseValue());
                    if (wDamage < 0)
                    {
                        wDamage = 0;
                    }
                    cout << "Kirby has taken " << wDamage << " damage." << endl;
                    kirby.setHealth(kirby.getHealth() - wDamage);
                    driver.setPoints(driver.getPoints() + 2);
                    cout << "You have earned +2 points for blocking." << endl;
                    if (kirby.getHealth() > 0 && whispy.getHealth() > 0) // stats
                    {
                        kirby.displayKirbyStats();
                        cout << "Points: " << driver.getPoints() << endl;
                        whispy.displayBossStats("Whispy");
                    }
                }
                else if (choice1 == 2) // dodge will be a 50% chance of avoiding attack entirely
                {
                    if (driver.kirbyDodge() == true)
                    {
                        cout << "Kirby has dodged the attack. Kirby takes 0 damage." << endl;
                    }
                    else
                    {
                        wDamage = whispy.bossAttack(whispy.getAttackValue());
                        kirby.setHealth(kirby.getHealth() - wDamage);
                        cout << "Kirby could not dodge the attack. Kirby took " << wDamage << " damage." << endl;
                    }

                    driver.setPoints(driver.getPoints() + 1);
                    cout << "You have earned +1 points for dodging." << endl;

                    if (kirby.getHealth() > 0 && whispy.getHealth() > 0) // stats
                    {
                        kirby.displayKirbyStats();
                        cout << "Points: " << driver.getPoints() << endl;
                        whispy.displayBossStats("Whispy");
                    }            
                }
                break;
            }
            case 3: // Visit the store. In the store, kirby can choose to view a description, buy an item, or activate an item.
            {
                cout << "If Kirby buys an item, make sure you activate it or else you won't get a bonus in your stats!" << endl;
                int result = driver.visitStore();
                if (result == 1) // view description of item
                {
                    driver.viewDescription();
                }
                else if (result == 2) // purchase and item
                {
                    int result2 = driver.buyItem(driver.getPoints());
                    driver.setPoints(driver.getPoints() - result2);
                }
                else if(result == 3) // activate item will add values from item to Kirby's stats
                {
                    int result3 = driver.activateItem();

                    if(result3 == 5)
                    {
                        kirby.setEnergy(result3 + kirby.getEnergy());                      
                    }
                    else if(result3 == 10)
                    {
                        kirby.setDefenseValue(result3 + kirby.getDefenseValue());
                    }
                    else if(result3 == 15)
                    {
                        kirby.setAttackValue(result3 + kirby.getAttackValue());
                    }
                    else if(result3 == 20)
                    {
                        kirby.setHealth(result3 + kirby.getHealth());
                    }  
                    else if(result3 == 25)
                    {
                        kirby.setAttackValue(result3 + kirby.getAttackValue());
                        kirby.setHealth(result3 + kirby.getHealth());
                    }                  
                }
                break;
            }
            case 4: // Displays a description of the enemy from text file
            {
                driver.viewEnemy("whispy.txt");
                break;
            }
            case 5: // view inventory from text file 
            {
                driver.viewInventory();
                break;
            }
            case 6: // quit option
            {
                cout << "Good Bye!" << endl;
                return 0;
            }
            default: // The user cannot choose a number other than 1 - 6
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }

    if (kirby.getHealth() <= 0) // lose game when Kirby dies
    {
        cout << "Oh no! You lost. Sad times." << endl;
        return 0;
    }
    else if (kirby.getEnergy() <= 0) // can't fight more if you're out of energy
    {
        cout << "Oh no! You're out of energy." << endl;
        return 0;
    }
    else if (kirby.getHealth() <= 0 && whispy.getHealth() <= 0) // tie when Kirby and boss reach 0 health or below at the same time 
    {
        cout << "It's a tie! Play again so Kirby can defeat the Boss!" << endl;
        return 0;
    }
    else if (whispy.getHealth() <= 0) // Kirby defeats Whispy Woods, so he can move on to stage 2
    {
        cout << endl;
        cout << "Yay! You defeated Whispy Woods!" << endl;
        cout << "Kirby has made it to the Stage 2: Mt. Dedede." << endl;
    }
    
    //-------------------------------------------------------[STAGE 2]-----------------------------------------------------------------
    
    // Resets Kirby's stats for the second stage of the game. 
    kirby.setHealth(100);
    kirby.setEnergy(100);
    dedede.setAttackValue(35); // boss attack value set higher
    dedede.setHealth(200); // boss health is 200 instead of 100
    
    // Asks the user if they want to start the final stage.
    cout << endl;
    cout << "Do you want to start the final stage? Enter Y or N" << endl;
    cin >> answer;

    if (answer == 'N' || answer == 'n')
    {
        cout << "Good bye!" << endl;
        return 0;
    }

    // Stage 2 starts here and Kirby encounters the 3 minions
    // Must reactivate items from stage 1 (if there were any)

    cout << "----Stage 2: Mt. Dedede----" << endl;
    cout << endl;
    cout << "Make sure you reactivate the items in your inventory if you bought it in stage 1." << endl;
    cout << endl;
    // Kirby encounters his first minion
    cout << "Kirby has encountered a minion called Waddle Doo!" << endl;
    if(driver.kirbyAttackMinion() == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the first minion! (+2 pts)" << endl;
    }
    else
    {
        kirby.setAttackValue(kirby.getAttackValue() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the first minion and copied their power! Now he has increased Attack Power. (+1 pt)" << endl;
    }
    
    // Kirby encounters his second minion
    cout << "Kirby has encountered a second minion!" << endl;
    if(driver.kirbyAttackMinion() == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the second minion! (+2 pts)" << endl;
    }
    else
    {
        kirby.setAttackValue(kirby.getAttackValue() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the second minion and copied their power! Now he has increased Attack Power. (+1 pt)" << endl;
    }
    
    // Kirby encounters his third minion
    cout << "Kirby has encountered a third minion!" << endl;
    if(driver.kirbyAttackMinion() == 1)
    {
        driver.setPoints(driver.getPoints() + 2);
        cout << "Kirby has defeated the last minion! (+2 pts)" << endl;
    }
    else
    {
        kirby.setAttackValue(kirby.getAttackValue() + driver.copy());
        driver.setPoints(driver.getPoints() + 1);
        cout << "Kirby has defeated the last minion and copied their power! Now he has increased Attack Power. (+1 pt)" << endl;
    }

    // display stats after defeating minions
    cout << endl;
    kirby.displayKirbyStats();
    cout << "Points: " << driver.getPoints() << endl;
    cout << endl;
    cout << "Kirby has reached the Final Boss, King Dedede!" << endl;

    int dDamage;
    
    // Kirby will continue fighting the boss until his health or the boss' health reaches 0.
    while (kirby.getHealth() > 0 && dedede.getHealth() > 0)
    {
        switch (driver.displayMenu())
        {        
            case 1: // attack
            {
                kDamage = driver.kirbyAttackBoss(kirby.getAttackValue() );
                kirby.setEnergy(kirby.getEnergy() - 10);
                
                if (dedede.getHealth() > 0 )
                {
                    dDamage = dedede.bossAttack(dedede.getAttackValue());
                    if (dDamage % 5 == 0)
                    {
                        // boss can now block Kirby's attacks, making it harder to win
                        cout << "King Dedede has blocked Kirby's attack!" << endl;  
                        cout << "King Dedede has taken no damage." << endl;
                    }
                    else
                    {
                        cout << "Kirby has taken " << dDamage << " damage." << endl;
                        kirby.setHealth(kirby.getHealth() - dDamage);
                        dedede.setHealth(dedede.getHealth() - kDamage);
                    }
                }

                if (kirby.getHealth() > 0 && dedede.getHealth() > 0) // stats
                {
                    kirby.displayKirbyStats();
                    cout << "Points: " << driver.getPoints() << endl;
                    dedede.displayBossStats("Dedede");
                }
                break;
            }
            case 2: // defend
            {
                cout << "Do you want to..." << endl;
                cout << "1. Block" << endl;
                cout << "2. Dodge" << endl;
                int choice1;
                cin >> choice1;
                
                if (choice1 == 1) // block
                {
                    dDamage = dedede.bossAttack(dedede.getAttackValue()) - driver.block(kirby.getDefenseValue());
                    if (dDamage < 0)
                    {
                        dDamage = 0;
                    }
                    cout << "Kirby has taken " << dDamage << " damage." << endl;
                    kirby.setHealth(kirby.getHealth() - dDamage);
                    driver.setPoints(driver.getPoints() + 2);
                    cout << "You have earned +2 points for blocking." << endl;
                    if (kirby.getHealth() > 0 && dedede.getHealth() > 0) // stats
                    {
                        kirby.displayKirbyStats();
                        cout << "Points: " << driver.getPoints() << endl;
                        dedede.displayBossStats("Dedede");
                    }
                }
                else if (choice1 == 2) // dodge
                {
                    if (driver.kirbyDodge() == true)
                    {
                        cout << "Kirby has dodged the attack. Kirby takes 0 damage." << endl;
                    }
                    else
                    {
                        dDamage = dedede.bossAttack(dedede.getAttackValue());
                        kirby.setHealth(kirby.getHealth() - dDamage);
                        cout << "Kirby could not dodge the attack. Kirby took " << dDamage << " damage." << endl;
                    }

                    driver.setPoints(driver.getPoints() + 1);
                    cout << "You have earned +1 points for dodging." << endl;

                    if (kirby.getHealth() > 0 && dedede.getHealth() > 0) // stats
                    {
                        kirby.displayKirbyStats();
                        cout << "Points: " << driver.getPoints() << endl;
                        dedede.displayBossStats("Dedede");
                    }            
                }
                break;
            }
            case 3: // visit store
            {
                cout << "If Kirby buys an item, make sure you activate it or else you won't get a bonus in you're stats!" << endl;
                int result = driver.visitStore();
                if (result == 1) // item descripton
                {
                    driver.viewDescription();
                }
                else if (result == 2) // buy item 
                {
                    int result2 = driver.buyItem(driver.getPoints());
                    driver.setPoints(driver.getPoints() - result2);
                }
                else if(result == 3) // activate item
                {
                    int result3 = driver.activateItem();

                    if(result3 == 5)
                    {
                        kirby.setEnergy(result3 + kirby.getEnergy());                      
                    }
                    else if(result3 == 10)
                    {
                        kirby.setDefenseValue(result3 + kirby.getDefenseValue());
                    }
                    else if(result3 == 15)
                    {
                        kirby.setAttackValue(result3 + kirby.getAttackValue());
                    }
                    else if(result3 == 20)
                    {
                        kirby.setHealth(result3 + kirby.getHealth());
                    }  
                    else if(result3 == 25)
                    {
                        kirby.setAttackValue(result3 + kirby.getAttackValue());
                        kirby.setHealth(result3 + kirby.getHealth());
                    }                  
                }
                break;
            }
            case 4: // view a description of the enemy
            {
                driver.viewEnemy("dedede.txt");
                break;
            }
            case 5: // view inventory
            {
                driver.viewInventory();
                break;
            }
            case 6: // quit
            {
                cout << "Good Bye!" << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }

    // If Kirby's health reaches 0, the user loses the game.
    if (kirby.getHealth() <= 0)
    {
        cout << "Oh no! You lost. Sad times." << endl;
        return 0;
    }

    // If the boss' health reaches 0, the user wins the game. 
    if (dedede.getHealth() <= 0)
    {
        cout << "Yay! You defeated King Dedede" << endl;
        cout << "Kirby has saved Dreamland!" << endl;
    }
    
    // Kirby loses if he runs out of energy
    if (kirby.getEnergy() <= 0)
    {
        cout << "Oh no! You're out of energy." << endl;
        return 0;
    }

    // if kirby and the boss both reach 0 health at the same time, it is a tie.
    if (kirby.getHealth() <= 0 && dedede.getHealth() <= 0)
    {
        cout << "It's a tie! Play again so Kirby can defeat the Boss!" << endl;
        return 0;
    }
}