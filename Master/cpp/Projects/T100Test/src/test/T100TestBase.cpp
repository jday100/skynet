#include "T100TestBase.h"

#include <sstream>
#include "T100Test.h"

T100TestBase::T100TestBase(T100TestBase* parent, T100WSTRING name) :
    T100ObjectTreeNode(name, parent)
{
    //ctor
    if(parent){
        parent->AddChild(name, this);
    }else{
        m_rootPtr   = this;
    }
}

T100TestBase::~T100TestBase()
{
    //dtor
}

T100RESULT T100TestBase::DoInit()
{

}

T100RESULT T100TestBase::DoUninit()
{

}

T100RESULT T100TestBase::Init()
{

}

T100RESULT T100TestBase::Uninit()
{

}

T100RESULT T100TestBase::DoGlobalInit()
{
    T100RESULT      result;
    if(m_parent){
        m_parent->DoGlobalInit();
    }

    if(m_needGlobalInit && (!m_globalInited)){
        result  = GlobalInit();
        if(result == T100RESULT_SUCCESS){
            m_globalInited  = T100TRUE;
        }
    }
    return result;
}

T100RESULT T100TestBase::DoGlobalUninit()
{
    T100RESULT      result;
    if(m_needGlobalUninit && (!m_globalUninited)){
        result = GlobalUninit();
        if(result == T100RESULT_SUCCESS){
            m_globalUninited    = T100TRUE;
        }
    }

    if(m_parent){
        //m_parent->do_global_uninit();
    }
    return result;
}

T100RESULT T100TestBase::GlobalInit()
{
    return T100RESULT_FAILURE;
}

T100RESULT T100TestBase::GlobalUninit()
{
    return T100RESULT_FAILURE;
}

T100VOID T100TestBase::Index()
{
    if(m_parent){
        m_parent->Index();
        return;
    }

    m_index++;
}

T100VOID T100TestBase::Success()
{
    if(m_parent){
        m_parent->Success();
        return;
    }

    m_success++;
}

T100VOID T100TestBase::Failure()
{
    if(m_parent){
        m_parent->Failure();
        return;
    }

    m_failure++;
}

T100Console* T100TestBase::GetConsole()
{
    if(m_parent){
        return m_parent->GetConsole();
    }
    return m_console;
}

T100VOID T100TestBase::Add()
{

}

T100RESULT T100TestBase::DoTest()
{
    return T100RESULT_SUCCESS;
}

T100VOID T100TestBase::Out(T100WSTRING msg)
{
    GetConsole()->OutLine(msg);
}

T100VOID T100TestBase::OutTestBegin(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"Unit [ " << m_index << L"/" << m_units << L" ] : [ " << name << L" ] test is beginning ... ";

    Out(result.str());
}

T100VOID T100TestBase::OutTestEnd(T100BOOL result, T100WSTRING& name)
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

    Out(ss.str());
}

T100VOID T100TestBase::OutList(T100WSTRING& name)
{
    std::wstringstream      result;

    result << L"\t Test unit: [ " << name << L" ]";

    Out(result.str());
}

T100VOID T100TestBase::OutListBegin()
{
    Out(L"All test units: ");
}

T100VOID T100TestBase::OutListEnd()
{
    std::wstringstream      result;

    result << L"Total test " << m_units << L" units . ";

    Out(result.str());
}

T100VOID T100TestBase::Insert(T100WSTRING, T100Test*)
{

}

T100VOID T100TestBase::Append(T100WSTRING, T100Test*)
{

}

T100VOID T100TestBase::Remove(T100WSTRING)
{

}
