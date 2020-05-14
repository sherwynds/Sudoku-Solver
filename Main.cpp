#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <fstream>

using namespace std;

#define EMPTY 0
#define SIZE 9
#define SPACE " "
#define END_COORDS make_pair(SIZE, SIZE)

// Prints the Sudoku board to the command line
void printBoard(int board[SIZE][SIZE]) {
	vector<string> lines;
	for(int row = 0; row < SIZE; row++) {
		string line;
		for(int col = 0; col < SIZE; col++) {
			if (col == 0) {
				line.append("| ");
			}
			if (col % 3 == 2) {
				line.append(to_string(board[row][col]) + " | ");
			} else {
				line.append(to_string(board[row][col]) + SPACE);
			}
		}
		lines.push_back(line);
	}

	string hEdge  = "-------------------------";
	cout << hEdge << endl;
	for(int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
		if(i % 3 == 2) {
			cout << hEdge << endl;
		}
	}
	cout << endl;
}

// Returns boolean: whether it is legal to place number in given sub-board starting at rowStart, colStart
bool gridUsed(int board[SIZE][SIZE], int rowStart, int colStart, int num) {
	int subSize = SIZE/3;
	for (int row = 0; row < subSize; row++) {
		for (int col = 0; col < subSize; col++) {
			if (board[rowStart + row][colStart + col] == num) {
				return false;
			}
		}
	}
	return true;
}

// Returns boolean: whether it is legal to place number in given row
bool rowUsed(int board[SIZE][SIZE], int row, int num) {
	for (int col = 0; col < SIZE; col++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

// Returns boolean: whether it is legal to place number in given row
bool colUsed(int board[SIZE][SIZE], int col, int num) {
	for (int row = 0; row < SIZE; row++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

// Returns boolean: whether it is legal to place the given number at row, col
bool safe(int board[SIZE][SIZE], int row, int col, int num) {
	// Determine the starting co-ordinates of the subsection belonging to row, col
	int rowStart = row - row % 3;
	int colStart = col - col % 3;
	return rowUsed(board, row, num) && colUsed(board, col, num) && gridUsed(board, rowStart, colStart, num);
}

// Finds row, col co-ordinates of the next empty cell
pair<int, int> findEmptyCell(int board[SIZE][SIZE]) {
	for (int row = 0; row < SIZE; row++) {
		for (int col = 0; col < SIZE; col++) {
			if (board[row][col] == EMPTY) {
				return make_pair(row, col);
			}
		}
	}
	return END_COORDS;
}
 
// Returns true when solved, false if all possible worlds have been exhausted without a solution (DFS)
bool solveDFS(int board[SIZE][SIZE]) {
	if (findEmptyCell(board) == END_COORDS) {
		return true;
	} else {
		pair<int, int> emptyCell = findEmptyCell(board);
		int row = emptyCell.first;
		int col = emptyCell.second;
		for (int n = 1; n <= 9; n++) {
			if (safe(board, row, col, n)) {
				board[row][col] = n;
				// DFS Recursion
				if (solveDFS(board)) {
					return true;
				}
				// Backtrack
				board[row][col] = EMPTY;
			}
		}
	}
	return false;
}

int main() {

	// Get user to input a text file containing the puzzle to be solved
	string path;
	cout << "Welcome to Sudoku Solver! Please enter path to file:" << endl;
	getline(cin, path);
	cout << endl;
	cout << "Path entered: " << path << endl;

	// Initialize the game board
	int board[SIZE][SIZE] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						     { 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

	// Read the input path, produce an error if it cannot be read properly
	ifstream f(path);
	if (!f) {
		cout << endl;
		cout << "Error - file couldn't be opened! Please enter a correct absolute or relative path next time." << endl;
		return 1;
	} else {
		for(int row = 0; row < SIZE; row++) {
			for(int col = 0; col < SIZE; col++) {
				f >> board[row][col];
				if (!f) {
					cout << "Error - element at " << row << ", " << col << " could not be found!" << endl;
					return 1;
				}
			}
		}
	}

	// Print the input board
	cout << endl;
	cout << "Input:" << endl;
	printBoard(board);

	// Print the output board
	cout << "Output:" << endl;
	if (solveDFS(board)) {
		printBoard(board);
	} else {
		cout << "No solution found!" << endl;
	}
	
	return 0;
}
