#include "SudokuBoard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SudokuBoard::SudokuBoard() {

    for(int i = 1; i <= 9; i++) {
        vector<int> tmp;
        for(int j = 1; j <= 9; j++) {
            tmp.push_back(i*10 + j);
        };
        values.push_back(tmp);
    };

};

vector<vector<int>> SudokuBoard::getValues() const {
    return values;
};

int main(){
    SudokuBoard s = SudokuBoard();
    vector<vector<int>> vals = s.getValues();
    cout << to_string(vals[0][0]) << endl;
};
