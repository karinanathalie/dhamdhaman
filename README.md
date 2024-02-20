# Welcome to Dham Dhaman!
By Group 28:
- Benita, Stacia (3036094289)
- Bryan, Kevin (3036103535)
- Lesmana, Eliza (3036037279)
- Nathalie, Karina (3036037267)
- Tanto, Caroline Avery (3036098625)

Dham-dhaman is a traditional board game from Yogyakarta, Indonesia. This board game allows players to train their brains and practice thinking critically about the consequences of their decisions. In real life, we play Dham-dhaman on a board with pebbles. 

## How to play?
- This is a 2-player game: Player 1 - X; Player 2 - O. Each player has 12 pieces
- The main objective of this game is to take all of your opponent’s pieces. 
- Players can move by inputting the piece number ([A-H]+[1-8]) and the movement direction ( UL: Up Left, UR: Up Right, DL: Down Left, DR: Down Right, EUL: Eat Up Left, EUR: Eat Up Right, EDL: Eat Down Left, EDR: Eat Down Right). 
- For Player 1: DL & DR movements are limited until you have reached the other side of the board.
- For Player 2: UL & UR movements are limited until you have reached the other side of the board.
- You can only move to an empty spot (‘.’). Unless your movement of choice has the opponent's piece and the +1 spot is empty. Stepping over an opponent’s piece will make it eliminated.
- After eliminating an opponent’s piece, the player can move again until there is no possible movement  that can eliminate other opponent’s pieces.
- To eliminate opponent’s pieces, you can type the eat direction movement (EUL, EUR, EDL, EDR).

### Restrictions
- Player 1 starts with two movements : UL & UR
- Player 2  starts with two movements : DL & DR
- No stacking before reaching the other side of the board; Stacking is only possible at the end of the board 
- Can only move diagonally (No illegal move such as Left, Right, Up, Down)

## How to execute our game?
### For HKU Staff and Students
1. Download our file by clicking the button “<> Code”, choosing the button “Download ZIP”, and decompressing the folder in your local folder
2. Open FileZilla and move the folder to your server (Make sure you are connected to the HKU VPN)
3. Open your Terminal or Command Prompt and log in into your CS account in academy server in our CS department can be accessed by using an SSH connection
4. Change your current working directory to our folder
5. Execute our code by type the make command
```bash
make main
```
6. To start playing our game, you can type
```bash
./main
```
7. And Done! Enjoy the game!
8. To remove all the executable files, you can type the clean command
```bash
make clean
```


### For Non-HKU Staff or Non-HKU Students
1. Download our file by clicking the button “<> Code”, choosing the button “Download ZIP”, and decompressing the folder in your local folder
2. Open the folder in your source-code editor or compiler
3. Execute our code by type the make command
```bash
make main
```
4. To start playing our game, you can type
```bash
./main
```
5. And Done! Enjoy the game!
6. To remove all the executable files, you can type the clean command
```bash
make clean
```

## Features
1. **Home page** 
<br>The homepage of Dham Dhaman Game features ASCII art for aesthetic purposes and offers users the ability to select game modes, access instructions on how to play, and view past game history.<br>
    <br><img width="661" alt="Homepage" src="https://user-images.githubusercontent.com/66895081/236405228-6966df28-40ce-4e9f-881b-f0d3be67f389.png">

2. **How to play** 
<br>This animation incorporates a clear screen and time delay function to create the appearance of movement, effectively visualizing the game and aiding user comprehension. <br>
    <br><img width="517" alt="How to play 1" src="https://user-images.githubusercontent.com/66895081/236405813-b9c1c547-c1e7-47c4-91d3-479141fdc94d.png"> <img width="693" alt="How to play 2" src="https://user-images.githubusercontent.com/66895081/236405825-106b6e25-7852-44a1-8c2a-81759af489eb.png">

3. **Play with your partner** 
<br>The first game mode which enables two players to engage in a one-on-one match. <br>
    <br><img width="451" alt="Multiplayer game" src="https://user-images.githubusercontent.com/66895081/236408079-0bf7ae11-ed5b-44d5-8fd4-7363045a1f20.png">

4. **Play vs Comp** 
<br>The second game mode which allows players to engage in a one-on-one competition with a computer<br>
    <br><img width="449" alt="Play Vs Comp" src="https://user-images.githubusercontent.com/66895081/236408823-1bf21b4c-765e-41c3-87ac-ad0f1ef164c9.png">

5. **Closing Animation** 
<br>The closing animation serves to indicate the outcome of a game, displaying the winning player and whether the player has emerged victorious or been defeated by the computer opponent<br>
    <br><img width="431" alt="Closing Animation" src="https://user-images.githubusercontent.com/66895081/236409539-97a1a05a-e60a-4f94-b004-f11c8f00cdbd.png">

6. **History** 
<br>The game's historical record displays pertinent details, such as the start time of each match, the players' moves, and the winning player of each game.<br>
    <br><img width="334" alt="History" src="https://user-images.githubusercontent.com/66895081/236409417-e5f9d834-0faa-4031-b955-1a90f3d23062.png">

## Course Material Implementation
1.  **Generation of random game sets or events** 
<br> The Player vs Computer mode utilizes a random generator to generate game sets or events.

2. **Data structures for storing game status** 
<br> The game employs data structures to store game status, including the board and available moves.

3. **Dynamic memory management**
<br> The program uses dynamic memory management to optimize performance.

4. **File input/output (e.g., for loading/saving game status)**
<br> The game supports file input/output for saving game history and saving game history and outputting the file when being asked by user.

5. **Program codes in multiple files**
<br> The program codes are organized into multiple files for better code management and maintainability.

6. **Proper indentation and naming styles**
<br> The code follows proper indentation and naming styles, making it easy to read and understand.

7. **In-code documentation**
<br> The code includes in-code documentation to improve readability and facilitate future development.