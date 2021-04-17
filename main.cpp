/*
Memory Game

Author: Jacob Cox
*/

#include <iostream>
#include <vector>
#include <string>

#include "game.h"

using namespace std;


int main() {
    int i1, j1, i2, j2;

    game newGame;

    newGame.generateRandomBoard();

    while(newGame.getMatchedCards() < newGame.getNecessaryMatches()){
        newGame.showGame();
        
        cout << "Pick a row for the 1st card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i1;

        //Input validation for i1
        while(!cin ||!(newGame.checkValidRow(i1)) ){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a row for the 1st card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i1;
        }


        cout << "Pick a column for the 1st card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j1;

        //Input validation for j1
        while(!cin || !(newGame.checkValidColumn(j1))){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a column for the 1st card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j1;
        }

        //Checks for already selected card
        if(newGame.checkForInvalidMove(i1, j1)){
            cout << "Can't select an already matched card!" << '\n';
            continue;
        }

        cout << "Pick a row for the 2nd card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i2;

        //Input validation for i2
        while(!cin ||!(newGame.checkValidRow(i2)) ){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a row for the 2nd card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i2;
        }

        cout << "Pick a column for the 2nd card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j2;

        //Input validation for j2
        while(!cin ||!(newGame.checkValidColumn(j2)) ){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a column for the 2nd card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j2;
        }

        //Checks for already selected card
        if(newGame.checkForInvalidMove(i2, j2)){
            cout << "Can't select an already matched card!" << '\n';
            continue;
        }

        //Checks for the same card
        if(i1 == i2 && j1 == j2){
            cout << "Cannot pick the same card!" << '\n';
            continue;
        }
        //Checks for match
        newGame.checkMatch(i1, j1, i2, j2);
    }   
    
    //Outputs moveCount
    cout << "Congratulations!! You finished in " << newGame.getMoveCount() << " moves!" << '\n';

    return 0;
}

