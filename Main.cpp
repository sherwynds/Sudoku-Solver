#include "SudokuBoard.h"
#include "Algorithms/DFSPruning.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    SudokuBoard s = SudokuBoard();
    s.setValue(7, 3, 3);
    vector<vector<int>>* svals = s.getValues();
    cout << (*svals)[7][3] << endl;
    s.printBoard();
    s.setValue(7, 8, 9);
    cout << "\n" << endl;
    s.printBoard();
}
