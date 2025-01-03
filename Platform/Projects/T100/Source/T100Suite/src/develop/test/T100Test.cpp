#include "T100Test.h"

T100Console*    T100Test::m_console         = T100NULL;
T100WORD        T100Test::m_index           = 0;
T100WORD        T100Test::m_success         = 0;
T100WORD        T100Test::m_failure         = 0;

T100Test::T100Test(T100Test* parent, T100WString name)
    :m_parent(parent), m_name(name)
{
    //ctor
    create();
}

T100Test::~T100Test()
{
    //dtor
    destroy();
}

T100VOID T100Test::create()
{
    if(T100NULL == m_console){
        m_console   = T100NEW T100Console();
    }
}

T100VOID T100Test::destroy()
{

}

T100BOOL T100Test::test_all()
{
    T100BOOL            result          = T100TRUE;

    if(!m_parent){
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    for(T100Test* entry : m_tests.getVector()){
        if(this == entry){

        }else{
            if(entry->test_all()){

            }else{
                result  = T100FALSE;
            }
        }
    }

    out_test_begin(m_name);

    m_index++;

    if(do_test()){

    }else{
        result = T100FALSE;
    }

    if(result){
        m_success++;
    }else{
        m_failure++;
    }

    out_test_end(m_name, result);
}

T100BOOL T100Test::do_test()
{
    return T100TRUE;
}

T100VOID T100Test::out(T100WString msg)
{
    m_console->outline(msg);
}

T100VOID T100Test::out_test_begin(T100WString& name)
{

}

T100VOID T100Test::out_test_end(T100WString& name, T100BOOL result)
{

}

T100VOID T100Test::out_list(T100WString& name)
{

}

T100VOID T100Test::out_list_element(T100WString& name)
{

}

T100VOID T100Test::out_list_begin()
{

}

T100VOID T100Test::out_list_end()
{

}
