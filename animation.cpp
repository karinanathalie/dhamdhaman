//animation.cpp
//include introduction, homepage, and closing
//Define Sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <string>
#include "animation.h"
#include "printboard.h"
using namespace std;

//Function to clear the screen (no return value and no input parameters)
void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system ("clear");
    #endif
}

//Function to delay the output before clear the screen (no return value and no input parameters)
void delay(){
    #ifdef _WIN32
        Sleep(5000);
    #else
        sleep(5);
    #endif
}

//Function to delay 10 seconds for visualization
void delay_vis(){
    #ifdef _WIN32
        Sleep(10000);
    #else
        sleep(10);
    #endif
}

//Function to delay 2 seconds for the closing
void delay_closing(){
    #ifdef _WIN32
        Sleep(2000);
    #else
        sleep(2);
    #endif
}

//Function to output the homepage (no return value and no input parameters)
void HomePage(){      
    cout << "               __    __     _                             _____                                      " << endl;
    cout << "              / / /\\ \\ \\___| | ___ ___  _ __ ___   ___   /__   \\___                             " << endl;
    cout << "              \\ \\/  \\/ / _ | |/ __/ _ \\| '_ ` _ \\ / _ \\    / /\\/ _ \\                        " << endl;
    cout << "               \\  /\\  |  __| | (_| (_) | | | | | |  __/   / / | (_) |                              " << endl;
    cout << "                \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|   \\/   \\___/                         " << endl;

    cout << ",------.  ,--.                       ,------.  ,--.                                                " << endl;    
    cout << "|  .-.  \\ |  ,---.  ,--,--.,--,--,--.|  .-.  \\ |  ,---.  ,--,--.,--,--,--. ,--,--.,--,--,        " << endl; 
    cout << "|  |  \\  :|  .-.  |' ,-.  ||        ||  |  \\  :|  .-.  |' ,-.  ||        |' ,-.  ||      \\      " << endl; 
    cout << "|  '--'  /|  | |  |\\ '-'  ||  |  |  ||  '--'  /|  | |  |\\ '-'  ||  |  |  |\\ '-'  ||  ||  |      "<< endl; 
    cout << "`-------' `--' `--' `--`--'`--`--`--'`-------' `--' `--' `--`--'`--`--`--' `--`--'`--''--'         "<< endl;    

    cout << "1. Play With Your Partner" << endl;  
    cout << "2. Play vs Comp" << endl; 
    cout << "3. How to Play?" << endl;
    cout << "4. Check Last Played History" << endl;                                                                    
}

//Function to output the board visualization (no return value and no input parameters)
void visualization(){
    string board1[8][8]{
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", "x", " ","x", " ","x", " ","x"},
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", ".", " ", "."," ", "."," ", "."},
        {".", " ", "."," ", "."," ", "."," "},
        {" ", "o", " ","o", " ","o", " ","o"},
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ", "o", " ","o", " ","o", " ","o"}
    };
    
    //Explaining Condition
    printboard(board1);
    cout << endl;
    cout << "Suppose you are in a game of 8 vs 8 board and your pieces are represented by o" << endl;
    cout << "The dot on the map indicates the area you can go to." << endl;
    cout << "To make a move, simply type in the piece you want to move and the direction you want it to go." << endl;
    cout << "Let's type 'B3' and 'UL' (Up Left) for this one." << endl;
    delay_vis();
    clear_screen();

    //Explaining how to move part 1
    string board2[8][8]{
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", "x", " ","x", " ","x", " ","x"},
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", ".", " ", "."," ", "."," ", "."},
        {"o", " ", "."," ", "."," ", "."," "},
        {" ", ".", " ","o", " ","o", " ","o"},
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ", "o", " ","o", " ","o", " ","o"}
    };
    printboard(board2);
    cout << endl;
    cout << "Look! The piece we chose has been moved to B4 right now!" << endl;
    cout << "Now, it's your opponent's turn. Suppose they choose 'C6' and 'DL' (Down Left)" << endl;
    delay_vis();
    clear_screen();

    //Explaining how to move part 2
    string board3[8][8]{
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", "x", " ","x", " ","x", " ","x"},
        {"x", " ", ".", " ","x", " ","x", " "},
        {" ", "x", " ", "."," ", "."," ", "."},
        {"o", " ", "."," ", "."," ", "."," "},
        {" ", ".", " ","o", " ","o", " ","o"},
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ", "o", " ","o", " ","o", " ","o"}
    };
    printboard(board3);
    cout << endl;
    cout << "Look! The piece they chose has been moved to B5 right now!" << endl;
    cout << "Here, We can move our piece 'A4' to 'EUR' (Eat Up Right)" << endl;
    cout << "Don't forget! Stepping over an opponent’s piece will make it eliminated." << endl;
    delay_vis();
    clear_screen();

    //Explaining how to eat
     string board4[8][8]{
        {"x", " ", "x", " ","x", " ","x", " "},
        {" ", "x", " ","x", " ","x", " ","x"},
        {"x", " ", "o", " ","x", " ","x", " "},
        {" ", ".", " ", "."," ", "."," ", "."},
        {".", " ", "."," ", "."," ", "."," "},
        {" ", ".", " ","o", " ","o", " ","o"},
        {"o", " ", "o", " ","o", " ","o", " "},
        {" ", "o", " ","o", " ","o", " ","o"}
    };
    printboard(board4);
    cout << endl;
    cout << "Look! The opponent's piece on B5 is gone! " << endl;
    cout << "You can now move another pieces and enjoy the game!" << endl;
    delay_vis();
    clear_screen();
}

//Function to output the animation about how to play the game (no return value and no input parameters)
void HowtoPlay(){
    //introduction about dhamdhaman
    cout << "                      .-----------------------------------.   " << endl;
    cout << "                      | DhamDhaman is a traditional board |   " << endl;
    cout << "                      | game from Yogyakarta, Indonesia   |   " << endl;
    cout << "                     /.-----------------------------------.   " << endl;
    cout << "                O /                                           " << endl;
    cout << "               /|/                                            " << endl;
    cout << "                |\\                                           " << endl;
    cout << "                | \\                                          " << endl;
    cout << "       ^^^^^^^^^^^^^^^^^^^^^                                  " << endl;
    cout << "                                                              " << endl;
    delay();
    clear_screen();

    cout << "                      .----------------------------------------------    " << endl;
    cout << "                      | This is a 2-player game. The pieces are      |   " << endl;
    cout << "                      | presented by X and O. To win this game, you  |   " << endl;
    cout << "                      | need to take all of your opponent\'s pieces.  |   " << endl;
    cout << "                     /.----------------------------------------------    " << endl;
    cout << "                O                                                        " << endl;
    cout << "               \\|\\/                                                   " << endl;
    cout << "                |\\                                                     " << endl;
    cout << "                | |                                                     " << endl;
    cout << "       ^^^^^^^^^^^^^^^^^^^^^                                            " << endl;
    cout << "                                                                        " << endl;
    delay();
    clear_screen();
   
    //explaining how to input
    cout << "                      .---------------------------------------------------  " << endl;
    cout << "                      | Don't get confused! Let's just visualize the game |   " << endl;
    cout << "                     /.---------------------------------------------------   " << endl;
    cout << "                 O /                                                        " << endl;
    cout << "                <|/                                                         " << endl;
    cout << "                / \\                                                        " << endl;
    cout << "               /   |                                                       " << endl;
    cout << "       ^^^^^^^^^^^^^^^^^^^^^                                               " << endl;
    cout << "                                                                           " << endl;
    delay();
    clear_screen();

    //board visualization
    visualization();

    //explaining restrictions
    cout << "                      .---------------------------------------------------------    " << endl;
    cout << "                      | Remember you can only move diagonally and no stacking   |   " << endl;
    cout << "                      | stacking allowed before you reach the other side of the |   " << endl;
    cout << "                      | board! Don't worry possible moves will be provided !    |   " << endl;
    cout << "             !!!     /.---------------------------------------------------------   " << endl;
    cout << "                 O                                                                 " << endl;
    cout << "                <|>                                                                " << endl;
    cout << "                / \\                                                               " << endl;
    cout << "               /   |                                                                " << endl;
    cout << "       ^^^^^^^^^^^^^^^^^^^^^                                                       " << endl;
    cout << "                                                                                   " << endl;    
    delay();
    clear_screen();
    

    //explaining the winning condition
    cout << "                      .---------------------------------------------   " << endl;
    cout << "                      | After you take all your opponent's pieces, |   " << endl;
    cout << "                      | you win! So, what are you waiting for?     |   " << endl;
    cout << "                      | You are excited, aren't you? Let's start!  |   " << endl;
    cout << "                  ^^  /.--------------------------------------------    " << endl;
    cout << "                 O __                                                    " << endl;
    cout << "                /|                                                      " << endl;
    cout << "                / \\                                                    " << endl;
    cout << "               /  \\                                                    " << endl;
    cout << "       ^^^^^^^^^^^^^^^^^^^^^                                            " << endl;
    cout << "                                                                         " << endl;
    delay();
    clear_screen();
}

// Closing animation take x as the input parameter for winner (whether PLAYER 1 or PLAYER 2) (no return value)
void closing_multiplayer(string x){
    clear_screen();
    cout <<"  \\   /                                         \\   /     " << endl; 
    cout <<"   \\O/                                           \\O/      " << endl;
    cout <<"    |    !!!! " << x <<  " WINS THE GAME !!!!         |       " << endl;  
    cout <<"   / \\                                           / \\      " << endl; 
    cout <<"  /   \\                                         /   \\     " << endl;
    
    delay_closing();
    clear_screen();
    cout << "                                                           " << endl;                                                          
    cout << "    O                                            O       " << endl; 
    cout << "  / | \\  !!!! " << x << " WINS THE GAME !!!!      / | \\ " << endl;      
    cout << "   / \\                                          / \\     " << endl;    
    cout << "  /   \\                                        /   \\    " << endl;

    delay_closing();
    clear_screen();
    cout <<"  \\   /                                         \\   /     " << endl; 
    cout <<"   \\O/                                           \\O/      " << endl;
    cout <<"    |     !!!! " << x <<  " WINS THE GAME !!!!        |       " << endl;  
    cout <<"   / \\                                           / \\      " << endl; 
    cout <<"  /   \\                                         /   \\     " << endl;

    delay_closing();
    clear_screen();
    cout << "                                                           " << endl;                                                          
    cout << "    O                                            O       " << endl; 
    cout << "  / | \\  !!!! " << x << " WINS THE GAME !!!!      / | \\ " << endl;      
    cout << "   / \\                                          / \\     " << endl;    
    cout << "  /   \\                                        /   \\    " << endl;
}

// Closing animation take win_status as the input parameter (whether true (win) or lose (false)) (no return value)
void closing_vscomp(bool win_status){
    if(win_status == true){
        clear_screen();
        cout <<"  \\   /                                  \\   /     " << endl; 
        cout <<"   \\O/                                    \\O/      " << endl;
        cout <<"    |       !!!! YOU WIN THE GAME !!!!     |         " << endl;  
        cout <<"   / \\                                    / \\      " << endl; 
        cout <<"  /   \\                                  /   \\     " << endl;

        delay_closing();
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "    O                                       O      " << endl; 
        cout << "  / | \\    !!!! YOU WIN THE GAME !!!!     / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;

        delay_closing();
        clear_screen();
        cout <<"  \\   /                                  \\   /     " << endl; 
        cout <<"   \\O/                                    \\O/      " << endl;
        cout <<"    |       !!!! YOU WIN THE GAME !!!!     |         " << endl;  
        cout <<"   / \\                                    / \\      " << endl; 
        cout <<"  /   \\                                  /   \\     " << endl;

        delay_closing();
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "    O                                       O      " << endl; 
        cout << "  / | \\    !!!! YOU WIN THE GAME !!!!     / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;
    }
    else if(win_status == false){
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "   . .                                     . .     " << endl; 
        cout << "  / | \\    :( YOU LOSE THE GAME :(        / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;   

        delay_closing();
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "   T T                                     T T     " << endl; 
        cout << "  / | \\    :( YOU LOSE THE GAME :(        / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;  

        delay_closing();
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "   . .                                     . .     " << endl; 
        cout << "  / | \\    :( YOU LOSE THE GAME :(        / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;   

        delay_closing();
        clear_screen();
        cout << "                                                    " << endl;                                                          
        cout << "   T T                                     T T     " << endl; 
        cout << "  / | \\    :( YOU LOSE THE GAME :(        / | \\   " << endl;      
        cout << "   / \\                                     / \\    " << endl;    
        cout << "  /   \\                                   /   \\   " << endl;   
    }

}