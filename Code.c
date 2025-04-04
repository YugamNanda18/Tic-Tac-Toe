#include <stdio.h>

// Global game board
char board[3][3];

// Initialize the board with numbers 1–9
void initializeBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '0' + count++;
}

// Display the current board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Check if there's a winner or a draw
char checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    // Check for draw or ongoing game
    int moves = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 'X' || board[i][j] == 'O')
                moves++;

    if (moves == 9) return 'D';  // Draw
    return 'N'; // No winner yet
}

// Make a move
int makeMove(int cell, char symbol) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return 0; // Invalid move
    }
    board[row][col] = symbol;
    return 1;
}

int main() {
    char winner = 'N';
    int move;
    char currentPlayer = 'X';

    initializeBoard();

    while (winner == 'N') {
        displayBoard();
        printf("Player %c, enter a cell number (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (!makeMove(move, currentPlayer)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        winner = checkWin();
        if (winner == 'N') {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    displayBoard();
    if (winner == 'D') {
        printf("It's a draw!\n");
    } else {
        printf("Player %c wins!\n", winner);
    }

    return 0;
}
