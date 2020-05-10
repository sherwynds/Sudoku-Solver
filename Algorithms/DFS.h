#include <vector>
#include "../SudokuBoard.h"
using namespace std;

class DFS  {

    public:

        SudokuBoard solve(SudokuBoard s);

    private:

        vector<SudokuBoard> todo;

        bool isSolved(SudokuBoard s);
        bool rowSolved();
        bool colSolved();
        bool gridSolved();

};