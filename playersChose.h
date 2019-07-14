struct playerChose
{
    // Storing user Guess
    string userGuess;

    // storing how many tries they had at that time
    int tries;

    // making sure the output is relative to the random output of the vector
    int chosenOutput;

    //Secret Code Response
    int notinSecret;
    int correctlyPlaced;
    int incorrectlyPlaced;
};

// A struct to store results relative of the user
struct getResults
{
    int notinSecret;
    int correctlyPlaced;
    int incorrectlyPlaced;
};