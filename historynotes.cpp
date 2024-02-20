#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "historynotes.h"
using namespace std;

/* To print the last played information file (history.txt)
It'll print the line one by one until eof.
*/
void output_history() {
    string line;
    bool isEmpty = true;
    ifstream fin;
    fin.open("history.txt");
    if ((fin.eof() && (isEmpty == true))||fin.fail()) {
        // file is empty or doesn't exist
        cout << "History does not exist! You need to play first" <<endl;
    }
    else {
        // output the content of history
        isEmpty = false;
        while (getline(fin, line)) {
            cout << line << endl;
        }
    }
    fin.close();
}

/* To make new or overwrite file
It'll create new history.txt with the date/time for the current game.
*/
void write_history() {
    time_t now = time(0);  // current date/time
    char* timeNow = ctime(&now); // convert now to string form
    ofstream fout;
    fout.open("history.txt");
    fout << "Dham Dhaman Game" << endl;
    fout << "----------------" << endl;
    fout << "Time and Date: " << timeNow << endl;
    fout << "Moves: " << endl;
    fout.close();
}

/* To record every moves made by player
takes 3 string parameters, the player's name, the movement made, and the piece, from the current play()/playvscomp()
It'll append history.txt with the move choice.
*/
void appendhistory(string player, string move, string piece){ 
    ofstream fout;
    fout.open("history.txt",ios::app);
    if(fout.fail()){
        fout<<"There has been some failure in recording the moves"<<endl;
    }
    else{
        fout<<player<<" chose piece "<<piece<<" and moved it "<<move<<endl;
    }
    fout.close();
}

/* To record last played game winner
takes 1 string parameter, the player's name, from the play()/playvscomp() return value
It'll append the last line of history.txt
*/
void historywin(string player){ 
    ofstream fout;
    fout.open("history.txt",ios::app);
    if(fout.fail()){
        fout<<"player's not recorded"<<endl;
    }
    else{
        fout<<player<<" won the game! \\(^o^)/"<<endl;
    }
    fout.close();
}