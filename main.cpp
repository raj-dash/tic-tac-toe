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

    return 0;
}

// function to swap the player and the marker
void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

// function with the actual logic of the game
void game() {
    cout << "Player 1, choose your marker (X or O) :" << endl;
    char marker_p1;
    cin >> marker_p1;
    int winner;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        cout << "it's player " << current_player << "'s turn, enter your slot :" << endl;
        int slot;
        cin >> slot;

        placeMarker(slot);
        drawBoard();

        winner = checkWin();
        if (winner == 1) {
            cout << endl << endl;
            cout << "Congratulations! PLayer 1 has won!" << endl;
            break;
        }
        if (winner == 2) {
            cout << endl << endl;
            cout << "Congratulations! PLayer 2 has won!" << endl;
            break;
        }

        swap_player_and_marker();
    }
    if (winner == 0) {
        cout << "Draw!" << endl;
    }
}

int main() {
    game();
}