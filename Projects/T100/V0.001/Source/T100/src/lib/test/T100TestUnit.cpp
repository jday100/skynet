#include "T100TestUnit.h"

#include "T100Thread.h"


T100TestUnit::T100TestUnit(T100TEST_UNIT unit)
{
    //ctor
    run(unit);
}

T100TestUnit::~T100TestUnit()
{
    //dtor
}

T100VOID T100TestUnit::run(T100TEST_UNIT unit)
{
    T100Thread  thread;

    thread.start();

    thread.wait();
}

T100BOOL T100TestUnit::ok()
{
    return T100FALSE;
}
