#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>

using namespace std;

class game {
private:
    char ** cardBacks;
    char ** cardValues;
    
    vector<char> values;

    int rows;
    int cols;

    int matchedCards;
    int necessaryMatches;

    int moveCount = 0;

public:
    game(vector<char>);
    void showGame();
    void showValues();

    void generateRandomBoard();
    void showCardValues();

    int getMatchedCards();
    int getNecessaryMatches();
    int getMoveCount();

    bool checkValidRow(int );
    bool checkValidColumn(int );

    void checkMatch(int ,int, int, int);

    bool checkForInvalidMove(int, int);
};

game::game(vector<char> passedValues){
    rows = 2;
    cols = 4;

    matchedCards = 0;
    necessaryMatches = 8;

    values = passedValues;

    cardBacks = new char * [rows];

    for(int i = 0; i < rows; i++){
        cardBacks[i] = new char [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cardBacks[i][j] = 'X';
        }
    }

    cardValues = new char * [rows];

    for(int i = 0; i < rows; i++){
        cardValues[i] = new char [cols];
    }
}

int game::getMatchedCards(){
    return matchedCards;
}

int game::getNecessaryMatches(){
    return necessaryMatches;
}

int game::getMoveCount(){
    return moveCount;
}

void game::showGame(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << cardBacks[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void game::showValues(){
    for(int i = 0; i < values.size(); i++){
        cout << values[i] << " ";
    }
}

void game::generateRandomBoard(){

    vector<char> scrambledValues;
    int randomIndex;

    int count = 0;

    srand (time(NULL));

    while(values.size() > 0){
        randomIndex = rand() % values.size();
        scrambledValues.push_back(values[randomIndex]);
        values.erase(values.begin() + randomIndex);
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cardValues[i][j] = scrambledValues[count];
            count++;
        }
    } 
    
}

void game::showCardValues(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << cardValues[i][j] << " ";
        }
        cout << '\n';
    }
}

bool game::checkValidRow(int r){
    if(r < 0 || r > rows - 1){
        return false;
    }else{
        return true;
    }
}

bool game::checkValidColumn(int c){
    if(c < 0 || c > cols - 1){
        return false;
    } else{
        return true;
    }
}

bool game::checkForInvalidMove(int i, int j){
    if(cardBacks[i][j] != 'X'){
        return true;
    }else{
        return false;
    }
}


void game::checkMatch(int i1 ,int j1, int i2, int j2){
    if(cardValues[i1][j1] == cardValues[i2][j2]){
        cout << "It's a match!!" << '\n';
        cardBacks[i1][j1] = cardValues[i1][j1];
        cardBacks[i2][j2] = cardValues[i2][j2];
        matchedCards += 2;
        moveCount++;
    }else{
        cout << "Not a match..." << '\n';
        cardBacks[i1][j1] = cardValues[i1][j1];
        cardBacks[i2][j2] = cardValues[i2][j2];
        showGame();
        cardBacks[i1][j1] = 'X';
        cardBacks[i2][j2] = 'X';
        moveCount++;
    }
}


