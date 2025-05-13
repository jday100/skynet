#include "object/T100ObjectTree.h"

T100ObjectTree::T100ObjectTree() :
    T100Class()
{
    //ctor
}

T100ObjectTree::T100ObjectTree(T100ObjectTree* parent) :
    T100Class()
{
    //ctor
    if(parent){
        m_rootPtr   = parent->GetRootPtr();
    }else{
        m_rootPtr   = this;
    }
}

T100ObjectTree::~T100ObjectTree()
{
    //dtor
}

T100VOID T100ObjectTree::Create(T100ObjectTree* parent)
{
    if(parent){
        m_rootPtr   = parent->GetRootPtr();
    }else{
        m_rootPtr   = this;
    }
}

T100VOID T100ObjectTree::Destroy()
{

}

T100VOID T100ObjectTree::AddChild(T100WSTRING label, T100ObjectTree* object)
{
    m_children.append(label, object);
}

T100ObjectTree* T100ObjectTree::GetChildPtr(T100WSTRING label)
{
    return m_children[label];
}

T100ObjectTree* T100ObjectTree::GetRootPtr()
{
    return m_rootPtr;
}

T100ObjectTree* T100ObjectTree::GetParentPtr()
{
    return m_parentPtr;
}
