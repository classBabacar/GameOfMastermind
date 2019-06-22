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
    void displayResult(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int maxSize, int choose);
    void resultPatternOne(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int maxSize);
    void resultPatternTwo(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int maxSize);
    void resultPatternThree(int notInSecret, int correctlyPlaced, int incorrectlyPlaced, int counter, int maxSize);

private:
    string password;
};
