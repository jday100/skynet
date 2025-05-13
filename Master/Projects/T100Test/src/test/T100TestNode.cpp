#include "T100TestNode.h"

T100TestNode::T100TestNode(T100WSTRING label, T100TestNode* parent) :
    T100TestNodeBase(label, parent)
{
    //ctor
    init();
}

T100TestNode::~T100TestNode()
{
    //dtor
    uninit();
}

T100VOID T100TestNode::init()
{
}

T100VOID T100TestNode::uninit()
{

}

T100RESULT T100TestNode::TestAll()
{
    T100RESULT              result      = T100RESULT_SUCCESS;
    T100RESULT              value;

    if(!m_parentPtr){
        m_index             = 1;
        m_countSuccess      = 0;
        m_countFailure      = 0;
        m_countException    = 0;
    }

    if(!m_parentPtr){
        result  = DoGlobalInit();
    }

    for(T100ObjectTreeNode* entry : m_children.getVector()){
        if(!entry){
            result  = T100RESULT_EXCEPTION;
        }else{
            if(this == entry){

            }else{
                T100TestNode*   node    = dynamic_cast<T100TestNode*>(entry);

                if(node){
                    T100RESULT  temp    = node->TestAll();
                    if(result == T100RESULT_SUCCESS){
                        result      = temp;
                    }else if(temp == T100RESULT_EXCEPTION){
                        result      = temp;
                    }
                }else{
                    result  = T100RESULT_EXCEPTION;
                }
            }
        }
    }

    OutTestBegin(m_label);

    value   = DoInit();
    if(result == T100RESULT_SUCCESS){
        result  = value;
    }else if(value == T100RESULT_EXCEPTION){
        result  = value;
    }
    SetIndex();

    value   = DoTest();
    if(result == T100RESULT_SUCCESS){
        result  = value;
    }else if(value == T100RESULT_EXCEPTION){
        result  = value;
    }

    value   = DoUninit();
    if(result == T100RESULT_SUCCESS){
        result  = value;
    }else if(value == T100RESULT_EXCEPTION){
        result  = value;
    }

    if(result == T100RESULT_SUCCESS){
        SetSuccess();
    }else if(result == T100RESULT_FAILURE){
        SetFailure();
    }else if(result == T100RESULT_EXCEPTION){
        SetException();
    }

    OutTestEnd(result, m_label);

    if(!m_parentPtr){
        value   = DoGlobalUninit();
        if(result == T100RESULT_SUCCESS){
            result  = value;
        }else if(value == T100RESULT_EXCEPTION){
            result  = value;
        }
    }

    return result;
}

T100VOID T100TestNode::ShowResult(T100RESULT result, T100WSTRING& msg)
{

}
