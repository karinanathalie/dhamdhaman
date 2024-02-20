#include <iostream>
#include "printboard.h"
using namespace std;

void printboard(string board[][8]) //This function prints the board array (input) according to dhamdhaman board (output)
{
    for (int i = 0;i<8;i++)
    {
        cout << (8-i) << " ";
        for(int j = 0; j<8;j++)
        {
            cout <<" " << board[i][j] << " |";
            
        }
        cout << endl;
        cout<<"  ---|---|---|---|---|---|---|---|";
        cout << endl;
    }
    cout << "   A   B   C   D   E   F   G   H" << endl;
    
}