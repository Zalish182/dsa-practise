/*
3 1 0 5 7 8 4 0 2
0 2 9 0 3 0 0 0 8
4 0 0 6 2 9 0 3 1
2 0 3 0 1 0 0 8 0
0 7 0 8 6 3 0 0 5
8 0 1 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
6 9 2 0 5 0 0 7 4
7 0 0 2 0 6 3 0 0
*/
#include <iostream>
using namespace std;

const int SIZE = 9;

void display(int board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

bool solve(int board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (board[r][c] == 0) {
                for (int num = 1; num <= 9; num++) {
                    bool valid = true;
                    for (int i = 0; i < SIZE; i++) {
                        if (board[r][i] == num || board[i][c] == num) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        board[r][c] = num;
                        if (solve(board)) {
                            return true;
                        }
                        board[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    cout << "Enter Sudoku puzzle (0 for empty cells):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    if (solve(board)) {
        cout << "Solved Sudoku:\n";
        display(board);
    } else {
        cout << "No solution found.\n";
    }
    return 0;
}
