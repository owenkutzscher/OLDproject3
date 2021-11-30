//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

//pseudo code:

/*

main driver:
    loops through the play fucnion while the player is still playing,
     becuase if they die they can be prompted to play again


//play functions gets the user playing
play()

    ////    before we start the game update loop, get the player set up     ////
    //like idk set players health to zero n shit


    ////    "game update loop"    ////
    //while our player is still playing, continue updating the game and looping through
    //each turn is 1 time going through this loop
    while loop{


        ////first display current stats and things

        ////second get the players response for the current turn they are on
        
        ////if they wanted to use an item or they're fighting a zombie or something similar then 
        //// have some kind of while loop going and call a funcion that gets input and just
        ////  has it so they are using an item


        ////call some kind of updateAllThings() funcion that updates everything going on
        ////like, it'll move the zombies and 


        ////like.. if(player.getDead?() == 1){ }
        ////    if they died then break the loops below:

        //if player dies.....
        
        //stop the loop with them playing the round
        
        //then ask if they want to play again
        
        
        

        //this is what we will return to our main funcion where this function was called
        //if they say they want to play again, then this variable will get returned, causing this fucnion to restart

*/




#include <iostream>
#include <cstring>
#include <fstream>
#include "Player.h"
#include "Map.h"

using namespace std;


bool play();
vector<Zombie> createZombiesVec();

void displayCurrentStatsAndThings();
bool checkForZombieOnPlayer();
Zombie findZombieOnPlayer();
void displayBasicMenu();
Map playerMoveMenu();
//void playerCheckInventoryMenu();


vector<Zombie> moveAllZombies();


void readScoreBoard();
int split();
void clearScoreBoard();
void addToScoreBoard();





//you know what this does
//splits a string passed in into an array, splits things around a seperator
int split(string str, char seperator, string arr[], int arrSIZE){
    //this will be the num pieces out string is split into
    int numPieces = 0;

    int validSeperatorCount = 0;



    //first, lets see if its an empty string, if so
    // numPieces, the return val, is 0 and just dont do anything else
    if(str == ""){
        
        //cout << "bruh there wasnt even a single guy in there what the heck" << endl;
        numPieces = 0;

    }else{

        //start looping and looking through the string for a seperator
        int strSize = str.length();
        for(int i = 0; i < strSize; i++){
            //cout << "testing the char: " << str[i] << endl;

            //lets see if its a seperator
            char c = str[i];
            if(c == seperator){
                //cout << "ayy we caught a seperator, in the act" << endl;

                //we found a seperator, sick
                //lets make sure it doesnt have anything weird with it

                //if the seperator is at the beginning or end, dont do anything
                if((i == 0) || (i == strSize)){
                    //cout << "ayy seperator what are you doing at the beginning/end?!!!" << endl;
                    bool keepGoing = 1;
                    while(keepGoing == 1){
                        if(str[i+1] == seperator){
                            i++;
                            //cout << "hell na no seperator repeating at thebeginning" << endl;
                        }else{
                            keepGoing = 0;
                        }
                    }
                }else{
                    
                    //cool, the seperator isnt at the beginning or the end

                    //wait, what if there were say 3 seperator in a row at the beginning?
                    // test for that
                    //actually we dont need to, if it was at the beginning, then it will do i++
                    // that way we are where we need to be

                    //if the seperator is followed by more seperators, that reach the
                    // end, then dont do anything
                        bool keepGoing = 1;
                        while(keepGoing == 1){
                            if(str[i+1] == seperator){
                                i++;
                                //cout << "hell na no seperator repeating" << endl;
                                if(i == strSize-1){
                                    //if the seperators went till the end then they are invalid
                                    //so take 1 off the count becuse we will be adding 1 on later regarless
                                    //cout << "those seperators went till the end so they are invalid" << endl;
                                    validSeperatorCount--;
                                }
                            }else{
                                keepGoing = 0;
                            }
                        }
                    
                    

                        //if the seperator has more seperators in front of it, then count
                        // it, and skip over the seperators against this one
                        //actually we dont need to do anything!
                        //the loop above checks for all instances of a seperator repeating

                        //if it doesnt have any seperators in front of it,
                        // and it passed all the tests, then count it
                        validSeperatorCount++;

                }

                    



                
            }
        }


        //loop ends here
        //cool we finished looping and finding seperators

        //now count the number of pieces, since we have the number of seperators
        numPieces = validSeperatorCount + 1;

        //if we finished looping, and there was no seperators,
        // then numPieces is 1, we will return that, and now place the whole
        // string in the array as the first element
        if(numPieces == 1){
            arr[0] = str;
        }else if(numPieces > arrSIZE){






            //well the dint state this in the problem so now I have to do this I guess
            //alright we have to add elements into the array until the array is full

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            int spaceLeft = arrSIZE;

            //bool endOnSeperator = 0;
            while(spaceLeft > 0){
            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                            spaceLeft--;
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    //if(p == strSize){
                    //    endOnSeperator = 1;
                    //}
                }

                itemToAdd.push_back(c);


                addAndReset = 1;
            }
            }




            
            
            //else if the string is split into more pieces than the size of 
            // the array, then numPieces, return val, is -1
            // and i guess just dont change the array
            numPieces = -1;
            //cout << "banana" << endl;


            
        }else{
            //sick, you passed those tests
            //now loop though and shove guys into an array wherever the
            // seperator ends

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            bool endOnSeperator = 0;

            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    if(p == strSize){
                        endOnSeperator = 1;
                    }
                }

                itemToAdd.push_back(c);


                addAndReset = 1;



                

            }

            if(endOnSeperator == 0){
                if(addAndReset == 1){
                            //since we found a seperator, 
                            // lets add the item weve been building into our array
                            //real quick tho, make sure the item to add isnt empty
                            if(itemToAdd != ""){
                                //cout << "im adding the item: " << itemToAdd << endl;
                                arr[z] = itemToAdd;
                                itemToAdd = "";
                            }
                            z++;
                        }
                }
            }
            

        
    }


    //cout << "valid seperator count: " << validSeperatorCount << endl;
    //return num pieces string was split into
    return numPieces;
}



















//lets make a function to erase all the leader boards. That can
// be called before the game starts if the scoreBoard.txt file isnt empty by default
    //erase the scoreBoard.txt file






//reads the score board, displays players names and scores sorted from highest to lowest
// note that the "highest score" is the score that won in the LEAST moves
void readScoreBoard(string fileName){

    //this is the file we'll open
    ifstream filedFile(fileName);


    //we will add the players names to one vector, and the scores to another vector
    //we will be sorting these vectors later
    vector<string> playersNames;
    vector<int> playersScores;

    //this is an array so we can temporarily store things from the split function
    string tempHolder[2];





    //so lets go through the file and add all the names and the scores to vectors
    //then we will sort them so the names with the highst scores appear at the front of the vectors
    if(!filedFile.is_open()){
        //dang we couldnt open it

    }else{
        //if we can open the file, then
        //go through our file...
        
        //this will just be a line of text from our file
        string line = " ";


        while (!filedFile.eof()){
            

            //get input
            getline(filedFile, line);
            

            //hold up, is the line empty?
            if(line.length() <= 1){
                
            }else{
                //cool it wasnt an empty line
                
                //lets use the split fucntion to split into the players name and the score
                //split(string str, char seperator, string arr[], int arrSIZE)
                split(line, ',', tempHolder, 2);

                //now shove the values in to our vectors
                playersNames.push_back(tempHolder[0]);
                playersScores.push_back( stoi(tempHolder[1]) );


            }
        }
    }


    //these variables exist so we can easily swap 2 guys from playersNames or playersScores
    string tempNameHolder = " ";
    int tempScoreHolder = 0;
    
    //cool, we added all the names and stuff to our vectors
    //now lets sort them so the highest scores appear first
    for(int u = 0; u < playersNames.size(); u++){
        //for each item in the list, see if it's greater than all the items following it

        //so we'll need another for loop to check every value following the guy
        // that  we're currently checking
        for(int y = u+1; y < playersNames.size(); y++){


            //cout << "comparing our u: " << playersScores.at(u) << " to our y: " << playersScores.at(y) << endl;



            //if a player that is past the player we are checking has a lower number of moves...
            // then swap those two player's scores and names
            if(playersScores.at(u) > playersScores.at(y)){

                //swap scores
                tempScoreHolder = playersScores.at(u);
                playersScores.at(u) = playersScores.at(y);
                playersScores.at(y) = tempScoreHolder;

                //swap names
                tempNameHolder = playersNames.at(u);
                playersNames.at(u) = playersNames.at(y);
                playersNames.at(y) = tempNameHolder;
            }
        }
    }




    
    //vecotrs have been sorted, now lets display the names and scores in order so they look pretty
    //note, if the vectors are empty, display, no winners yet
    
    cout << " - - - Score Board - - - " << endl;

    //this will be so we can say... 1. 2. 3. on the score board
    int scoreBoardIndex = 1;
    
    if(playersNames.size() == 0){
        cout << "No one has beat the game yet..." << endl;
    }else{
        for(int i = 0; i < playersNames.size(); i++){
            cout << scoreBoardIndex << ": ";
            cout << playersNames.at(i) << " took " << playersScores.at(i) << " moves to finish the game" << endl;
            scoreBoardIndex++;
        }
    }
    //playersScores.close();
}



void clearScoreBoard(string fileName){
    //make the thing to write things on
    ofstream openedFile;

    openedFile.open(fileName);

    openedFile.trunc;

    openedFile.close();
}

//adds a name to the score board, formatted, name,numTurnsToWin
void addToScoreBoard(string fileName, string name, int score){


    //so heres the plan on how were going to do this
    //first, go through the scoreboard.txt file, and for each line, insert that into a vector
    //then write everything back on to the .txt file, and add on the thing we wanted to add in the first place


    //this is the vector where we will store each line from the .txt file
    vector<string> linestxt;








    //this is the file we'll open
    ifstream filedFile(fileName);


    //lets go through the file
    if(!filedFile.is_open()){
        //dang we couldnt open it

    }else{
        //if we can open the file, then
        //go through our file...
        
        //this will just be a line of text from our file
        string line = " ";


        while (!filedFile.eof()){
            

            //get input
            getline(filedFile, line);
            

            //hold up, is the line empty?
            if(line.length() <= 1){
                
            }else{
                //cool it wasnt an empty line

                //now shove the line in to our vector
                linestxt.push_back(line);
            }
        }
    }


    //now that we added all the lines to our vector, lets add our new line
    string newLine = name + "," + to_string(score);
    linestxt.push_back(newLine);


    ////now that we got the lines from the file, lets write them all back on with our additional line

    //make the thing to write things on
    ofstream openedFile;

    //open that thing
    openedFile.open(fileName);
    

    

    //if the file is open...
    if(openedFile.is_open()){

        for(int i = 0; i < linestxt.size(); i++){
            string textToAdd = "\n" + linestxt.at(i);
            //cout << "text to add is: " << textToAdd << endl;
            openedFile.write(textToAdd.data(), textToAdd.size());
        }
        
    }

    openedFile.close();
}






//This fuction creates a vector of Zombies
//Its where all our zombies will be stored for each round
//each turn the zombies vector will be updated, and we will have each zombie move
vector<Zombie> createZombiesVec(int numZombiesToSpawn){
    vector<Zombie> zombiesVec;


    for(int i = 0; i < numZombiesToSpawn; i++){

        //we will add in a zombie with random stats
        Zombie randoZomb;
        randoZomb.setAllStatsRandom();

        zombiesVec.push_back(randoZomb);
    }

    return zombiesVec;

}


//this is what is displayed at the beginning of each turn
//Just some stats and things to keep the player updated
void displayCurrentStatsAndThings(Map mainGameMap, Player currentPlayer, int turns){
    cout << endl;
    cout << endl;
    cout << "Player Stats: " << endl;
    cout << "Player: " << currentPlayer.getPlayerName() << endl;
    cout << "Turn Number: " << turns << endl;
    cout << "Health: " << currentPlayer.getPlayerHealth() << endl;
    cout << "Stamina: " << currentPlayer.getPlayerStamina() << endl;
    cout << "Inventory Size: " << currentPlayer.getPlayerInventorySize() << endl;
    cout << "Number of Weapons: " << currentPlayer.getPlayerWeaponNum() << endl;
    cout << "Number of Keys: " << currentPlayer.getPlayerKeyCount() << endl;
    cout << "X: " << mainGameMap.getPlayerX() << " Y: " << mainGameMap.getPlayerY() << endl;
}

//This returns a value of 1 (true) if a zombie and a player are on the same coordinates
bool checkForZombieOnPlayer(vector<Zombie> zombiesVec, Map currentMap){

    //Return value
    bool rV = 0;

    //These varibales we will just temporarily set to values for the zombie that we are checking
    int zX = 0;
    int zY = 0;

    //these variables are just to make it easy to compare to the players X and Y
    int pX = currentMap.getPlayerX();
    int pY = currentMap.getPlayerY();

    for(int i = 0; i < zombiesVec.size(); i++){
        zX = zombiesVec.at(i).getX();
        zY = zombiesVec.at(i).getY();

        if(zX == pX && zY == pY){
            //cout << "we found a zombie on the player at: ";
            //cout << "X = " << zX << " Y = " << zY << endl;

            rV = 1;
        }
    }

    return rV;
}



Zombie findZombieOnPlayer(Map currentMap, vector<Zombie> zombiesVec){
    //this is the zombie we find on the player that we will return
    Zombie returnZombie;

    //these varibales we will just temporarily set to values for the zombie
    //that we are checking
    int zX = 0;
    int zY = 0;

    //these variables are just to make it easy to compare to the players X and Y
    int pX = currentMap.getPlayerX();
    int pY = currentMap.getPlayerY();

    for(int i = 0; i < zombiesVec.size(); i++){
        zX = zombiesVec.at(i).getX();
        zY = zombiesVec.at(i).getY();

        if(zX == pX && zY == pY){
            //cout << "we found a zombie on the player at: ";
            //cout << "X = " << zX << " Y = " << zY << endl;

            returnZombie = zombiesVec.at(i);
        }
    }

    return returnZombie;
}

//this is just a starting menu with things like...
//attack, move, use item, etc...
void displayBasicMenu(){

    //the requirements reads: "at least 5 manu options" 
    //cout << "whis is this causing an error?!?!?!" << endl;
    //cout << "Options: " << end;
    
    
    cout << "Options: " << endl;
    cout << "1: Move" << endl;
    cout << "2: Check Inventory" << endl;
    cout << "3: Check Weapons" << endl;
    cout << "4: Search for Items" << endl;
    cout << "5: Display Scoreboard" << endl;
    cout << "6: Quit" << endl;
}


//asks the player which direction they'd like to move in
//prompts them with a move menu
//returns an updated map with the players new X and Y 
Map playerMoveMenu(Map currentMap, Player currentPlayer){
    
    //this is what we'll return, its the map but updated with the new x and y positions
    Map updatedMap = currentMap;

    //this is where we will store the move direction the player selects

    //MAKE A WHILE LOOP MAKING SURE THEY DONT GO  THORUGH A WALL



    //this is where will save the users move direction input
    int moveDirection = 0;

    //this is to break / continue the while loop which checks for a valid move direction
    bool validDirection = 0;

    while(validDirection == 0){
        moveDirection = currentPlayer.displayPlayerMoveMenu();
        //1: up
        //2: down
        //3: left
        //4: right
        
        //depending on which  direction they chose, change the players X or Y coords
        //this set of if else statemtns also checks to see if their move direction was valid, ex invalid: 6
        //not only that, it checks to make sure they don't move through a wall/edge of the map
        if(moveDirection == 1){

            //up
            if(currentMap.getPlayerY() <= 0){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerY(currentMap.getPlayerY() - 1);
            }
            
            
        }else if(moveDirection == 2){

            //down
            if(currentMap.getPlayerY() >= 14){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerY(currentMap.getPlayerY() + 1);
            }

        }else if(moveDirection == 3){

            //left
            if(currentMap.getPlayerX() <= 0){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerX(currentMap.getPlayerX() - 1);
            }

        }else if(moveDirection == 4){

            //right
            if(currentMap.getPlayerX() >= 26){
                cout << "You can't cross the edge of the map! Pick a different move direction." << endl;
            }else{
                validDirection = 1;
                updatedMap.setPlayerX(currentMap.getPlayerX() + 1);
            }

        }
    
    }


    

    


    return updatedMap;
}





vector<Zombie> moveAllZombies(vector<Zombie> ZZZ){
    for(int i = 0; i < ZZZ.size(); i++){
        ZZZ.at(i).moveRandomly();
    }

    return ZZZ;
}




//play functions gets the user playing
bool play(){



    //each turn will be counted here as a turn
    int turns = 0;

    //this is used to indicate if we should continue updating the game
    //if they die or win this will become a zero and break the "game update loop"
    bool stillPlayingRound = 1;

    //this is used to check if a response is valid
    //we will assign its value to true to break a while loop
    //then we will assign it to false again so we can immediatly re use it
    bool validResponse = 0;


    //this is what we will return to our main funcion where this function was called
    //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
    bool wantToPlayAgain = 1;

    //if the player dies this will trigger a series of things that end the round
    bool playerDead = 0;

    //when we want some input from the player, we might want to use this for a response
    string response = " ";

    //this is to check if the player has won the game
    //if the player has won, slightly different things will occur at the very end
    bool playerHasWon = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////


    ////    before we start the game update loop, get the player set up     ////
    //like idk set players health to zero n shit
    //we'll also set up some other things, like spawning some zombies all over the map

    //create a new map to use for the game
    Map currentMap;

    //for testing purpouses:
    //lets give the player a specific location
    currentMap.setPlayerX(0);
    currentMap.setPlayerY(0);
    
    //make our player
    //later we can add the feature to enter your name and maybe select players with specialized stats or something
    Player currentPlayer;
    string currentPlayerName;
    cout << "Please name your character" << endl;
    cin >> currentPlayerName;
    currentPlayer.setPlayerName(currentPlayerName);

    //lets make a vector of zombies, and spawn em all over the map
    //the int entered in is how many zombies we want to spawn
    vector<Zombie> zombiesVec = createZombiesVec(20);


    ////    "game update loop"    ////
    //while our player is still playing, continue updating the game and looping through
    //each turn is 1 time going through this loop
    while(stillPlayingRound == 1){
        
        //before we do anything, print out some lines to make it clear where tha last turn ended
        // and where this new turn begind
        cout << endl;
        cout << "///////////////////////////////////END OF TURN////////////////////////////////////////" << endl;
        cout << endl;
        

        
        //before anthing else, add 1 to the turn count
        turns++;

        ////first display current stats and things like the map
        //add more inputs to this function to display more things
        currentMap.displayMap();
        //^idk why the display map i being buggy when i pass it into the function so we'll just call it here
        displayCurrentStatsAndThings(currentMap, currentPlayer, turns);

        cout << endl;
        



        //this sees if a zombie and the player are on the same space
        //if they are it will initiate a battle sequence
        bool battleTime = checkForZombieOnPlayer(zombiesVec, currentMap);

        //now, if we found a zombie on the player, its battle time
        if(battleTime == 1){
            cout << "Oh no!" << endl;
            //cout << "Its battle time..." << endl;
            //we need to find the zombie that's on the player
            //and we need to pass that zombie into the Player.battle function to initiate a battle!
            Zombie zombieOnPlayer = findZombieOnPlayer(currentMap, zombiesVec);
            currentPlayer.battle(zombieOnPlayer);

        }











        ////second get the players response for the current turn they are on
        //have an ask for input function that prints a list of options
        //dependign on the option, print / update different things and stuff
        
        //lets display a menu of things for them to choose from
        //this will be like... move, attack, use item, etc.
        displayBasicMenu();

        //this loop does 2 jobs
        // it (1) checks to make sure the players response is valid
        // and (2) it will call functions and activate menus depending on the player response
                //ex: we call check weapons, then it calls the "check weapons menu" fucniton, 
                // which will display  more things etc...
        while(validResponse == 0){
            cin >> response;
            if(response == "1"){
                //move

                //OFFICIALLY DONE!
                //cout << "the player wants to move" << endl;
                currentMap = playerMoveMenu(currentMap, currentPlayer);
                validResponse = 1;

            }else if(response == "2"){
                //check inventory

                //POTENTIALLY SOME TESTING, BUT IF IT WAS DONE IN THE PLAYER CLASS, THIS IS DONE
                //cout << "the player wants to check their inventory" << endl;
                //playerCheckInventoryMenu(currentPlayer);
                currentPlayer.checkPlayerInventory();
                validResponse = 1;

            }else if(response == "3"){
                //check weapons

                //HOLY SHIT, SAME AS ABOVE^ REECE DEPENDING ON THE TESTING YOU DID THIS ONE IS DONE
                //cout << "the player wants to check their weapons" << endl;
                currentPlayer.checkPlayerWeapons();
                validResponse = 1;

            }else if(response == "4"){
                //search for item

                currentPlayer.pickUpItem();
                validResponse = 1;

            }else if(response == "5"){

                //cout << "PUT SOMETHING IN HERE" << endl;
                readScoreBoard("scoreBoard.txt");
                validResponse = 1;

            }else if(response == "6"){

                cout << "Quitting game" << endl;
                playerDead = 1;
                validResponse = 1;
                //tell a message saying its going to save their game with number of moves
                // and they they didn't win

            }else{
                cout << "invalid response, please enter a number 1-6" << endl;
            }
        }

        //now reset valid response
        validResponse = 0;
        







        ////call some kind of updateAllThings() funcion that updates everything going on
        //actually, we might just need to update the zombies vec
        zombiesVec = moveAllZombies(zombiesVec);

        
        //this is usefull for testing:
        //this prints out the current zombie locations
        /*
        for(int w = 0; w < zombiesVec.size(); w++){
            cout << "ZX: " << zombiesVec.at(w).getX();
            cout << " ZY: " << zombiesVec.at(w).getY() << endl;
        }
        */
        






        //// things related to the game ending below ////

        


        //we need to check if the player has won the game
        if(currentPlayer.getPlayerKeyCount() >= 3){
            playerHasWon = 1;
        }

        //if the players health is zero or less, then they've died, so make the player dead variable a 1
        if(currentPlayer.getPlayerHealth() <= 0){
            playerDead = 1;
        }

        ////the below if statemnts n shit check to see if they payer has died, and if the player has won
        //everything below is jsut some concluding stuff to end the game
        if(playerDead == 1 || playerHasWon == 1){
            
            
            if(playerDead == 1){
                //if player dies.....
                cout << "You died lmao" << endl;
                cout << "Since you didn't win, your name and score will not be recorded in the Score Board" << endl;
                cout << "Try again to get your name in the leader boards!" << endl;
            }else{
                //else, they won!!!!!!!
                cout << "Congradulations! You won!!" << endl;
                //now that they've died, lets record their name in the scoreBoard.txt file
                //if you wanna see how that' done, check out the function below
                addToScoreBoard("scoreBoard.txt", currentPlayerName, turns);

                //lastly, since they won, automatily display the leaderboards sorted
                //def make this a function
                readScoreBoard("scoreBoard.txt");
                
            }
            



            








            //stop the loop with them playing the round
            stillPlayingRound = 0;
            //then ask if they want to play again
            string playerResponse = " ";

            bool validResponse2 = 0;

            while(validResponse2 == 0){
                cout << "you wanna keep playing? 1 = yes, 0 = no" << endl;
                cin >> playerResponse;

                if(playerResponse == "1" || playerResponse == "0"){
                    validResponse2 = 1;
                }
            }
            
            
            //quick lil while loop to check if they entered in a 1 or 0
            

            if(playerResponse == "1"){
                //this is what we will return to our main funcion where this function was called
                //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
                wantToPlayAgain = 1;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                cout << "CREATING NEW GAME...." << endl;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
            }else{
                wantToPlayAgain = 0;

                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
                cout << "TURNING OFF GAME DRIVER..." << endl;
                cout << endl;
                cout << "-----------------------------" << endl;
                cout << endl;
            }
        }

        



        
    

        
    }

    //this is what we will return to our main funcion where this function was called
    //if they say they want to play again, then this variable will get returned, causing this fucnion to restart
    return wantToPlayAgain;
}






int main(){

    bool stillPlaying = 1;

    //clear the previous game's score board
    clearScoreBoard("scoreBoard.txt");

    while(stillPlaying == 1){
        //we should display a quick lil menu thing on how to play
        stillPlaying = play();
        
    }
    return 0;
}

//CURRENT UPDATE:

//Changed the include statements to not have the .cpp files just because the TA in recitation told us it was bad practice and you could easily define objects too many times. 
//So only the header files are included now, 
//When you compile type in the console:"g++ -std=c++11 MD.cpp Player.cpp Map.cpp Zombie.cpp Item.cpp Weapon.cpp" and it should compile perfectly.


/*
Anywheres changes I made with this round of working were:
* Made it so the chance to get a key goes up slightly every time the player gets a key, since it starts off as a rare chance.
    Did this primarily so the game isn't too long
* I changed the amount of zombies spawning from 15 to 20 because I did a test run and in 63 turns I won and didn't run into a single zombie. I'd rather there be too many than too little zombies
* Also fixed a bug causing a segmentation fault in my inventory array
* Changed a few of your comments to look more presentable for when we upload, 
    but I didn't change many so you can feel free to change the rest of yours to look more presentable to the TAs, 
    I still need to add comments to the CPP files I made but I'll do that around when we're 100% finished
*Made some minor touch ups to the stats displayed every turn, mainly so they look more symetrical and also added the words end of turn at the bar that is displayed
* I removed the run option from the battle function because the player doesn't move on the map after they run, and even if we made it so, it'd be really easy for the player to immediately run into another zombie. 
    So since it's not a requirement, I just removed it all together. Rest of the battle function is as normal
* I believe I fixed a bug that made battles not end immediately when the player hits 0 HP
* Fixed bug in the weapon class that made it so the weapons didn't reload
* Made it so the player can input their name at the start of the round now

Bugs that still need patching:
*Even with 20 zombies, it still feels light fights are rare, are all of them moving? Or do we still need more zombies?
*/


/*

Final update I believe:

added in the .txt files for the score board and sorting algorithem to sort the leaderboards!

*/