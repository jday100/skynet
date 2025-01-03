#include "T100SuiteTest.h"

int main()
{
    int         result      = -1;

    T100SuiteTest       suite;

    if(suite.test_all()){
        result  = 0;
    }
    return result;
}
