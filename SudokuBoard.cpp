#include "SudokuBoard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using T = vector<vector<int>>;

SudokuBoard::SudokuBoard() {

    int numCols = 9;
    int numRows = 9;
    cout << "Cols = " << to_string(numCols) << " Rows = " << to_string(numRows) << endl;

    for(int i = 0; i < numCols; i++) {
        vector<int> tmp;
        for(int j = 0; j < numRows; j++) {
            tmp.push_back((i+1)*10 + (j+1));
        }
        values.push_back(tmp);
    }

    cout << values[8][8] << endl;
};

SudokuBoard::SudokuBoard(vector<vector<int>> vals) {
    values = vals;
}

vector<vector<int>>* SudokuBoard::getValues() {
    return &values;
}

int main(){
    SudokuBoard s = SudokuBoard();
    T* vals = s.getValues();
    cout << (*vals)[8][8] << endl;
    T vals2;
    for(int i = 0; i < 9; i++) {
        vector<int> tmp;
        for(int j = 0; j < 9; j++) {
            tmp.push_back(101);
        }
        vals2.push_back(tmp);
    }
    SudokuBoard s2 = SudokuBoard(vals2);
    T* vals2p = s2.getValues();
    cout << (*vals2p)[8][8] << endl;
};
