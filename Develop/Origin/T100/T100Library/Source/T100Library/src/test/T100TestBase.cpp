#include "test/T100TestBase.h"

#include <sstream>

namespace T100LIBRARY{

T100TestBase::T100TestBase() :
    T100Tree()
{
    //ctor
    init();
}

T100TestBase::~T100TestBase()
{
    //dtor
    uninit();
}

T100VOID T100TestBase::SetNeedGlobalInit(T100BOOL flag)
{
    m_needGlobalInit    = flag;
}

T100BOOL T100TestBase::IsNeedGlobalInit()
{
    return m_needGlobalInit;
}

T100VOID T100TestBase::SetNeedGlobalUninit(T100BOOL flag)
{
    m_needGlobalUninit  = flag;
}

T100BOOL T100TestBase::IsNeedGlobalUninit()
{
    return m_needGlobalUninit;
}

T100VOID T100TestBase::SetNeedInit(T100BOOL flag)
{
    m_needUnitInit      = flag;
}

T100BOOL T100TestBase::IsNeedInit()
{
    return m_needUnitInit;
}

T100VOID T100TestBase::SetNeedUninit(T100BOOL flag)
{
    m_needUnitUninit    = flag;
}

T100BOOL T100TestBase::IsNeedUninit()
{
    return m_needUnitUninit;
}

T100BOOL T100TestBase::doInit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::doUninit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::init()
{
    if(m_parent){

    }else{
        m_console   = T100NEW T100Console();
    }
    return T100FALSE;
}

T100BOOL T100TestBase::uninit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::doGlobalInit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::doGlobalUninit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::globalInit()
{
    return T100FALSE;
}

T100BOOL T100TestBase::globalUninit()
{
    return T100FALSE;
}

T100VOID T100TestBase::doIndex()
{

}

T100VOID T100TestBase::doSuccess()
{

}

T100VOID T100TestBase::doFailure()
{

}

T100VOID T100TestBase::doException()
{

}

T100BOOL T100TestBase::DoTest()
{

}

T100Console* T100TestBase::getConsole()
{
    T100Console*        result      = T100NULL;
    T100TestBase*       root        = T100NULL;

    root    = dynamic_cast<T100TestBase*>(m_root);

    if(root){
        if(this == root){
            result = m_console;
        }else{
            result = root->getConsole();
        }
    }
    return result;
}

T100VOID T100TestBase::out(const T100WSTRING& value)
{
    getConsole()->OutLine(value);
}

T100VOID T100TestBase::outTestBegin(const T100WSTRING& value)
{
    std::wstringstream      result;

    result << L"Unit [ " << m_index << L"/" << m_units << L" ] : [ " << value << L" ] test is beginning ... ";

    out(result.str());
}

T100VOID T100TestBase::outTestEnd(T100BOOL result, const T100WSTRING& value)
{

    std::wstringstream      ss;

    if(result){
        ss << L"[SUCCESS] ";
    }else{
        ss << L"[FAILURE] ";
    }

    ss << L"Unit [ " << m_index - 1 << L"/" << m_units << L" ] : [ " << value << L" ] test is ended . ";

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

T100VOID T100TestBase::outList(const T100WSTRING& value)
{
    std::wstringstream      result;

    result << L"\t Test unit: [ " << value << L" ]";

    out(result.str());
}

T100VOID T100TestBase::outListBegin()
{
    out(L"All test units: ");
}

T100VOID T100TestBase::outListEnd()
{
    std::wstringstream      result;

    result << L"Total test " << m_units << L" units . ";

    out(result.str());
}

}
