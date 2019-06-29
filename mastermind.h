#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"
using namespace std;

class mastermind
{
public:
    //Tutorial
    void differentColorsTutorial();
    void userGuideline();
    void scenarioOne();
    void scenarioTwo();
    void scenarioThree();

    //GameTime Functions
    string stringToColor(string password);

    //Random Sequences
    void displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize, int choose);
    void resultPatternOne(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);
    void resultPatternTwo(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);
    void resultPatternThree(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int colorSize);

    //AI functionality
    void aiPlay(int totalColors);
    string generateSecret(int totalColors);

private:
    string password;
};
