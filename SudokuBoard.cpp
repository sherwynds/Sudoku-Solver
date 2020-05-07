#include "SudokuBoard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

auto SudokuBoard::getValues() {

    

};

int main(){
    SudokuBoard s = SudokuBoard();
    s.getValues();
};
