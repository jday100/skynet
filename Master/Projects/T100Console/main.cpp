#include "test/T100ConsoleTest.h"

int main()
{
    T100ConsoleTest     console;
    T100RESULT          result;

    result  = console.TestAll();
    if(result == T100RESULT_SUCCESS){
        return 0;
    }
    return -1;
}
