
#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main() {
    char board[3][3];
    char player;
    int row, col;
    char playAgain;

    do {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        player = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);
            cout << "Player " << player << ", enter row and column (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin(board, player)) {
                displayBoard(board);
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw.\n";
                gameOver = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
