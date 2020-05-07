#include <vector>
using namespace std;

class SudokuBoard

{
    
    public:

        SudokuBoard();

        SudokuBoard(int& vals);

        void printValues();

        vector<vector<int>> getValues() const;

    
    private:
        vector<vector<int>> values;

};