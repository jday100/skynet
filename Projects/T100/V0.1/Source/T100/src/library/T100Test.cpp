#include "T100Test.h"
#include <sstream>


namespace T100Library{

T100Console*    T100Test::m_console         = T100NULL;
T100WORD        T100Test::m_units           = 0;
T100WORD        T100Test::m_elements        = 0;
T100WORD        T100Test::m_index           = 0;
T100WORD        T100Test::m_success         = 0;
T100WORD        T100Test::m_failure         = 0;

T100TEST_UNIT_HASH      T100Test::m_unit_hash;


T100Test::T100Test(T100Test* parent, T100WSTRING name)
    :T100Class(),
    m_parent(parent),
    m_name(name)
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

    add();

    if(m_need_init){
        if(init()){
            m_inited = T100TRUE;
        }else{
            m_inited = T100FALSE;
        }
    }else{
        m_inited = T100TRUE;
    }

    //test
    m_inited    = T100FALSE;
    m_uninited  = T100FALSE;
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

T100VOID T100Test::add()
{
    m_units++;
    if(m_parent){
        m_parent->append(m_name, this);
    }else{
        append(m_name, this);
    }
}

T100VOID T100Test::append(T100WSTRING name, T100Test* test)
{
    m_tests.append(name, test);

    m_unit_hash[name] = test;
}

T100VOID T100Test::remove(T100WSTRING name, T100Test* test)
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

    for(T100Test* entry : m_tests.getVector()){
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

    for(T100TEST_CALL call : m_test_call.getVector()){
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

T100BOOL T100Test::test_unit(T100WSTRING name)
{
    T100BOOL        result          = T100TRUE;
    T100TEST_UNIT_HASH::iterator    it;

    if(L"all" == name){
        return test_all();
    }

    /*
    it = m_unit_hash.find(name);

    if(m_unit_hash.end() == it){
        result = T100FALSE;
    }else{
        T100Test*   test = T100NULL;

        test = it->second;

        if(test){
            result = test->test_all();
        }else{
            result = T100FALSE;
        }
    }
    */

    T100Test*   test    = T100NULL;

    test = m_tests[name];

    if(test){
        result = test->test_all();
    }else{
        result = T100FALSE;
    }

    return result;
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
    if(T100FALSE == m_inited){
        m_inited = init();
        return m_inited;
    }
    return T100TRUE;
}

T100BOOL T100Test::do_uninit()
{
    if(T100FALSE == m_uninited){
        m_uninited = uninit();
        return m_uninited;
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

T100BOOL T100Test::do_test()
{
    return T100TRUE;
}

T100VOID T100Test::show_result(T100BOOL result, T100WSTRING& msg)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] " << msg;
    }else{
        ss << L"[FAILURE] " << msg;
    }

    out(ss.str());
}

T100VOID T100Test::out(T100WSTRING msg)
{
    m_console->outline(msg);
}

T100VOID T100Test::out_test_begin(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"Unit [ " << m_index << L"/" << m_units << L" ] : [ " << name << L" ] test is beginning ... ";

    out(result.str());
}

T100VOID T100Test::out_test_end(T100WSTRING& name, T100BOOL result)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] ";
    }else{
        ss << L"[FAILURE] ";
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

        ss << L"Success " << m_success << L" units . ";
        ss << L"Failure " << m_failure << L" units . ";
        ss << L"\n" << L"Total be tested " << m_units << L" units . ";
    }

    out(ss.str());
}

T100VOID T100Test::out_list(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"\t Test unit: [ " << name << L" ]";

    out(result.str());
}

T100VOID T100Test::out_list_element(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"\t\tTest element: [ " << name << L" ]";

    out(result.str());
}

T100VOID T100Test::out_list_begin()
{
    out(L"All test units: ");
}

T100VOID T100Test::out_list_end()
{
    std::wstringstream      result;

    result << L"Total test " << m_units << L" units . ";

    out(result.str());
}

}
