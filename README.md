
# Inspiration
- In 1977, Donald Knuth implementend an algorithm to solve the game, Mastermind. The algorithm says you can solve any pattern in 5 or fewer turns granted if the set of pegs = 4. I've played the game before and thought it was very interesting so I decided to make the game and apply his algorithm to it and see what I can learn.
https://en.wikipedia.org/wiki/Mastermind_(board_game)

- I decided I'm going to also include another algorithm which is called, Swaszek strategy which was discovered in 2000. This should be intersting, because I'm gonna allow users to use both Knuth's and Swaszek's algorithm to determine which one they like more from a algorithmic standpoint. I'm going to see how these algorithms scales as the #ofpegs increases. It should be fun!!!

# Tutorial Phase (6/22/19)
- The game at first can be a little tricky and I want the people to understand how it's played. So if you've never played mastermind go through the tutorial I hope I explained it well.

# Human v AI (7/14/2019)
- The human v AI aspect is complete. This part is primarly where the AI generates a secret code and you the user have to guess it. I played a lot of rounds and it's very interesting on how you can go about solving a secret pattern with 4 pegs compared to 7. When I re-implement Donald Knuth's Algorithm I will try to be a bit more creative and insert my approach when I have an AI guess a users secret word.

# Swaszek's Algorithm (8/5/2019)
1. You the user have to think of a color pattern ideally with 4 pegs (repitions or not)...example (rgby -> red green blue yellow). I was thinking to have the user enter the secret code but some people wouldn't believe so it's best to keep it in your mind haha.
2. Instead of the AI giving you feedback (Human V. AI), the game is reversed so for each round the AI will ask for it's black and white peg total.

> You should be able to notice how the algorithm works...it's pretty cool and how it eliminates varying possibilities. In some of the articles they say this algorithm is less computationally demanding than Knuth's method but we'll see!

# Update
- **6/29/2019** Menu added and way to generate a random color, I'm most likely going to use a struct to minimize the game and make it easier to handle.

- **7/4/2019** Added a authentication system to make sure the game wouldn't debunk at random spots now all that is left is the results algorithm and I'm thinking of a way to make the game appealing in the results stage.

- **7/6/2019** Structs are GREAT!!! It makes the code packagable and it helps with readibility.

# Docker Rules
Since operating systems are so specific about their color codes, I couldn't make this program work on both windows and linux. However, with the help of docker this problem is solved slightly...which can allow users to simulate a OS (simply put).

Step 1 : Download Docker For Desktop or Docker-Toolbox.

Step 2 : In the **Connect4WithAi** directory, do the following : ``docker build -t test . ``

Step 3 : Next : `` docker run -it test /bin/sh ``

Step 4 : Now you are in the Docker shell and can operate it as if it was a linux machine.

Step 5 : Read the part of this README that says : `` Running Code using Makefile``

# Running Code using Makefile

I recommend that you compile with ``make build`` or ``make``

Run the program with ``./game``

To delete the ``./game`` do:

 ``make clean``
