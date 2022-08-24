#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8','9'}};

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

void placeMarker(int slot) {
    int row = slot / 3;
    int col;
    
    if (slot % 3 == 0) {
        row = row = 1;
        col = 2;
    } else {
        col = (slot % 3) - 1;
    }
}

int main() {
    drawBoard();
    placeMarker(8);
}