#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8','9'}};

char current_marker;
int current_player;

// this function draws the board
void drawBoard() {
    cout << "   |   |   " << endl;
    cout << ' ' << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << ' ' << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << ' ' << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   " << endl;
}

// this is a function to place the marker on the players input
void placeMarker(int slot) {
    int row = slot / 3;
    int col;
    
    if (slot % 3 == 0) {
        row = row - 1;
        col = 2;
    } else {
        col = (slot % 3) - 1;
    }

    board[row][col] = current_marker;
}

// this is a function to check if a player has won or the game has been drawn
char checkWin() {

    for (int i = 0; i < 3; i++) {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
        //cols
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return '0';
}

int main() {
    drawBoard();
    current_marker = 'X';
    current_player = '1';
    placeMarker(1);
    placeMarker(5);
    placeMarker(9);
    cout << endl << endl << endl;
    drawBoard();

    cout << checkWin();
}