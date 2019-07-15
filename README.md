
# Inspiration
- In 1977, Donald Knuth implementend an algorithm to solve the game, Mastermind. The algorithm says you can solve a pattern in 5 or fewer moves granted if the set of pegs = 4. I've played the game before and thought it was very interesting so I decided to make the game and apply his algorithm to it and see what I can learn.
https://en.wikipedia.org/wiki/Mastermind_(board_game)


# Tutorial Phase (6/22/19)
- The game at first can be a little tricky and I want the people to understand how it's played. So if you've never played mastermind go through the tutorial I hope I explained it well.

# Human v AI (7/14/2019)
- The human v AI aspect is complete. This part is primarly where the AI generates a secret code and you the user have to guess it. I played a lot of games and its interesting how to go about solving a secret pattern with 4 pegs compared to 7. When I re-implement Donald Knuths Algorithm I will try to be a bit more creative and insert my approach when I have an AI guess a users secret word.

# Update
- **6/29/2019** Menu added and way to generate a random color, I'm most likely going to use a struct to minimize the game and make it easier to handle.

- **7/4/2019** Added a authentication system to make sure the game wouldn't debunk at random spots now all that is left is the results algorithm and I'm thinking of a way to make the game appealing in the results stage.

- **7/6/2019** Structs are GREAT!!! It makes the code packagable and it helps with readibility I think.

# Running Code

I recommend that you compile with ``make build`` or ``make``

Run the program with ``./game``

To delete the ``./game`` do:

 ``make clean``
