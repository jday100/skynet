#include "T100Test.h"

namespace T100Library{

T100Console*    T100Test::m_console         = T100NULL;
T100WORD        T100Test::m_units           = 0;
T100WORD        T100Test::m_elements        = 0;
T100WORD        T100Test::m_index           = 0;
T100WORD        T100Test::m_success         = 0;
T100WORD        T100Test::m_failure         = 0;


T100Test::T100Test(T100Test* parent, T100WSTRING name)
    :T100Class()
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
#ifdef __lOG__
        m_console = T100NEW T100Console(T100CONSOLE_TYPE_LOG);
#else
        m_console = T100NEW T100Console();
#endif // __lOG__
    }

    if(!m_parent){
        m_units = 0;
    }

    append();

    if(m_need_init){
        if(init()){
            m_inited = T100TRUE;
        }else{
            m_inited = T100FALSE;
        }
    }else{
        m_inited = T100TRUE;
    }
}

T100VOID T100Test::destroy()
{
    if(m_need_uninit){
        if(uninit()){
            m_uninited = T100TRUE;
        }else{
            m_uninited = T100FALSE;
        }
    }else{
        m_uninited = T100TRUE;
    }
}

T100VOID T100Test::append()
{

}

T100BOOL T100Test::test_all()
{
    T100BOOL        result      = T100TRUE;

    if(!m_parent){
        //m_units   = 0;
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    return T100FALSE;
}

T100VOID T100Test::list()
{

}

T100BOOL T100Test::find()
{
    return T100FALSE;
}

T100BOOL T100Test::do_init()
{

}

T100BOOL T100Test::do_uninit()
{

}

T100BOOL T100Test::init()
{

}

T100BOOL T100Test::uninit()
{

}

T100BOOL T100Test::do_test()
{

}

T100VOID T100Test::show_result(T100BOOL result, T100WSTRING& msg)
{

}

T100VOID T100Test::out(T100WSTRING msg)
{

}

T100VOID T100Test::out_test_begin(T100WSTRING& msg)
{

}

T100VOID T100Test::out_test_end(T100WSTRING& msg, T100BOOL result)
{

}

T100VOID T100Test::out_list(T100WSTRING& msg)
{

}

T100VOID T100Test::out_list_element(T100WSTRING& msg)
{

}

T100VOID T100Test::out_list_begin()
{

}

T100VOID T100Test::out_list_end()
{

}

}
