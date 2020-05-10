#include <vector>
using namespace std;

class SudokuBoard

{
    
    public:

        SudokuBoard();
        SudokuBoard(vector<vector<int>> vals);
        
        void setValue(int col, int row, int value);
        vector<vector<int>>* getValues();
    
    private:
        
        vector<vector<int>> values;

};