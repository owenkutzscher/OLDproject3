//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

Player::Player()
{
    //Default Constructor sets player with empty name to default player states
    playerName = "";
    playerHealth = 10;
    playerStamina = 10;
    playerInvSize = 7;
    playerWepNum = 3;
    playerKeyCount = 0;
    numItems = 0;
    playerWeapons[0].setWeaponName("Pistol");
    playerWeapons[0].setAmmoType(1);
    playerWeapons[0].setWeaponDamage(10);
    playerWeapons[0].setWeaponAmmo(10);
    playerWeapons[0].setMaxAmmo(10);
    playerWeapons[1].setWeaponName("Shotgun");
    playerWeapons[1].setAmmoType(2);
    playerWeapons[1].setWeaponDamage(15);
    playerWeapons[1].setWeaponAmmo(0);
    playerWeapons[1].setMaxAmmo(8);
    playerWeapons[2].setWeaponName("Rifle");
    playerWeapons[2].setAmmoType(3);
    playerWeapons[2].setWeaponDamage(20);
    playerWeapons[2].setWeaponAmmo(0);
    playerWeapons[2].setMaxAmmo(5);
}
Player::Player(string name, int health, int stamina, int inventorySize, int keys)
{
    //Parameterized Constructor
    playerName = name;
    playerHealth = health;
    playerStamina = stamina; 
    playerInvSize = inventorySize;
    playerKeyCount = keys;
    numItems = 0;
    //Weapons are the exact same for all players
    playerWeapons[0].setWeaponName("Pistol");
    playerWeapons[0].setAmmoType(1);
    playerWeapons[0].setWeaponDamage(10);
    playerWeapons[0].setWeaponAmmo(10);
    playerWeapons[0].setMaxAmmo(10);
    playerWeapons[1].setWeaponName("Shotgun");
    playerWeapons[1].setAmmoType(2);
    playerWeapons[1].setWeaponDamage(15);
    playerWeapons[1].setWeaponAmmo(0);
    playerWeapons[1].setMaxAmmo(8);
    playerWeapons[2].setWeaponName("Rifle");
    playerWeapons[2].setAmmoType(3);
    playerWeapons[2].setWeaponDamage(20);
    playerWeapons[2].setWeaponAmmo(0);
    playerWeapons[2].setMaxAmmo(5);
}
//Getters and Setters
string Player::getPlayerName()
{
    return playerName;
}
void Player::setPlayerName(string name)
{
    playerName = name;
}
int Player::getPlayerHealth()
{
    return playerHealth;
}
void Player::setPlayerHealth(int health)
{
    playerHealth = health;
}
int Player::getPlayerStamina()
{
    return playerStamina;
}
void Player::setPlayerStamina(int stamina)
{
    playerStamina = stamina;
}
int Player::getNumItems()
{
    return numItems;   
}
void Player::setNumItems(int numberOfItems)
{
    numItems = numberOfItems;
}
int Player::getPlayerInventorySize()
{
    return playerInvSize;
}
void Player::setPlayerInventorySize(int inventorySize)
{
    playerInvSize = inventorySize;
}
int Player::getPlayerWeaponNum()
{
    return playerWepNum;
}
void Player::setPlayerWeaponNum(int numOfWeapons)
{
    playerWepNum = numOfWeapons;
}
int Player::getPlayerKeyCount()
{
    return playerKeyCount;
}
void Player::setPlayerKeyCount(int keyCount)
{
    playerKeyCount = keyCount;
}
//Displays the player move menu with a loop, returns a value 1-4 to the map depending on which 4 directions the player wants to move
int Player::displayPlayerMoveMenu()
{
    int playerMovementInput = 0;
    while(playerMovementInput == 0)
    {
        cout << "Movement Options:" << endl;
        cout << "1. Up" << endl;
        cout << "2. Down" << endl;
        cout << "3. Left" << endl;
        cout << "4. Right" << endl;
        cin >> playerMovementInput;
        if(playerMovementInput < 1 || playerMovementInput > 4)
        {
            cout << "Invalid input, please choose another option." << endl;
            cout << endl;
        }
    }
    return playerMovementInput;
}
//Allows the player to search for and see if they find an item on the specific grade square they are on
void Player::pickUpItem()
{
    //Random Seed since the chance of finding an item or which item is found is based on chance
    srand(time(0));
    int itemId;
    //Random chance is out of 1000
    int randItem = rand() % 1000 + 1;
    //The players chance of finding a key goes up with each keys to prevent the game from dragging on too long
    if(playerKeyCount  < 3 && playerKeyCount == 0)
    {
        //When the player has no keys, they have about a 5% chance of finding one per square
        if(randItem > 950)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        //If the player doesn't find a key and their inventory isn't full, they will have a about a 66% chance to find an item
        else if(numItems < playerInvSize)
        {
            //33% chance of finding no items
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            //Each item has a similar % chance of finding different items, which are then pushed bach into the player Inventory array
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 951)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
        }
        //If the inventory is full and no keys are found, this message is printed
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }
    }
    //Same as code above, except once the player has 1 key, the player has a 10% chance of finding a key per square
    else if(playerKeyCount  < 3 && playerKeyCount == 1)
    {
        if(randItem > 900)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        else if(numItems < playerInvSize)
        {
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 901)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
        }
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }
    }
    //Finally, once the player has 2 keys, the player has a 15% chance of finding a key, ensuring they finish the game soon after they find their second key
    else if(playerKeyCount  < 3 && playerKeyCount == 2)
    {
        if(randItem > 850)
        {
            if(playerKeyCount < 3)
            {
                playerKeyCount++;
                cout << "Congrats! You Found a Key! " << (3 - playerKeyCount) << " more to go!" << endl;
                cout << endl;
            }
        }
        else if(numItems < playerInvSize)
        {
            if(randItem > 0 && randItem < 330)
            {
                cout << "Nothing was found." << endl;
            }
            else if(randItem > 330 && randItem < 455)
            {
                playerInventory.push_back(Item(1, 1));
                cout << "You found a pistol magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 454 && randItem < 579)
            {   
                playerInventory.push_back(Item(2, 1));
                cout << "You found a box of 6 shotgun shells." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 578 && randItem < 703)
            {
                playerInventory.push_back(Item(3, 1));
                cout << "You found a rifle magazine." << endl;
                cout << endl;
                numItems++;
            }
            else if(randItem > 702 && randItem < 8)
            {
                playerInventory.push_back(Item(4, 1));
                cout << "You found a healing syringe." << endl;
                cout << endl;
                numItems++;
            }
        }
        else
        { 
            cout << "Inventory full and no keys found." << endl;
        }   
    }
    //Once the player finds all 3 keys, they escape and the game is finished.
    else if(playerKeyCount == 3)
    {
        cout << "Congrats! You have found all 3 keys and can now escape the labrynth" << endl;
    }
}
//Allows the players inventory to be displayed and interacted with
void Player::checkPlayerInventory()
{
    //If the vector is empty, the player is told their inventory is empty
    if(playerInventory.empty())
    {
        cout << "Your inventory is currently empty." << endl;
        cout << endl;
    }
    else
    {
        //Otherwise if the inventory has at least one item, a while loop initiates to display all the items in the player inventory array
        int playerInventoryInput = 0;
        while(playerInventoryInput != playerInventory.size() + 1)
        {
            cout << "Current Inventory: " << endl;
            int displayCounter = 0;
            int itemCounter = 1;
            //This specific while loop displays the inventory in a list format
            while(displayCounter < playerInventory.size())
            {
                cout << itemCounter << ": " << playerInventory[displayCounter].getItemName() << endl;
                displayCounter++;
                itemCounter++;
            }
            //The end of the list will always give the player the option to leave the menu, and then players are prompted for their input
            cout << playerInventory.size() + 1 << ": Quit." << endl;
            cout << "Please select an item: " << endl;
            cin >> playerInventoryInput;
            //If statement protects from inputting a number greater than the inventory size or a negative number
            if(playerInventoryInput < 0 || playerInventoryInput > playerInventory.size() + 1)
            {
                cout << "Invalid Input, Try Again." << endl;
                cout << endl;
            }
            //If the player chooses the quit option
            else if(playerInventoryInput == playerInventory.size() + 1)
            {
                cout << "Returning to primary menu" << endl;
            }
            else
            {
                //Once a player chooses an item, a second, nested while loop initiates for a second menu
                int playerInventoryInput2 = 0;
                while(playerInventoryInput2 != 3)
                {
                    //Within this menu, players have the option of using the item, dropping it, or returning to previous menu
                    string itemName = playerInventory[playerInventoryInput - 1].getItemName();
                    cout << "What do you want to do with " << itemName << "?" << endl;
                    cout << "1. Use Item." << endl;
                    cout << "2. Drop Item." << endl;
                    cout << "3. Go Back" << endl;
                    cin >> playerInventoryInput2;
                    switch(playerInventoryInput2)
                    {
                        //If the player chooses to use an item, different things will happen depending on the item type.
                        case 1:
                        {
                            cout << "Using " << itemName << "." << endl;
                            //For item types 1-3, it will be a weapon ammo type they are using and therefor the weapon will be reloaded
                            if(playerInventory[playerInventoryInput - 1].getItemType() == 1)
                            {                
                                //Checks if the weapon ammo is already full
                                if(playerWeapons[0].getWeaponAmmo() == playerWeapons[0].getMaxAmmo())
                                {
                                    cout << "Cannot reload, pistol ammo is already full" << endl;
                                    playerInventoryInput2 = 3;
                                }
                                else
                                {
                                    //Otherwise the weapon is reloaded and that ammo is removed from the inventory
                                    playerWeapons[0].reloadWeapon();
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    playerInventoryInput2 = 3;
                                }
                            }
                            //Same code as item type 1
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 2)
                            {
                                if(playerWeapons[1].getWeaponAmmo() == playerWeapons[1].getMaxAmmo())
                                {
                                    cout << "Cannot reload, shotgun ammo is already full" << endl;
                                    playerInventoryInput2 = 3;
                                }
                                else
                                {
                                    playerWeapons[1].reloadWeapon();
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    playerInventoryInput2 = 3;
                                }
                            }
                            //Same code as item types 1 and 2
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 3)
                            {
                                if(playerWeapons[2].getWeaponAmmo() == playerWeapons[2].getMaxAmmo())
                                {
                                    cout << "Cannot reload, shotgun ammo is already full" << endl;
                                    playerInventoryInput2 = 3;
                                }
                                else
                                {
                                    playerWeapons[2].reloadWeapon();
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    playerInventoryInput2 = 3;
                                }
                            }
                            //If the chosen item type is 4, it is a healing syringe, which will heal the player's health by 25
                            else if(playerInventory[playerInventoryInput - 1].getItemType() == 4)
                            {
                                //If the player health is above 75, then their health is set to full to prevent their health from going over 100
                                if(playerHealth < 100 && playerHealth > 75)
                                {
                                    playerHealth = 100;
                                    numItems--;
                                    //Syringe is always erased from inventory after use
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    cout << "Used healing syringe, your health is now full." << endl;
                                    playerInventoryInput2 = 3;
                                }
                                //IF player health is 75 or lower, then the player health increases by 25
                                else if(playerHealth < 76 && playerHealth > 0)
                                {
                                    playerHealth += 25;
                                    numItems--;
                                    playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                                    playerInventoryInput2 = 3;
                                    cout << "Used healing syringe, your health is now at " << playerHealth << " HP." << endl;
                                }
                                //Players cannot use healing syringes if their health is full
                                else if (playerHealth == 100)
                                {
                                    cout << "Health is full, cannot use healing syringe" << endl;
                                    playerInventoryInput2 = 3;
                                }                                     
                            }
                            break;
                        }
                        case 2:
                        {
                            //If the player chooses option 2, then they drop the item and it is removed from the player inventory vector
                            playerInventory.erase(playerInventory.begin() + playerInventoryInput);
                            numItems--;
                            cout << "Dropped " << itemName << endl;
                            playerInventoryInput2 = 3;
                            break;
                        }
                        case 3: 
                        {
                            //Returns the player to the previous menu
                            cout << "Returning to previous menu." << endl;
                            break;
                        }
                        default:
                        {
                            //Prevents invalid inputs
                            cout << "Invalid input, please choose another option." << endl;
                            break;
                        }
                    } 
                }
            }
        }   
    }
}
//Allows the player to check the 3 weapons they hold
void Player::checkPlayerWeapons()
{
    int playerWeaponInput = 0;
    while(playerWeaponInput != 4)
    {
        //While loop displays a menu of the weapons the player holds
        int weaponNumber = 1;
        cout << "1: Pistol" << endl;
        cout << "2: Shotgun" << endl;
        cout << "3: Rifle" << endl;
        cout << "4: Go Back" << endl;
        cout << "Choose weapon: " << endl;
        cin >> playerWeaponInput;
        //If statement prevents invalid inputs
        if(playerWeaponInput < 1 && playerWeaponInput > 4)
        {
            cout << "Invalid input. Try Again." << endl;
        }
        //If statement for if the player chooses to quit the menu
        if(playerWeaponInput == 4)
        {
            cout << "Returning to primary menu." << endl;
        }
        else
        {
            //Otherwise a second nested while loop is initiated to ask the player if they would like to reload the weapon and displays their current and max ammo
            int playerWeaponInput2 = 0;
            while(playerWeaponInput2 != 2)
            {
                cout << "Current ammo: " << playerWeapons[playerWeaponInput - 1].getWeaponAmmo() << "/" << playerWeapons[playerWeaponInput - 1].getMaxAmmo() << endl; 
                cout << "Would you like to reload " << playerWeapons[playerWeaponInput - 1].getWeaponName() << "?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> playerWeaponInput2;
                //Protects from invalid inputs
                if(playerWeaponInput2 < 1 || playerWeaponInput2 > 2)
                {
                    cout << "Invalid option, choose another option" << endl;
                }
                //Players cannot reload full weapons
                else if(playerWeapons[playerWeaponInput - 1].getWeaponAmmo() == playerWeapons[playerWeaponInput - 1].getMaxAmmo())
                { 
                    cout << "This weapon is already full" << endl;
                    playerWeaponInput2 = 2;
                }
                //Players cannot reload if they have an empty inventory, which means they have no ammo
                else if(playerInventory.empty())
                {
                    cout << "Your inventory is empty" << endl;
                }
                else if(playerWeaponInput2 == 1)
                {
                    //If the player chooses to reload their wepon, a boolean value is initialized saying the player has no ammo
                    int currentWeaponAmmoType = playerWeapons[playerWeaponInput - 1].getAmmoType();
                    bool hasMoreAmmo = false;
                    //This for loop then searches the players inventory to see if they have a an item type than corresponds with the ammo type of that weapon, which then sets the has ammo bool to true
                    for(int x = 0; x < playerInvSize; x++)
                    {
                        if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                        {
                            hasMoreAmmo = true;
                        }
                    }
                    //If the player has more ammo, the weapon is reloaded, and another for loop searches the player inventory and removes that ammo type from the inventory
                    if(hasMoreAmmo == true)
                    {
                        playerWeapons[playerWeaponInput - 1].reloadWeapon();
                        for(int x = 0; x < playerInvSize; x++)
                        {
                            if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                            {
                                playerInventory.erase(playerInventory.begin() + x);
                            }
                        }
                        cout << "Reloaded " << playerWeapons[playerWeaponInput - 1].getWeaponName() << "." << endl;
                    }
                    else
                    {
                        //If the bool is false, then the player does not have ammo for the weapon they are trying to reload
                        cout << "You do not have any more ammo for this weapon." << endl;
                    }
                    playerWeaponInput2 = 2;
                }
                //Returns player to previous menu
                else if(playerWeaponInput2 == 2)
                {
                    cout << "Returning to previous menu." << endl;
                }
                //Else if protects from invalid inputs
                else if(playerWeaponInput2 > 3 || playerWeaponInput2 < 1)
                {
                    cout << "Invalid input, choose another option." << endl;
                }
            }
        }
    }
}
//Battle function is initiated in the main driver whenever a players XY coordinates are the same as a zombies XY coordinates, which forces a battle with that specific zombie
void Player::battle(Zombie encounteredZombie)
{
    //Battle occurs while the player and zombie's are above 0 HP
    while (playerHealth > 0 && encounteredZombie.getHealth() > 0)
    {
        //Each turn in the battle, the players health and ammo is displayed along with their healing syringe number.
        int syringeNum = 0;
        int playerBattleInput = 0;
        cout << "You have encountered a zombie!" << endl;
        cout << endl;
        cout << "Current Player Health: " << playerHealth << " HP" << endl;
        cout << "Current Pistol Ammo: " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
        cout << "Current Shotgun Ammo: " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
        cout << "Current Rifle Ammo: " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
        for(int x = 0; x < playerInventory.size(); x++)
        {
            if(playerInventory[x].getItemType() == 4)
            {
                syringeNum++;
            }
        }
        cout << "Amount of healing syringes: " << syringeNum << endl;
        cout << endl;
        //Below the player stats, the zombies health is displayed
        cout << "Current Zombie Health: " << encounteredZombie.getHealth() << " HP" << endl;
        cout << endl;
        //The player is then given 3 options and prompted on what to do.
        cout << "What are you going to do?" << endl;
        cout << "1: Use Weapon" << endl;
        cout << "2: Reload Weapon" << endl;
        cout << "3: Use Healing Item" << endl;
        cin >> playerBattleInput;
        switch(playerBattleInput)
        {
            case 1:
            {
                int playerWeaponInput = 0;
                while(playerWeaponInput != 4)
                {
                    //If the player chooses to use their weapon, a second while loop is initiated to ask the player which weapon to use
                    cout << "Current Player Health: " << playerHealth << " HP" << endl;
                    cout << "Current Pistol Ammo: " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
                    cout << "Current Shotgun Ammo: " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
                    cout << "Current Rifle Ammo: " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
                    cout << endl;
                    cout << "Current Zombie Health: " << encounteredZombie.getHealth() << " HP" << endl;
                    cout << endl;
                    cout << "Which Weapon are you going to choose? " << endl;
                    cout << "1: Pistol" << endl;
                    cout << "2: Shotgun" << endl;
                    cout << "3: Rifle" << endl;
                    cout << "4: Go Back" << endl;
                    cout << "Choose weapon: " << endl;
                    cin >> playerWeaponInput;
                    switch(playerWeaponInput)
                    {
                        case 1:
                        {
                            if(playerWeapons[0].getWeaponAmmo() == 0)
                            {
                                //If the player chooses the pistol, the game checks if they have ammo for their ammo first.
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                            {
                                //If the player has ammo in their pistol, they take a shot at the zombie and 1 shot is removed from the pistol ammo
                                playerWeapons[0].setWeaponAmmo(playerWeapons[0].getWeaponAmmo() - 1);
                                srand(time(0));
                                //The likelyhood to hit a zombie is based on a random % chance
                                int hitPercentage = rand() % 100 + 1;
                                //With the pistol, the player has a 65% chance of hitting the zombie
                                if(hitPercentage > 35)
                                {
                                    //Pistol shots do 10 HP of damage to zombies
                                    cout << "The shot hit, the zombie has taken 10 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 10);
                                }
                                else
                                {
                                    //Player however has a 35% chance to miss the zombie
                                    cout << "You missed the zombie." << endl;  
                                }
                                //Whether the player hits or misses the zombie, the zombie will attack the player afterwards
                                if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                                {
                                    //The zombie has a 75% chance of biting the player if they miss or have not killed the player yet
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                //Player dies if their health hits 0
                                else if(playerHealth <= 0)
                                {
                                    cout << "The zombie has killed you!" << endl;
                                }
                                //Once the zombie health hits 0, the battle sequence ends
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            //Multiple checks within each turn to make sure the player is still alive
                            else if(playerHealth <= 0)
                            {
                                cout << "The zombie has killed you!" << endl;
                            }
                            else
                            {
                                //Multiple checks to see if the zombie is still alive
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }  
                            break;  
                        }
                        case 2:
                        {
                            //If the player chooses shotgun, code almost the exact same as shooting with pistol, with only differences to hit percentage and damage.
                            if(playerWeapons[1].getWeaponAmmo() == 0)
                            {
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                            {
                                playerWeapons[1].setWeaponAmmo(playerWeapons[1].getWeaponAmmo() - 1);
                                srand(time(0));
                                int hitPercentage = rand() % 100 + 1;
                                //Shotgun has the highest percentage of chance to hit at 95% and it does 15 damage
                                if(hitPercentage > 5)
                                {
                                    cout << "The shot hit, the Zombie has taken 15 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 15);
                                }
                                else
                                {
                                    cout << "You missed the zombie." << endl;  
                                }
                                if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                                {
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                else if(playerHealth <= 0)
                                {
                                    cout << "The zombie has killed you!" << endl;
                                }
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            else if(playerHealth <= 0)
                            {
                                cout << "The zombie has killed you!" << endl;
                            }
                            else
                            {
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }
                            break;    
                        }
                        case 3:
                        {
                            //Shooting rifle is similar to shotgun and pistol again, with only differences in damage and hit percentage
                            if(playerWeapons[2].getWeaponAmmo() == 0)
                            {
                                cout << "You are out of ammo and must reload." << endl;
                                break;
                            }
                            else if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                            {
                                playerWeapons[2].setWeaponAmmo(playerWeapons[2].getWeaponAmmo() - 1);
                                srand(time(0));
                                int hitPercentage = rand() % 100 + 1;
                                //Rifle has the lowest hit percentage, at only 50% chance to hit, however in exchange for this low percentage, it does the highest damage, usually enough to kill zombies in 1 shot and prevent getting bit
                                if(hitPercentage > 50)
                                {
                                    cout << "The shot hit, the Zombie has taken 20 HP of damage." << endl;
                                    encounteredZombie.setHealth(encounteredZombie.getHealth() - 20);
                                }
                                else
                                {
                                    cout << "You missed the zombie." << endl;  
                                }
                                if(encounteredZombie.getHealth() > 0 && playerHealth > 0)
                                {
                                    hitPercentage = rand() % 100 + 1;
                                    if(hitPercentage > 25)
                                    {
                                        cout << "The Zombie bit you and you lost " << encounteredZombie.getDamage() << " HP" << endl;
                                        playerHealth = playerHealth - encounteredZombie.getDamage();
                                    }
                                }
                                else if(playerHealth <= 0)
                                {
                                    cout << "The zombie has killed you!" << endl;
                                }
                                else
                                {
                                    cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                    return;
                                }
                            }
                            else if(playerHealth <= 0)
                            {
                                cout << "The zombie has killed you!" << endl;
                            }
                            else
                            {
                                cout << "The Zombie has be neutralized, Battle sequence is over." << endl;
                                return;
                            }
                            break;    
                        }
                        //Returns to previous menu
                        case 4:
                        {
                            cout << "Returning to Previous Menu" << endl;
                            break;
                        }
                        //Prevents invalid inputs
                        default:
                        {
                            cout << "Invalid Input, please choose something else." << endl; 
                        }
                    }
                }
                break;
            }
            //If the player chooses to reload their weapon, another nested while loop is initialized to show the player their weapon ammo numbers and allows them to choose weapon to reload
            case 2:
            {
                int playerReloadInput;
                while(playerReloadInput != 4)
                {
                    cout << "Which weapon would you like to reload?" << endl;
                    cout << "1. Pistol -  " << playerWeapons[0].getWeaponAmmo() << "/" << playerWeapons[0].getMaxAmmo() << endl;
                    cout << "2. Shotgun -  " << playerWeapons[1].getWeaponAmmo() << "/" << playerWeapons[1].getMaxAmmo() << endl;
                    cout << "3. Rifle -  " << playerWeapons[2].getWeaponAmmo() << "/" << playerWeapons[2].getMaxAmmo() << endl;
                    cout << "4. Go Back" << endl;
                    cin >> playerReloadInput;
                    //Prevents invalid inputs
                    if(playerReloadInput > 4 || playerReloadInput < 1)
                    {
                        cout << "Invalid Input, please try again" << endl;
                    }
                    //Exists the weapon reload menu
                    else if(playerReloadInput == 4)
                    {
                        break;
                    }
                    else
                    {
                        //Boolean checks if player has ammo tha matches the weapon ammo type, searches inventory with for loop
                        int currentWeaponAmmoType = playerWeapons[playerReloadInput - 1].getAmmoType();
                        bool hasMoreAmmo = false;
                        for(int x = 0; x < playerInvSize; x++)
                        {
                            if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                            {
                                hasMoreAmmo = true;
                            }
                        }
                        //If player has matching ammo type, the weapon is reloaded and that ammo is removed from the inventory
                        if(hasMoreAmmo == true)
                        {
                            playerWeapons[playerReloadInput - 1].reloadWeapon();
                            for(int x = 0; x < playerInvSize; x++)
                            {
                                if(playerInventory[x].getItemType() == currentWeaponAmmoType)
                                {
                                    playerInventory.erase(playerInventory.begin() + x);
                                }
                            }
                            cout << "Reloaded " << playerWeapons[playerReloadInput - 1].getWeaponName() << "." << endl;
                        }
                        //If bool is false, player has no ammo for said weapon
                        else
                        {
                            cout << "You do not have any more ammo for this weapon." << endl;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                //Third option allows player to heal, checks player inventory for healing syringe number, doesn't allow them to heal if they don't have any
                if(syringeNum <= 0)
                {
                    cout << "You are out of healing syringes and cannot heal yourself." << endl;
                    break;
                }
                else
                {
                    //If the player has syringes, player inventory is searched for healing syringe
                    int syringeIndex;
                    for(int x = 0; x < playerInventory.size(); x++)
                    {
                        if(playerInventory[x].getItemType() == 4);
                        {
                            syringeIndex = x;
                            break;
                        }
                    }
                    //Same code as healing from the inventory menu outside of a battle
                    if(playerHealth < 100 && playerHealth > 75)
                    {
                        playerHealth = 100;
                        numItems--;
                        playerInventory.erase(playerInventory.begin() + syringeIndex);
                        cout << "Used healing syringe, your health is now full." << endl;
                    }
                    else if(playerHealth < 76 && playerHealth > 0)
                    {
                        playerHealth += 25;
                        numItems--;
                        playerInventory.erase(playerInventory.begin() - syringeIndex);
                        cout << "Used healing syringe, your health is now at " << playerHealth << " HP." << endl;
                    }
                    else if (playerHealth == 100)
                    {
                        cout << "Health is full, cannot use healing syringe" << endl;
                    }
                }
                break;
            }
            //Prevents invalid inputs
            default:
            {
                cout << "Invalid input, please input a valid input." << endl;
            }
        }
    }
}