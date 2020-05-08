#include <vector>
using namespace std;
using T = int[9][9];

class SudokuBoard

{
    
    public:

        SudokuBoard();

        SudokuBoard(T vals);

        T& getValues();
    
    private:
        
        int values[9][9];

};