#include <stdio.h>

#define SIZE 5

// Function Prototype
int did_player_win(char player, char board[SIZE][SIZE]);
void check_board_winner(char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {' ', 'X', ' ', ' ', 'O'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    check_board_winner(no_wins_board);
    check_board_winner(x_wins_board);
    check_board_winner(o_wins_board);
}

void check_board_winner(char board[SIZE][SIZE]) {
    if (did_player_win('X', board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Function Implementation:
// Determines whether a given player has won the game of tictactoe
// by getting SIZE tokens in a row, in any direction.
int did_player_win(char player, char board[SIZE][SIZE]) {
    
    // 1. Check the rows
    for (int row = 0; row < SIZE; row++) {
        int is_player = 1;
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] != player) {
                is_player = 0;
            }
        }
        if (is_player) {
            return 1;
        }
    }

    // 0,0 -> 0,1 -> 0,2 -> ...
    // 1,0 -> 1,1 -> 1,2 

    // 2. Check the columns
    for (int col = 0; col < SIZE; col++) {
        int count = 0;
        for (int row = 0; row < SIZE; row++) {
            if (board[row][col] == player) {
                count++;
            }
        }
        if (count == SIZE) {
            return 1;
        }
    }

    // 0,0 -> 1,0 -> 2,0 ->
    // 0,1 -> 1,1 -> 2,1 ->

    // 3. Check the diagonals
    // 3.1 top-left to bottom-right
    int is_player = 1;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            is_player = 0;
        }
    }
    if (is_player) {
        return 1;
    }

    // 3.2 top-right to bottom-left
    // 0, SIZE - 1 -> 1, SIZE - 2 ...
    int count = 0;
    int row = 0;
    int col = SIZE - 1;
    while (row < SIZE && col >= 0) {
        if (board[row][col] == player) {
            count++;
        }
        row++;
        col--;
    }
    if (count == SIZE) {
        return 1;
    }

    return 0;
}