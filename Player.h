#ifndef Player_Header
#define Player_Header
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

vector <char> num {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
vector <char> playerXO {'X','O'}; 
int position;
char currentPlayer;
bool turn;

class Game {  
    public:
    void board() {
        int numRows = 3;    
        int numCols = 3;  
        int index;

        for (int i = 0; i < numRows; i++) {  
            for (int j = 0; j < numCols; j++) {
                index = i * numCols + j;
                cout << num[index];

                if (j < numCols - 1) {
                    cout << " | ";
                }
            }   
            cout << endl;
            if (i < numRows - 1) {
                cout << "---------\n";
            }
        }
    }
    
    bool win() {

    // Row
    bool winRow1 = (num[0] == num[1]) && (num[1] == num[2]);
    bool winRow2 = (num[3] == num[4]) && (num[4] == num[5]);
    bool winRow3 = (num[6] == num[7]) && (num[7] == num[8]);

    // Column
    bool winCol1 = (num[0] == num[3]) && (num[3] == num[6]);
    bool winCol2 = (num[1] == num[4]) && (num[4] == num[7]);
    bool winCol3 = (num[2] == num[5]) && (num[5] == num[8]);

    // Diagonal
    bool winDiagonal1 = (num[0] == num[4]) && (num[4] == num[8]);
    bool winDiagonal2 = (num[2] == num[4]) && (num[4] == num[6]);

    if (winRow1 || winRow2 || winRow3 || winCol1 || winCol2 || winCol3 || winDiagonal1 || winDiagonal2) {
        return true;
    } else {
        return false;
    }
}

    void attack() {
            turn = true;
            while (num.begin() != num.end()) {
                board();
                currentPlayer = turn ? playerXO.at(0) : playerXO.at(1);
                cout << "Player " << currentPlayer << ", choose a position (1-9): ";
                
                position;
                cin >> position;
                
                try {
                    if (num.at(position)) {
                        num[position - 1] = currentPlayer; 
                        turn = !turn;
                        
                        if (win()) {
                            cout << "\nPlayer " << currentPlayer << " wins!" << endl;
                            board();
                            break;
                        } 
                    } else {    
                        throw "This position is already taken. Please try again.";
                    }
                }
                catch(exception e)
            {
                cerr << "Invalid input! \nPlease try again..."<< e.what() << '\n';
                break;
            }
        }
    }
};

#endif