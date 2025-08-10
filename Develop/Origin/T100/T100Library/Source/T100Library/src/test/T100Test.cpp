#include "test/T100Test.h"

namespace T100LIBRARY{

T100INT ToValue(T100BOOL flag)
{
    if(flag){
        return 0;
    }
    return -1;
}

T100BOOL ToBool(T100INT value)
{
    if(value < 0){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL ToBool(T100UINT value)
{
    if(value == 0){
        return T100TRUE;
    }
    return T100FALSE;
}

T100Test::T100Test(T100Test* parent, const T100WSTRING& label) :
    T100TestBase(),
    m_tests()
{
    //ctor
    T100Tree::Create(parent, label);

    if(parent){
        parent->Add(this, label);
    }
}

T100Test::~T100Test()
{
    //dtor
}

T100BOOL T100Test::TestAll()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    if(!m_parent){
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
        m_exception = 0;
    }

    if(!m_parent){
        result  = doGlobalInit();
    }

    for(T100Test* entry : m_tests.GetVector()){
        if(this == entry){

        }else{
            if(entry->TestAll()){

            }else{
                result  = T100FALSE;
            }
        }
    }

    outTestBegin(m_label);

    doInit();

    doIndex();

    if(DoTest()){

    }else{
        result  = T100FALSE;
    }

    doUninit();

    if(result){
        doSuccess();
    }else{
        doFailure();
    }

    outTestEnd(result, m_label);

    if(!m_parent){
        value   = doGlobalUninit();
        if(!value){
            result  = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100Test::TestUnit(const T100WSTRING& label)
{
    T100BOOL        result      = T100TRUE;

    if(L"all" == label){
        return TestAll();
    }

    T100Test*       unit        = T100NULL;

    unit    = m_tests[label];

    if(unit){
        result  = unit->TestAll();
    }else{
        result  = T100FALSE;
    }

    return result;
}

T100VOID T100Test::List()
{
    if(!m_parent){
        outListBegin();
    }

    outList(m_label);

    for(T100Test* entry : m_tests.GetVector()){
        if(this == entry){

        }else{
            entry->List();
        }
    }

    if(!m_parent){
        outListEnd();
    }
}

T100BOOL T100Test::Find(const T100WSTRING& label)
{
    T100BOOL        result  = T100TRUE;

    T100Test*       unit    = T100NULL;

    unit    = m_tests[label];

    if(unit){
        result  = T100TRUE;
    }

    return result;
}

T100VOID T100Test::Add(T100Test* child, const T100WSTRING& label)
{
    m_tests.Append(label, child);
}

}
