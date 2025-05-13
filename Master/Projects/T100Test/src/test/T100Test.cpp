#include "T100Test.h"

#include <sstream>

T100Test::T100Test(T100Test* parent, T100WSTRING name) :
    T100TestBase(parent, name)
{
    //ctor
    init();
}

T100Test::~T100Test()
{
    //dtor
    uninit();
}

T100VOID T100Test::init()
{
    m_needUnitInit          = T100FALSE;
    m_needUnitUninit        = T100FALSE;

    m_needGlobalInit        = T100FALSE;
    m_needGlobalUninit      = T100FALSE;

    m_unitInited            = T100FALSE;
    m_unitUninited          = T100FALSE;

    m_globalInited          = T100FALSE;
    m_globalUninited        = T100FALSE;

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

    Add();
}

T100VOID T100Test::uninit()
{
    m_tests.clear();
    DoGlobalUninit();
    T100SAFE_DELETE(m_console);
}

T100VOID T100Test::SetGlobalInit(T100BOOL flag)
{
    m_needGlobalInit        = flag;
}

T100VOID T100Test::SetGlobalUninit(T100BOOL flag)
{
    m_needGlobalUninit      = flag;
}

T100VOID T100Test::SetInit(T100BOOL flag)
{
    m_needUnitInit      = flag;
}

T100VOID T100Test::SetUninit(T100BOOL flag)
{
    m_needUnitUninit    = flag;
}

T100RESULT T100Test::TestAll()
{
    T100RESULT        result          = T100RESULT_SUCCESS;
    T100RESULT        value;

    if(!m_parent){
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    if(!m_parent){
        result = DoGlobalInit();
    }

    for(T100Test* entry : m_tests.getVector()){
        if(this == entry){

        }else{
            if(entry->TestAll()){

            }else{
                result = T100RESULT_FAILURE;
            }
        }
    }

    OutTestBegin(m_name);

    DoInit();

    Index();

    if(DoTest()){

    }else{
        result = T100RESULT_FAILURE;
    }

    DoUninit();

    if(result){
        Success();
    }else{
        Failure();
    }

    OutTestEnd(result, m_name);

    if(!m_parent){
        value = DoGlobalUninit();
        if(!value){
            result = T100RESULT_FAILURE;
        }
    }

    return result;
}

T100RESULT T100Test::TestUnit(T100WSTRING name)
{
    T100RESULT      result          = T100RESULT_SUCCESS;

    if(L"all" == name){
        return TestAll();
    }

    T100Test*       test            = T100NULL;

    test = m_tests[name];

    if(test){
        result = test->TestAll();
    }else{
        result = T100RESULT_FAILURE;
    }

    return result;
}

T100VOID T100Test::List()
{
    if(!m_parent){
        OutListBegin();
    }

    OutList(m_name);

    for(T100Test* entry : m_tests.getVector()){
        if(this == entry){

        }else{
            entry->List();
        }
    }

    if(!m_parent){
        OutListEnd();
    }
}

T100RESULT T100Test::Find(T100WSTRING name)
{
    T100RESULT      result          = T100RESULT_FAILURE;

    T100Test*       test            = T100NULL;

    test = m_tests[name];

    if(test){
        result = T100RESULT_SUCCESS;
    }

    return result;
}

T100VOID T100Test::ShowResult(T100RESULT result, T100WSTRING& msg)
{
    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] " << msg;
    }else{
        ss << L"[FAILURE] " << msg;
    }

    Out(ss.str());
}

