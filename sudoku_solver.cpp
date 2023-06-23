class Solution {
private:
    // The private section of the class contains helper functions and variables.

    // This helper function checks if a given placement of a number is valid in the Sudoku board.
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // Iterate through the cells of the grid to check for conflicts.
        for (int i = 0; i < 9; i++) {
            // Check if the same number already exists in the same column.
            if (board[i][col] == ch) {
                return false; 
            }
            // Check if the same number already exists in the same row.
            if (board[row][i] == ch) {
                return false;
            }
            // Check if the same number already exists in the same 3x3 box.
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch) {
                return false;
            }
        }
        // If no conflicts are found, the placement is valid.
        return true;
    }

    // This is a recursive helper function that solves the Sudoku board.
    bool solver(vector<vector<char>>& board) {
        // Iterate through each cell of the board.
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Check if the cell is empty.
                if (board[i][j] == '.') {
                    // Try placing numbers from '1' to '9' and check if it is a valid placement.
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            // If the placement is valid, update the cell with the new number.
                            board[i][j] = ch;
                            // Recursively call the solver function to solve the updated board.
                            if (solver(board) == true) {
                                // If the board is completely solved, return true.
                                return true;
                            }
                            // If the board cannot be solved with the current placement, backtrack by undoing the placement.
                            board[i][j] = '.';
                        }
                    }
                    // If no number can be placed in the current cell, return false.
                    return false;
                }
            }
        }
        // If all cells are filled and no conflicts are found, the board is solved.
        return true;
    }

public:
    // This is the public function that solves the Sudoku puzzle.
    void solveSudoku(vector<vector<char>>& board) {
        // Call the solver function to solve the Sudoku board.
        solver(board);
    }
};
