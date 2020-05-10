#include "SudokuBoard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SudokuBoard::SudokuBoard() {

    int numCols = 9;
    int numRows = 9;
    cout << "Cols = " << to_string(numCols) << " Rows = " << to_string(numRows) << endl;

    for(int i = 0; i < numCols; i++) {
        vector<int> tmp;
        for(int j = 0; j < numRows; j++) {
            tmp.push_back(-1);
        }
        values.push_back(tmp);
    }

    cout << values[8][8] << endl;
}

SudokuBoard::SudokuBoard(vector<vector<int>> vals) {
    values = vals;
}

void SudokuBoard::setValue(int col, int row, int value) {
    int maxCol = values.size() - 1;
    int maxRow = values[0].size() - 1;
    int maxVal = 9;
    int minVal = 1;
    if(col < 0 || col > maxCol) {
        cout << "column out of range" << endl;
    } else if (row < 0 || row > maxRow) {
        cout << "row out of range" << endl;
    } else if (value < minVal || value > maxVal) {
        cout << "value must be in range 1 - 9" << endl;
    } else {
        values[col][row] = value;
    }
}

vector<vector<int>>* SudokuBoard::getValues() {
    return &values;
}

