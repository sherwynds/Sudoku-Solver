#include <vector>
#include "DFS.h"
#include "../SudokuBoard.h"
using namespace std;

SudokuBoard DFS::solve(SudokuBoard s) {
    while(!todo.empty()) {
        if(isSolved(s)) {
            return s;
        } else {
            // add next children, continue searching
        }
    }
    vector<vector<int>> vals;
    return SudokuBoard(vals);
}

bool DFS::isSolved(SudokuBoard s) {}