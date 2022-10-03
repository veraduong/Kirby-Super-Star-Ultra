// CS1300 Spring 2020
// Author: Vera Duong and Emily Hoang
// Recitation: 301 – Telly Umada
// Project 3 

#include <iostream> 
#include <fstream>
#include <string>
#include <ctime>
#include "KirbyBoss.h"
#include "Minion.h"
#include "Driver.h"
using namespace std; 

Driver :: Driver() // Constructor initializes the variables and arrays
{
    // Puts the items in the store into two arrays
    ifstream infile;
    infile.open("store.txt");
    string str;
    int line = 0;
    while (getline(infile, str))
    {
        // This array is for the item names
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ':')
            {
                items[line] = str.substr(0, j);
            }
        }
        // This array is for the costs
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ',')
            {
                int cost = stoi(str.substr(j + 1, str.length()));
                itemCost[line] = cost;
                
            }
        }
        line++;
    }
    // Initializes the minion array. The first three minions have the power shield.
    // The second three have the power sword. Shield increases health. Sword incrases attack.
    for (int i = 0; i < 3; i++)
    {
        minions[i].setShield(5);
    }
    for (int i = 3; i < 6; i++)
    {
        minions[i].setSword(5);
    }
    // Kirby starts the game with 0 points.
    points = 0;
    // This variable is used later for the inventory functions. 
    itemValuePos = 0;
}

// This function sets the number of points. It does not return anything.
void Driver :: setPoints(int pointValue)
{
    points = pointValue;
}

// This function gets the number of points. It returns the number of points as an int. 
int Driver :: getPoints()
{
    return points;
}

// This function is used when the user chooses to block a boss attack. Block will lessen a boss attack.
// The block number will be chosen at random between 1 and the defense value. The function returns the block
// value as an integer.
int Driver :: block(int defenseValue) 
{
    cout << "Kirby has chosen to block." << endl;
    srand(time(NULL));
    int seed = randomNumbers(0,RAND_MAX);
    srand(seed);
    int kBlock_ = randomNumbers(1, defenseValue);
    return kBlock_;
}

// menu for attacking minions. The function returns the choice as an int.
int Driver :: kirbyAttackMinion()
{
    cout << "Do you want to...?" << endl;
    cout << "1. Strike" << endl;
    cout << "2. Copy" << endl;
    int choice1;
    cin >> choice1;

    return choice1;
    cout << "Called attack function" << endl;
}

//  This function picks a number at random between 1 and the attack value if the user chooses to 
// attack the boss. The function returns the attack value as an int. 
int Driver :: kirbyAttackBoss(int attackValue)
{
    cout << "Kirby has attacked the boss." << endl;
    srand(time(NULL));
    int seed = randomNumbers(0,100);
    srand(seed);
    int kStrike_ = randomNumbers(1, attackValue);
    cout << "Kirby will strike at " << kStrike_ << "." << endl;
    return kStrike_;
}

// Kirby has a 50/50 shot of dodging a boss attack completely. This function returns either true or false.
// If the function returns true, kirby dodged the attack. Otherwise, kirby faces the entirety of the attack. 
bool Driver :: kirbyDodge()
{
    bool dodge = false;
    int dodge_ = randomNumbers(1, 2);
    if (dodge_ == 1)
    {
        dodge = true;
    }
    if (dodge_ == 2)
    {
        dodge = false;
    }
    return dodge;
}

// Displays main menu, returns choice input as an int
int Driver :: displayMenu()
{
    cout << "====Menu====" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Visit Store" << endl;
    cout << "4. View Enemy" << endl;
    cout << "5. View Inventory" << endl;
    cout << "6. Quit" << endl;
    int choice;
    cin >> choice;

    return choice;  
}  

// visit store function displays store menu options and displays the items in items[i] array
int Driver :: visitStore()
{
    cout << "Here are the items in the store:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << items[i] << endl;
    }
    cout << "-----------------" << endl;
    cout << "Do you want to..." << endl;
    cout << "1. View Description" << endl;
    cout << "2. Buy Item" << endl;
    cout << "3. Activate Item" << endl;
    int choice;
    cin >> choice;
    
    if (choice == 1)
    {
        return 1;
    }
    else if (choice == 2)
    {
        return 2;
    }
    else if (choice == 3)
    {
        return 3;
    }
    else
    {
        cout << "Invalid option" << endl;
        return -1;
    }
}

// displays the description of an item the user inputs when in the store menu 
void Driver :: viewDescription()
{
    // this takes in an item name and matches it to the name in the items array
    cout << "Enter item name: " << endl; 
    string itemName;
    cin.ignore();
    getline(cin, itemName);
    int line;
    for (int i = 0; i < 5; i++)
    {
        if (itemName == items[i])
        {
            line = i;
            break;
        }
        else if (i == 4 && itemName != items[i])
        {
            cout << "Item not found." << endl;
            return;
        }
    }

    // this will display the description of the item the user input from the textfile 
    ifstream infile;
    infile.open("store.txt");
    string str1;
    int line1 = 0;
    while(getline(infile, str1))
    {
        if (line1 == line)
        {
            for (int j = 0; j < str1.length(); j++)
            {
                if (str1[j] == ',')
                {
                    string description = str1.substr(0 , j);
                    cout << description << endl;
                    return;
                }
            }
        }
        line1++;
    }
}

// If the user chooses to buy an item from the store, the item will be added to the inventory, and 
// the cost of the item will be subtraced from the points. The function returns the cost of the item
// as an int.
int Driver :: buyItem(int points)
{
    cout << "Enter item name: " << endl; // matches item name input to the item name in array
    string itemName;
    cin.ignore();
    getline(cin, itemName);
    int line;
    for (int i = 0; i < 5; i++)
    {
        if (itemName == items[i])
        {
            line = i;
            break;
        }
        else if (i == 4 && itemName != items[i])
        {
            cout << "Item not found." << endl;
            return 0;
        }
    }
    
    // this adds the item value (number that adds to Kirby's stats) into itemValue array once item is bought 
    ifstream infile;
    infile.open("store.txt");
    string str;
    int line1 = 0;
    while (getline(infile, str))
    {
        if (line1 == line)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == ',')
                {
                    string itemValueString = str.substr(i-2,2);
                    itemValue[itemValuePos] = stoi(itemValueString);
                    itemValuePos++;
                }
            }
        }
        line1++;
    }

    if (itemCost[line] > points) 
    {
        cout << "You don't have enough points to buy the item! Defeat more minions!" << endl;
        return 0;
    }

    // adds item purchased to the inventory text file
    ofstream outfile;
    outfile.open("inventory.txt", ios::app);
    outfile << itemName << endl;
    cout << "Added item to inventory." << endl;
    outfile.close();
  
    return itemCost[line];
}

// This function opens up a file and reads from it to display a description of the enemies kirby is 
// fighting. The function does not return anything.
void Driver :: viewEnemy(string enemyFile)
{
    ifstream infile;
    infile.open(enemyFile);
    string str;
    while (getline(infile, str))
    {
        cout << str << endl;
    }
}

// This function opens the inventory file and reads all the items from the inventory. It does not return
// anything. 
void Driver :: viewInventory()
{
    ifstream infile;
    infile.open("inventory.txt");
    
    if(infile.fail()) // if infile fails to open
    {
        cout << "can't view inventory" << endl;
    }
    else  // if file opens
    {
        string str;
        int lineCount = 0;
        while (getline(infile, str))
        {
            cout << str << endl;
        }
    }
}

// If kirby chooses to copy a minion's power, he will increase his stats by the value stored in the
// minions array. The function returns the increase in stats as an int.
int Driver :: copy()
{
    ifstream infile;
    infile.open("inventory.txt");
    string str;
    infile >> str;
    if (points < 3 && str == "")
    {
        return minions[points].getShield();
    }
    else
    {
        return minions[points].getSword();
    }
}

// If Kirby buys an item from the store, he must activate it in order for it to have an effect on his
// stats. The function returns the increase in stats due to activating the item as an int. 
int Driver :: activateItem()
{
    ifstream infile;
    infile.open("inventory.txt");
    if(infile.fail()) // if infile fails to open
    {
        cout << "Can't view inventory." << endl;
        return -1;
    }
    cout << "Which item do you want to activate?" << endl;
    string itemName;
    cin.ignore();
    getline(cin, itemName);
    string str;
    int line = 0;
    bool itemFound = false;
    while (getline(infile, str))
    {
        if (str == itemName)
        {
            itemFound = true;
            break;
        }
        line++;
    }
    if (itemFound == true)
    {
        cout << "Item Activated." << endl;
        return itemValue[line];
    }
    else
    {
        cout << "Could not find item in inventory." << endl;
        return 0;
    }
}

int Driver :: randomNumbers(int min, int max) // generate random numbers funct
{
    return (rand() % (max-min+1)) + min;
}

