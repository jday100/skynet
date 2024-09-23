#include "T100CPPThisApp.h"

#include "T100ThisTest.h"

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
    //test
    state.TEST  = T100TRUE;

    if(state.TEST == T100TRUE){
        T100ThisTest         this_test;

        this_test.run();
    }
    return T100FALSE;
}
