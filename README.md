# Speckers-Game
A c++ class made to represent the Speckers Game

Specker's Game Generalization
This repository contains an implementation of a generalized version of Specker's Game ($\Pi_{n}$), developed as part of the Programming Techniques course at the National Technical University of Athens (NTUA).
Game Description:
The game is a mathematical strategy game involving $p$ players and $n$ heaps of coins. Players take turns in a circular fashion (0 to $p-1$). 
Rules of Playing:
Each turn, the current player must: Choose a source heap ($i$) and a target heap ($j$). Remove $k$ coins ($k > 0$) from the source heap. Place $m$ coins ($0 \le m < k$) into the target heap. Note: If $m=0$, the choice of the target heap is irrelevant. Winning Condition: The game ends when all heaps are empty. The last player to make a valid move wins.
Implementation Structure:
The project is divided into several core components:
1. Move & State ManagementMove Class: Represents a single action, storing the source heap, number of coins removed, target heap, and number of coins added. State Class: Tracks the current number of coins in each heap, the total number of players, and whose turn it is. It includes a next(Move) method to progress the game and handles errors via logic_error exceptions.
 2. Player LogicThe Player class is an abstract base class. This project implements four distinct, deterministic  strategies:

| Player Type | Logic / Strategy | Tie-breaking Rule |
| :--- | :--- | :--- |
| **Greedy** | Selects the heap with the most coins, removes all of them, and adds nothing back. | Smallest heap index. |
| **Spartan** | Selects the heap with the most coins, removes exactly one coin, and adds nothing back. | Smallest heap index. |
| **Sneaky** | Selects the heap with the fewest coins, removes all of them, and adds nothing back. | Smallest heap index. |
| **Righteous** | Selects the heap with the most coins (s). Removes half (rounded up) and adds (half rounded down - 1) to the smallest heap. | Smallest heap index. |

Note: In case of ties (multiple heaps with the same max/min coins), the heap with the lowest index is always chosen.
3. Game EngineThe Game Class orchestrates the execution. It allows for the dynamic addition of heaps and players, then executes the game loop until a winner is found, printing the state transitions to the output stream

ex.
State: 10, 20, 17 with 0/4 playing next
Sneaky player Tom takes 10 coins from heap 0 and puts nothing
State: 0, 20, 17 with 1/4 playing next
...
Greedy player Alan takes 7 coins from heap 2 and puts nothing
State: 0, 0, 0 with 3/4 playing next
Greedy player Alan wins

All the files are needed in order for the game to work. 

You can write for example: 

int main() {
    // 1. Initialize the game with 3 heaps and 4 players [cite: 137]
    Game specker(3, 4);

    // 2. Add the initial coin counts for each heap 
    specker.addHeap(10);
    specker.addHeap(20);
    specker.addHeap(17);

    // 3. Add the players with their specific strategies and names 
    specker.addPlayer(new SneakyPlayer("Tom"));
    specker.addPlayer(new SpartanPlayer("Mary"));
    specker.addPlayer(new GreedyPlayer("Alan"));
    specker.addPlayer(new RighteousPlayer("Robin"));

    // 4. Start the game simulation and output to the console 
    specker.play(cout);

    return 0;
}
