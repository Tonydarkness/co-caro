#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int SIZE = 9;

bool isRowValid(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isColValid(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

bool isBoxValid(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    return isRowValid(grid, row, num) &&
        isColValid(grid, col, num) &&
        isBoxValid(grid, row - row % 3, col - col % 3, num);
}

bool findUnassignedLocation(int grid[SIZE][SIZE], int& row, int& col) {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    if (!findUnassignedLocation(grid, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void PrintGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " ";
            if ((col + 1) % 3 == 0)
            {
                cout << setw(3) << " ";
            }
        }
        cout << endl;
        if ((row + 1) % 3 == 0)
            cout << endl;
    }
}

int main() {
    int grid[SIZE][SIZE];
    //cout << "Enter the Sudoku grid (use 0 to indicate blank cells):" << endl;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cin >> grid[row][col];
        }
    }
    if (solveSudoku(grid)) {
        cout << "The solution is:" << endl;
        PrintGrid(grid);
    }
    else {
        cout << "No solution exists" << endl;
    }
    return 0;
}
