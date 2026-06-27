#include <iostream>
#include <vector>
using namespace std;

class SudokuSolver
{
public:
    bool isSafe(vector<vector<int>> &board, int row, int col, int num)
    {

        for (int x = 0; x < 9; x++)
        {
            if (board[row][x] == num)
                return false;
        }

        for (int x = 0; x < 9; x++)
        {
            if (board[x][col] == num)
                return false;
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[startRow + i][startCol + j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solveSudoku(vector<vector<int>> &board)
    {

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {

                if (board[row][col] == 0)
                {

                    for (int num = 1; num <= 9; num++)
                    {

                        if (isSafe(board, row, col, num))
                        {

                            board[row][col] = num;

                            if (solveSudoku(board))
                                return true;

                            // Backtrack
                            board[row][col] = 0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void printBoard(vector<vector<int>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    SudokuSolver solver;

    if (solver.solveSudoku(board))
    {
        cout << "Solved Sudoku:\n";
        solver.printBoard(board);
    }
    else
    {
        cout << "No solution exists.\n";
    }

    return 0;
}