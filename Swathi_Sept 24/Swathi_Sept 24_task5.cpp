TicTacToe Class (Basic 3x3 Human vs Human)
#include <iostream>
#include <array>
using namespace std;

class TicTacToe {
private:
    array<array<int, 3>, 3> board; // 3x3 board
    int currentPlayer;             // 1 or 2

public:
    // Constructor
    TicTacToe() {
        for (auto &row : board)
            row.fill(0);  // empty board
        currentPlayer = 1;
    }

    // Display the board
    void displayBoard() const {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char symbol = ' ';
                if (board[i][j] == 1) symbol = 'X';
                else if (board[i][j] == 2) symbol = 'O';

                cout << " " << symbol << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
    }

    // Make a move
    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid position. Try again.\n";
            return false;
        }
        if (board[row][col] != 0) {
            cout << "Cell already taken. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    // Check for a win
    bool checkWin() const {
        // check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return true;
            if (board[0][i] != 0 &&
                board[0][i] == board[1][i] &&
                board[1][i] == board[2][i])
                return true;
        }
        // diagonals
        if (board[0][0] != 0 &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return true;
        if (board[0][2] != 0 &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return true;

        return false;
    }

    // Check for draw
    bool checkDraw() const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0) return false;
        return true;
    }

    // Switch player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 1 ? 2 : 1);
    }

    int getCurrentPlayer() const {
        return currentPlayer;
    }
};


int main() {
    TicTacToe game;
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1 = X, Player 2 = O\n";

    while (true) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() 
             << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (!game.makeMove(row, col))
            continue; // invalid move, retry

        if (game.checkWin()) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }
        if (game.checkDraw()) {
            game.displayBoard();
            cout << "It's a draw!\n";
            break;
        }
        game.switchPlayer();
    }

    return 0;
}