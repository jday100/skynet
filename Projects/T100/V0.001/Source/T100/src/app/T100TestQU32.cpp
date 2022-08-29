#include "T100TestQU32.h"

#include "T100QU32.h"

T100STDSTRING       T100TestQU32::m_unit        = "qu32";


T100TestQU32::T100TestQU32()
    :T100Test(m_unit)
{
    //ctor
}

T100TestQU32::~T100TestQU32()
{
    //dtor
}

T100VOID T100TestQU32::load()
{

}

T100BOOL T100TestQU32::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_qu32()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestQU32::test_qu32()
{
    T100BOOL    result      = T100TRUE;

    T100QU32    qu32;

    result = qu32.start();

    if(result){
        qu32.wait();
    }

    return result;
}
