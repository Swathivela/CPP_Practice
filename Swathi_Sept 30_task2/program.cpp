#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 12;

// Function prototypes
void mazeTraverse(char maze[][SIZE], int x, int y, int startX, int startY);
void printMaze(char maze[][SIZE]);

// Directions: right, down, left, up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    char maze[SIZE][SIZE] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','#'},
        {'.','.','#','.','#','.','#','#','#','#','.','#'},
        {'#','#','#','.','#','.','.','.','.','#','.','#'},
        {'#','.','.','.','.','#','#','#','.','#','.','.'},
        {'#','#','#','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','#','.','#','.','#','.','#','.','#'},
        {'#','#','.','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','#','.','#'},
        {'#','#','#','#','#','#','.','#','#','#','.','#'},
        {'#','.','.','.','.','.','.','#','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    int startX = 2, startY = 0; // starting location (row, col)

    mazeTraverse(maze, startX, startY, startX, startY);

    return 0;
}

// Recursive function
void mazeTraverse(char maze[][SIZE], int x, int y, int startX, int startY) {
    maze[x][y] = 'X'; // mark path
    printMaze(maze);

    // base case: exit found (on border, but not starting point)
    if ((x == 0 || x == SIZE-1 || y == 0 || y == SIZE-1) && !(x == startX && y == startY)) {
        cout << "Exit found at (" << x << "," << y << ")!\n";
        return;
    }

    // try all directions (right, down, left, up)
    for (int d = 0; d < 4; d++) {
        int newX = x + dx[d];
        int newY = y + dy[d];

        if (maze[newX][newY] == '.') { // valid move
            mazeTraverse(maze, newX, newY, startX, startY);
            return; // stop after moving
        }
    }
}

// Print maze
void printMaze(char maze[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(2) << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
