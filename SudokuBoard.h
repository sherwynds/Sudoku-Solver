#include <vector>
using namespace std;

class SudokuBoard

{
    
    public:
        SudokuBoard();
        SudokuBoard(int& vals);

        vector<vector<int>> getValues();

        void printValues();
    
    private:
        vector<vector<int>> values;

};