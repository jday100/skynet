#include "T100AssemblyApp.h"


int main(int argc, wchar_t** argv)
{
    T100BOOL                result;
    T100AssemblyApp         app;

    result = app.run();

    if(!result){
        return -1;
    }

    return 0;
}

