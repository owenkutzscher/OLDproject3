
//CSCI 1300 
//Authors: Reece Benson, Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class





/*

//// this is some code that I edited, Idk if reece used it on his version, so ill paste it in if his version doesnt have this


//we need to add something to make it so players cant enter a name with a comma in it!!
//this is to check if the player has won the game
    //if the player has won, slightly different things will occur at the very end
    bool playerHasWon = 0;








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

                //lastly, since they won, automatily display the leaderboards sorted
                //def make this a function
                
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

        
















score board driver!!!
 this is just to test out some functions


//now that they've died, lets record their name in the scoreBoard.txt file
//they will be stored in a very specific way so its easy to get the names back, and 
// then display them in order from best to worst. Followed by players who didn't finish the game
////////
//EX: 
//player.getPlayerName() ... "Reeceowen"
//turns ... 27
//written into scoreBoard.txt as: "Reeceown,27"


//soooo

//lets make a function to erase all the leader boards. That can
// be called before the game starts if the scoreBoard.txt file isnt empty by default
    //erase the scoreBoard.txt file

//lets make a function to add names to the leaderboard
    //adds a playerName,numTurns to the scoreBoard.txt file

//lets make a function to read the lederboards,
// we'll make sure to display the names in ranked order
    //adds the player's name to a vector of players names
    //adds the players score to a vector of players scores

    //sorts the vector of scores, anything it swaps in the sores vector, 
    // it also swaps in the same players name so that they stay in synch
    //then after it is done, it prints out the names and their scores in order in some fancy way



*/



#include <iostream>
//#include <string>
#include <cstring>
#include <fstream>

#include "Player.cpp"
#include "Map.cpp"

using namespace std;



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
            cout << "text to add is: " << textToAdd << endl;
            openedFile.write(textToAdd.data(), textToAdd.size());
        }
        
    }

    openedFile.close();
}


int main(){


    //below is some stuff I used to test out the funcitons
    //I put the stuff below into the .txt files
    /*  
    owen,69

    cheese head,420
    balls in ya mouth, 333
    wacha ma call ittt, 77
    twinkie, 3
    */


    cout << "clearing score board...." << endl;
    clearScoreBoard("scoreBoard.txt");
    

    cout << "trying to add 3 names to scoreBoard.txt....." << endl;
    addToScoreBoard("scoreBoard.txt", "poopie head", 512);
    addToScoreBoard("scoreBoard.txt", "cheese mo", 25);
    addToScoreBoard("scoreBoard.txt", "mr sex", 55);

    //cout << "trying to clear the score board" << endl;
    //clearScoreBoard("scoreBoard.txt");



    readScoreBoard("scoreBoard.txt");


    return 0;
}




