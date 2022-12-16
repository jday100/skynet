#include "T100TestNew.h"

#include <sstream>


namespace T100Library{

T100TestNew::T100TestNew(T100TestNew* parent, T100WSTRING name)
    :T100Class(),
    m_parent(parent),
    m_name(name)
{
    //ctor
    create();
}

T100TestNew::~T100TestNew()
{
    //dtor
    destroy();
}

T100VOID T100TestNew::create()
{
    m_need_unit_init        = T100FALSE;
    m_need_unit_uninit      = T100FALSE;

    m_need_global_init      = T100FALSE;
    m_need_global_uninit    = T100FALSE;

    m_unit_inited           = T100FALSE;
    m_unit_uninited         = T100FALSE;

    m_global_inited         = T100FALSE;
    m_global_uninited       = T100FALSE;

    if(!m_parent){
        if(T100NULL == m_console){
#ifdef __lOG__
            m_console = T100NEW T100Console(T100CONSOLE_TYPE_LOG);
#else
            m_console = T100NEW T100Console();
#endif // __lOG__
        }

        m_units = 0;
    }

    add();
}

T100VOID T100TestNew::destroy()
{
    m_tests.clear();
    do_global_uninit();
    T100SAFE_DELETE(m_console);
}

T100Console* T100TestNew::getConsole()
{
    if(m_parent){
        return m_parent->getConsole();
    }
    return m_console;
}

T100VOID T100TestNew::add()
{
    if(m_parent){
        m_parent->insert(m_name, this);
    }else{
        append(m_name, this);
    }
}

T100VOID T100TestNew::insert(T100WSTRING name, T100TestNew* test)
{
    if(m_parent){
        m_parent->insert(name, test);
    }else{
        append(name, test);
    }
}

T100VOID T100TestNew::append(T100WSTRING name, T100TestNew* test)
{
    m_tests.append(name, test);
    m_units++;
}

T100VOID T100TestNew::remove(T100WSTRING name)
{
    T100TestNew*        test            = T100NULL;

    test = m_tests[name];

    m_tests.remove(name);
}

T100VOID T100TestNew::setGlobalInit(T100BOOL flag)
{
    m_need_global_init      = flag;
}

T100VOID T100TestNew::setGlobalUninit(T100BOOL flag)
{
    m_need_global_uninit    = flag;
}

T100BOOL T100TestNew::do_global_init()
{
    if(m_parent){
        m_parent->do_global_init();
    }

    if(m_need_global_init && (!m_global_inited)){
        m_global_inited     = global_init();
        return m_global_inited;
    }
    return T100TRUE;
}

T100BOOL T100TestNew::do_global_uninit()
{

    if(m_need_global_uninit && (!m_global_uninited)){
        m_global_uninited   = global_uninit();
        return m_global_uninited;
    }

    if(m_parent){
        //m_parent->do_global_uninit();
    }
    return T100TRUE;
}

T100BOOL T100TestNew::global_init()
{
    return T100FALSE;
}

T100BOOL T100TestNew::global_uninit()
{
    return T100FALSE;
}

T100VOID T100TestNew::setInit(T100BOOL flag)
{
    m_need_unit_init    = flag;
}

T100VOID T100TestNew::setUninit(T100BOOL flag)
{
    m_need_unit_uninit  = flag;
}

T100BOOL T100TestNew::do_init()
{
    if(m_need_unit_init && (!m_unit_inited)){
        m_unit_inited   = init();
        return m_unit_inited;
    }
    return T100TRUE;
}

T100BOOL T100TestNew::do_uninit()
{
    if(m_need_unit_uninit && (!m_unit_uninited)){
        m_unit_uninited = uninit();
        return m_unit_uninited;
    }
    return T100TRUE;
}

T100BOOL T100TestNew::init()
{
    return T100FALSE;
}

T100BOOL T100TestNew::uninit()
{
    return T100FALSE;
}

T100VOID T100TestNew::index()
{
    if(m_parent){
        m_parent->index();
        return;
    }

    m_index++;
}

T100VOID T100TestNew::success()
{
    if(m_parent){
        m_parent->success();
        return;
    }

    m_success++;
}

T100VOID T100TestNew::failure()
{
    if(m_parent){
        m_parent->failure();
        return;
    }

    m_failure++;
}

T100BOOL T100TestNew::test_all()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(!m_parent){
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    if(!m_parent){
        result = do_global_init();
    }

    for(T100TestNew* entry : m_tests.getVector()){
        if(this == entry){

        }else{
            if(entry->test_all()){

            }else{
                result = T100FALSE;
            }
        }
    }

    out_test_begin(m_name);

    do_init();

    index();

    if(do_test()){

    }else{
        result = T100FALSE;
    }

    do_uninit();

    if(result){
        success();
    }else{
        failure();
    }

    out_test_end(result, m_name);

    if(!m_parent){
        value = do_global_uninit();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100TestNew::test_unit(T100WSTRING name)
{
    T100BOOL        result          = T100TRUE;

    if(L"all" == name){
        return test_all();
    }

    T100TestNew*    test            = T100NULL;

    test = m_tests[name];

    if(test){
        result = test->test_all();
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestNew::do_test()
{
    return T100TRUE;
}

T100VOID T100TestNew::list()
{
    if(!m_parent){
        out_list_begin();
    }

    out_list(m_name);

    for(T100TestNew* entry : m_tests.getVector()){
        if(this == entry){

        }else{
            entry->list();
        }
    }

    if(!m_parent){
        out_list_end();
    }
}

T100BOOL T100TestNew::find(T100WSTRING name)
{
    T100BOOL        result          = T100FALSE;

    T100TestNew*    test            = T100NULL;

    test = m_tests[name];

    if(test){
        result = T100TRUE;
    }

    return result;
}

T100VOID T100TestNew::show_result(T100BOOL result, T100WSTRING& msg)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] " << msg;
    }else{
        ss << L"[FAILURE] " << msg;
    }

    out(ss.str());
}

T100VOID T100TestNew::out(T100WSTRING msg)
{
    getConsole()->outline(msg);
}

T100VOID T100TestNew::out_test_begin(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"Unit [ " << m_index << L"/" << m_units << L" ] : [ " << name << L" ] test is beginning ... ";

    out(result.str());
}

T100VOID T100TestNew::out_test_end(T100BOOL result, T100WSTRING& name)
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

T100VOID T100TestNew::out_list(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"\t Test unit: [ " << name << L" ]";

    out(result.str());
}

T100VOID T100TestNew::out_list_begin()
{
    out(L"All test units: ");
}

T100VOID T100TestNew::out_list_end()
{
    std::wstringstream      result;

    result << L"Total test " << m_units << L" units . ";

    out(result.str());
}

}
