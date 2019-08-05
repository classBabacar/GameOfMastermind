#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <time.h>
#include <iomanip> // std::setw
#include <ctype.h>
#include "colors.h"
#include "playersChose.h"

using namespace std;

class mastermind
{
public:
    //constructor
    mastermind();

    //Tutorial
    void differentColorsTutorial();
    void userGuideline();
    void scenarioOne();
    void scenarioTwo();
    void scenarioThree();

    //GameTime Functions
    string stringToColor(string password);
    string authenticateGuess(int totalColors);
    bool checkValidColors(string userGuess);
    void displayFeedback(int totalColors);
    void helpUserSeeColors(int totalColors);
    void setDisplay(int &counter,int colorSize);

    // Struct-User Specific Functions
    playerChose setPlayerInstance(string userGuess, string secretCode, int tries, int randomizer);
    getResults resultAlgorithm(string userGuess, string secretCode, int totalColors);
    string resultMessage(char isWho);
    bool checkSet(int wordLocation, set<int> coordinateSet);

    //Random Sequences
    void displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize, int randomizer);
    void resultPatternOne(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);
    void resultPatternTwo(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);
    void resultPatternThree(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);

    //AI functionality
    void aiPlay(int totalColors);
    string generateSecret(int totalColors);

private:
    int attempts;
    char colors[7];
    vector<playerChose> myPieces;
};
