#include "T100TestUnitTest.h"

int main()
{
    T100RESULT              result;
    T100TestUnitTest        unit;

    result  = unit.TestAll();

    if(result == T100RESULT_SUCCESS){
        return 0;
    }
    return -1;
}
