#include <vector>
using namespace std;

class SudokuBoard

{
    
    public:

        SudokuBoard();
        SudokuBoard(vector<vector<int>> vals);

        vector<vector<int>>* getValues();
    
    private:
        
        vector<vector<int>> values;

};