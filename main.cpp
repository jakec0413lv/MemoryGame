/*
Memory Game

Author: Jacob Cox

ToDo:

- Add 3 difficulty levels, therefore changing passed char values, and row/column values (update constructor!!)
*/

#include <iostream>
#include <vector>
#include "game.h"


using namespace std;

int main() {
    vector<char> values = {'1', '1', '2', '2', '3', '3', '4', '4'};

    int i1, j1, i2, j2;

    game newGame(values);
    newGame.generateRandomBoard();

    while(newGame.getMatchedCards() < newGame.getNecessaryMatches()){
        newGame.showGame();
        cout << "Pick a row for the 1st card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i1;

        while(!cin){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a row for the 1st card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i1;
        }

        while(!(newGame.checkValidRow(i1))){
            cout << "Pick a valid row number: "<< '\n';
                cin >> i1;
                while(!cin){
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Pick a valid row number: " << '\n';
                        cin >> i1;
                }
        }

        cout << "Pick a column for the 1st card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j1;

        while(!cin){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a column for the 1st card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j1;
        }


        while(!(newGame.checkValidColumn(j1))){
            cout << "Pick a valid column number: "<< '\n';
                cin >> j1;
                while(!cin){
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Pick a valid column number: " << '\n';
                        cin >> j1;
                }
        }

        if(newGame.checkForInvalidMove(i1, j1)){
            cout << "Can't select an already matched card!" << '\n';
            continue;
        }

        cout << "Pick a row for the 2nd card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i2;

        while(!cin){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a row for the 2nd card [Note: Rows Begin @ 0]: " << '\n';
            cin >> i2;
        }

        while(!(newGame.checkValidRow(i2))){
            cout << "Pick a valid row number: "<< '\n';
                cin >> i2;
                while(!cin){
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Pick a valid row number: " << '\n';
                        cin >> i2;
                }
        }

        cout << "Pick a column for the 2nd card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j2;

        while(!cin){
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Pick a column for the 2nd card [Note: Columns Begin @ 0]: " << '\n';
            cin >> j2;
        }

        while(!(newGame.checkValidColumn(j2))){
            cout << "Pick a valid column number: "<< '\n';
                cin >> j2;
                while(!cin){
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Pick a valid column number: " << '\n';
                        cin >> j2;
                }
        }

        if(newGame.checkForInvalidMove(i2, j2)){
            cout << "Can't select an already matched card!" << '\n';
            continue;
        }

        if(i1 == i2 && j1 == j2){
            cout << "Cannot pick the same card!" << '\n';
            continue;
        }

        newGame.checkMatch(i1, j1, i2, j2);
    }
    
    cout << "Congratulations!! You finished in " << newGame.getMoveCount() << " moves!" << '\n';

    return 0;
}

