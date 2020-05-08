#include "SudokuBoard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using T = int[9][9];

SudokuBoard::SudokuBoard() {

    int numCols = sizeof(values) / sizeof(values[0]);
    int numRows = sizeof(values[0]) / sizeof(values[0][0]);
    cout << "Cols = " << to_string(numCols) << " Rows = " << to_string(numRows) << endl;

    for(int i = 0; i <= numCols; i++) {
        for(int j = 0; j <= numRows; j++) {
            values[i][j] = (i+1)*10 + (j+1);
        }
    }

    cout << values[8][8] << endl;
};

SudokuBoard::SudokuBoard(T vals) {
    T& tmp = values;
    delete tmp;
    **values = **vals;
    cout << values[8][8] << endl;
}

T& SudokuBoard::getValues() {
    return values;
};

int main(){
    int vals[9][9];
    vals[8][8] = 177;
    SudokuBoard s = SudokuBoard(vals);
    auto vlu = s.getValues();
    cout << vlu[8][8] << endl;
};
