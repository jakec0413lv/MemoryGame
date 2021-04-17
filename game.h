#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>
#include <string>

using namespace std;

class game {
private:
    string ** cardBacks;
    string ** cardValues;
    
    vector<string> values;

    int rows;
    int cols;

    int matchedCards;
    int necessaryMatches;

    int moveCount = 0;

public:
    game();
    ~game();
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

game::game(){

    int difficulty;

    vector<string> easyValues = {"1", "1", "2", "2", "3", "3", "4", "4"};
    vector<string> mediumValues = {"1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6","6", "7", "7", "8", "8"};
    vector<string> hardValues = {"1", "1", "2", "2", "3", "3", "4", "4", "5", "5", "6","6", "7", "7", "8", "8", 
                                 "9", "9", "10", "10", "11", "11", "12", "12", "13", "13", "14","14", "15", "15", "16", "16"};

    cout << "Choose a difficulty [1 - [8 cards], 2- [16 cards], 3 [32 Cards]]" << '\n';
        cin >> difficulty;
    
    while(!cin || (difficulty != 1 && difficulty != 2 && difficulty != 3)){
        cin.clear();
        cin.ignore(40, '\n');
        cout << "Choose a difficulty [1 - [8 cards], 2- [16 cards], 3 [32 Cards]]" << '\n';
        cin >> difficulty;
    }

    if(difficulty == 1){
        rows = 2;
        cols = 4;
        matchedCards = 0;
        necessaryMatches = 8;
        values = easyValues;
    }

    if(difficulty == 2){
        rows = 4;
        cols = 4;
        matchedCards = 0;
        necessaryMatches = 16;
        values = mediumValues;
    }

    if(difficulty == 3){
        rows = 4;
        cols = 8;
        matchedCards = 0;
        necessaryMatches = 32;
        values = hardValues;
    }

    cardBacks = new string * [rows];

    for(int i = 0; i < rows; i++){
        cardBacks[i] = new string [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cardBacks[i][j] = "X";
        }
    }

    cardValues = new string * [rows];

    for(int i = 0; i < rows; i++){
        cardValues[i] = new string [cols];
    }
}
game::~game(){
    for(int i = 0; i < rows; i++){
        delete [] cardValues[i];
        delete [] cardBacks[i];
    }
    delete [] cardValues;
    delete [] cardBacks;
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
    cout << "  ";
    for(int i = 0; i < cols; i++){
        cout << i << ' ';
    }
    cout << '\n';
    cout << "--------------------" << '\n';
    for(int i = 0; i < rows; i++){
        cout << i << "|";
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

    vector<string> scrambledValues;
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
    if(cardBacks[i][j] != "X"){
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
        cardBacks[i1][j1] = "X";
        cardBacks[i2][j2] = "X";
        moveCount++;
    }
}


