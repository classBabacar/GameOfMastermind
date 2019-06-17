#include <iostream>
#include "colors.h"
using namespace std;

class mastermind
{
public:
    //Tutorial
    void differentColorsTutorial();
    void userGuideline();
    void scenarioOne();

    //GameTime Functions
    string stringToColor(string password);
    string displayResult(int correctlyPlaced, int notInSecret, int incorrectlyPlaced);

private:
    string password;
};
