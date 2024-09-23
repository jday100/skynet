#include "T100CPPThisApp.h"

#include "T100CPPTest.h"

T100CPPThisApp::T100CPPThisApp()
{
    //ctor
}

T100CPPThisApp::~T100CPPThisApp()
{
    //dtor
}

T100BOOL T100CPPThisApp::run(T100CPPState& state)
{
    if(state.TEST == T100TRUE){
        T100CPPTest         cpp_test;

        cpp_test.run();
    }
    return T100FALSE;
}
