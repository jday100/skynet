#include "T100TestNodeBase.h"

#include <sstream>

T100TestNodeBase::T100TestNodeBase(T100WSTRING label, T100TestNodeBase* parent) :
    T100ObjectTreeNode(label, parent)
{
    //ctor
    init();
}

T100TestNodeBase::~T100TestNodeBase()
{
    //dtor
    uninit();
}

T100VOID T100TestNodeBase::init()
{
    m_needUnitInit          = T100FALSE;
    m_needUnitUninit        = T100FALSE;

    m_needGlobalInit        = T100FALSE;
    m_needGlobalUninit      = T100FALSE;

    m_unitInited            = T100FALSE;
    m_unitUninited          = T100FALSE;

    m_globalInited          = T100FALSE;
    m_globalUninited        = T100FALSE;

    m_consolePtr        = T100NEW T100Console();

    Append();
}

T100VOID T100TestNodeBase::uninit()
{
    m_children.clear();
    DoGlobalUninit();

    T100SAFE_DELETE m_consolePtr;
}

T100TestNodeBase* T100TestNodeBase::ConvertNode(T100ObjectTreeNode* node)
{
    return dynamic_cast<T100TestNodeBase*>(node);
}

T100Console* T100TestNodeBase::GetConsole()
{
    /*
    if(m_rootPtr){
        T100TestNodeBase*   node    = dynamic_cast<T100TestNodeBase*>(m_rootPtr);
        if(node){
            return node->GetConsole();
        }
    }
    return T100NULL;
    */
    return m_consolePtr;
}

T100RESULT T100TestNodeBase::DoGlobalInit()
{
    T100RESULT      result      = T100RESULT_SUCCESS;
    T100RESULT      value;

    if(m_parentPtr){
        T100TestNodeBase*   node =   dynamic_cast<T100TestNodeBase*>(m_parentPtr);
        if(node){
            value       = node->DoGlobalInit();
            if(result == T100RESULT_SUCCESS){
                result  = value;
            }else if(value == T100RESULT_EXCEPTION){
                result  = value;
            }
        }else{
            result  = T100RESULT_EXCEPTION;
        }
    }

    if(m_needGlobalInit && (!m_globalInited)){
        value   = GlobalInit();
        if(result == T100RESULT_SUCCESS){
            result  = value;
        }else if(value == T100RESULT_EXCEPTION){
            result  = value;
        }
    }

    return result;
}

T100RESULT T100TestNodeBase::DoGlobalUninit()
{
    return T100RESULT_SUCCESS;
}

T100RESULT T100TestNodeBase::GlobalInit()
{

}

T100RESULT T100TestNodeBase::GlobalUninit()
{

}

T100RESULT T100TestNodeBase::DoInit()
{
    return T100RESULT_SUCCESS;
}

T100RESULT T100TestNodeBase::DoUninit()
{
    return T100RESULT_SUCCESS;
}

T100RESULT T100TestNodeBase::Init()
{

}

T100RESULT T100TestNodeBase::Uninit()
{

}

T100RESULT T100TestNodeBase::DoTest()
{
    return T100RESULT_SUCCESS;
}

T100VOID T100TestNodeBase::SetIndex()
{
    T100TestNodeBase*   node        = ConvertNode(m_rootPtr);

    if(node){
        node->m_index++;
    }
}

T100VOID T100TestNodeBase::SetSuccess()
{
    T100TestNodeBase*   node        = ConvertNode(m_rootPtr);

    if(node){
        node->m_countSuccess++;
    }
}

T100VOID T100TestNodeBase::SetFailure()
{
    T100TestNodeBase*   node        = ConvertNode(m_rootPtr);

    if(node){
        node->m_countFailure++;
    }
}

T100VOID T100TestNodeBase::SetException()
{
    T100TestNodeBase*   node        = ConvertNode(m_rootPtr);

    if(node){
        node->m_countException++;
    }
}

T100VOID T100TestNodeBase::Insert()
{

}

T100VOID T100TestNodeBase::Append()
{
    T100TestNodeBase*   root    = ConvertNode(m_rootPtr);

    if(root){
        root->m_countUnits++;
    }
}

T100VOID T100TestNodeBase::Remove()
{

}

T100VOID T100TestNodeBase::Out(T100WSTRING msg)
{
    GetConsole()->OutLine(msg);
}

T100VOID T100TestNodeBase::OutTestBegin(T100WSTRING& label)
{
    T100TestNodeBase*       node;
    std::wstringstream      result;

    node    = ConvertNode(m_rootPtr);

    if(!node){
        return;
    }

    result << L"Unit [ " << node->m_index << L"/" << node->m_countUnits << L" ] : [ " << label << L" ] test is beginning ... ";

    Out(result.str());
}

T100VOID T100TestNodeBase::OutTestEnd(T100RESULT result, T100WSTRING& label)
{
    T100TestNodeBase*       node;
    std::wstringstream      ss;

    node    = ConvertNode(m_rootPtr);

    if(!node){
        return;
    }

    if(result == T100RESULT_SUCCESS){
        ss << L"[SUCCESS] ";
    }else if(result == T100RESULT_FAILURE){
        ss << L"[FAILURE] ";
    }else if(result == T100RESULT_EXCEPTION){
        ss << L"[EXCEPTION] ";
    }

    ss << L"Unit [ " << node->m_index - 1 << L"/" << node->m_countUnits << L" ] : [ " << label << L" ] test is ended . ";

    if(!m_parentPtr){
        ss << L"\n";
        ss << L"Test result: ";
        if(result == T100RESULT_SUCCESS){
            ss << L"[SUCCESS] ";
        }else if(result == T100RESULT_FAILURE){
            ss << L"[FAILURE] ";
        }else if(result == T100RESULT_EXCEPTION){
            ss << L"[EXCEPTION] ";
        }

        ss << L"Success " << node->m_countSuccess << L" units . ";
        ss << L"Failure " << node->m_countFailure << L" units . ";
        ss << L"Exception " << node->m_countException << L" units . ";
        ss << L"\n" << L"Total be tested " << node->m_countUnits << L" units . ";
    }

    Out(ss.str());
}
