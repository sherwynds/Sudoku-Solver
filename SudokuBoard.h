#include <vector>
using namespace std;

class SudokuBoard

{
    
    public:

        SudokuBoard();

        auto getValues();
    
    private:

        int values[9][9];

};