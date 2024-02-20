#include <iostream>
#include <string>
#include "animation.h"
#include "Posmove.h"
#include "CheckWin.h"
#include "printboard.h"
#include "historynotes.h"
#include "play.h"
#include "vsComp.h"
#include "playvscomp.h"

using namespace std;

int main()
{   
    //INTRODUCTION
    int input, turns=1;
    bool game_end = false;
    string mode = "multiplayer";
    HomePage(); //Calling the HomePage() function from animation.cpp to print welcoming message and show the menu for users to choose
    cin >> input;
    while (input != 1 && input != 2){ 
        if (input == 3){ 
            clear_screen(); //Calling clear_screen() function from animation.cpp to clear the screen
            HowtoPlay(); //Calling HowtoPlay() function from animation.cpp to show the tutorial of the game
            HomePage();
        }
        if (input == 4){
            output_history(); //Calling output_history() function from historynotes.cpp to print the game history
            delay(); //Calling delay() function from animation.cpp to give delay
            HomePage();
        }
        cin >> input;
        cout << endl;
    }
    write_history(); //Calling write_history() function from historynotes.cpp to write the header of history notes files
    
    string player = "PLAYER 1";

    //GAME STARTS HERE   
    if (input == 2){ 
        mode = "comp";
        player = playvscomp(); //Calling playvscomp() function from playvscomp.cpp to start the game for Player vs Computer
    }
    else if (input == 1){ 
        player = play(); //Calling play() function from play.cpp to start the game for Player vs Player
    }

    //CLOSING
    historywin(player); //Calling the historywin(string player) function from historynotes.cpp to record the winner of the game
    if (mode == "comp"){
        if(player == "PLAYER"){  
            closing_vscomp(true); //Print closing if users win
        }
        else{
            closing_vscomp(false); //Print closing if comp wins
        }

    }
    else{
        closing_multiplayer(player); //Print closing and show winner (for Player vs Player)
    }
    
    return 0;
}
