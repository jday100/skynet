#include "T100Test.h"

#include <sstream>

#ifdef __LOG__
    #include "T100Log.h"
#else
    #include <stdarg.h>
    #include <iostream>
#endif // __LOG__


int                     T100Test::argc                  = 0;
wchar_t**               T100Test::argv                  = T100NULL;

T100Console*            T100Test::m_console             = T100NULL;
T100WORD                T100Test::m_units               = 0;
T100WORD                T100Test::m_elements            = 0;
T100WORD                T100Test::m_index               = 0;
T100WORD                T100Test::m_success             = 0;
T100WORD                T100Test::m_failure             = 0;


T100Test::T100Test(T100Test* parent, T100WSTRING name)
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
#ifdef __LOG__
        m_console   = T100NEW T100Console(T100CONSOLE_LOG);
#else
        m_console   = T100NEW T100Console();
#endif // __LOG__
    }

    if(!m_parent){
        m_units     = 0;
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

T100BOOL T100Test::find()
{

}

T100VOID T100Test::show_report()
{

}

T100VOID T100Test::skip()
{
    if(m_parent){
        m_parent->remove(m_name, this);
    }
}

T100VOID T100Test::append()
{
    m_units++;
    if(m_parent){
        m_parent->add(m_name, this);
    }else{
        add(m_name, this);
    }
}

T100VOID T100Test::add(T100WSTRING name, T100Test* test)
{
    m_test_vector.push_back(test);
    m_test_hash[name] = test;
}

T100VOID T100Test::remove(T100WSTRING name, T100Test* test)
{

}

T100VOID T100Test::signin(T100WSTRING name, T100TEST_CALL call)
{
    m_call_vector.push_back(call);
    m_call_hash[name] = call;
}

T100BOOL T100Test::do_init()
{
    if(!m_inited){
        if(init()){
            m_inited = T100TRUE;
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100Test::do_uninit()
{
    if(!m_uninited){
        if(uninit()){
            m_uninited = T100TRUE;
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100Test::init()
{
    return T100FALSE;
}

T100BOOL T100Test::uninit()
{
    return T100FALSE;
}

T100BOOL T100Test::test_all()
{
    T100BOOL        result          = T100TRUE;

    if(!m_parent){
        //m_units    = 0;
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    for(T100Test* entry : m_test_vector){
        if(this == entry){

        }else{
            if(entry->test_all()){

            }else{
                result = T100FALSE;
            }
        }
    }

    out_test_begin(m_name);

    m_index++;

    if(do_test()){

    }else{
        result = T100FALSE;
    }

    for(T100TEST_CALL call : m_call_vector){
        if(call(this)){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        m_success++;
    }else{
        m_failure++;
    }

    out_test_end(m_name, result);

    return result;
}

T100VOID T100Test::list()
{
    if(!m_parent){
        //m_units   = 0;
        m_elements  = 0;
        out_list_begin();
    }

    out_list(m_name);

    T100TEST_CALL_HASH::iterator it;

    for(it = m_call_hash.begin(); it != m_call_hash.end(); ++it){
        T100WSTRING     element;

        element = it->first;
        m_elements++;
        out_list_element(element);
    }

    for(T100Test* entry : m_test_vector){
        if(this == entry){

        }else{
            entry->list();
        }
    }

    if(!m_parent){
        out_list_end();
    }
}

T100BOOL T100Test::do_test()
{
    return T100TRUE;
}

T100VOID T100Test::show_result(T100BOOL result, T100WSTRING& msg)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS]" << " " << msg;
    }else{
        ss << L"[FAILURE]" << " " << msg;
    }

    out(ss.str());
}

T100VOID T100Test::out_test_begin(T100WSTRING& name)
{
    std::wstringstream   result;

    result << L"Unit [ " << m_index << L"/" << m_units << L" ] : [ " << name << L" ] test is beginning ... ";

    out(result.str());
}

T100VOID T100Test::out_test_end(T100WSTRING& name, T100BOOL result)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] ";
    }else{
        ss << L"[FAILURE]";
    }

    ss << L"Unit [ " << m_index - 1 << L"/" << m_units << L" ] : [ " << name << L" ] test is ended . ";

    if(!m_parent){
        ss << L"\n";
        ss << L"Test result: ";
        if(result){
            ss << L"[SUCCESS] ";
        }else{
            ss << L"[FAILURE] ";
        }

        ss << L"Success " << m_success << L" units. ";
        ss << L"Failure " << m_failure << L" units. ";
        ss << L"\n" << L"Total be tested " << m_units << L" units. ";
    }

    out(ss.str());
}

T100VOID T100Test::out_list(T100WSTRING& name)
{
    std::wstringstream   result;

    result << L"\tTest unit: [ " << name << L" ]";

    out(result.str());
}

T100VOID T100Test::out_list_element(T100WSTRING& name)
{
    std::wstringstream   result;

    result << L"\t\tTest element: [ " << name << L" ]";

    out(result.str());
}

T100VOID T100Test::out_list_begin()
{
    out(L"All test units: ");
}

T100VOID T100Test::out_list_end()
{
    std::wstringstream  result;

    result << L"Total test " << m_units << L" " << L"units . ";

    out(result.str());
}

T100VOID T100Test::out(T100WSTRING msg)
{
    m_console->outline(msg);
}
