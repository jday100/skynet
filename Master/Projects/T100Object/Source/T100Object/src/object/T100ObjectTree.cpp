#include "object/T100ObjectTree.h"

T100ObjectTree::T100ObjectTree(T100ObjectTree*) :
    T100Class()
{
    //ctor
}

T100ObjectTree::~T100ObjectTree()
{
    //dtor
}

T100VOID T100ObjectTree::AddChild(T100WSTRING label, T100Object* object)
{
    m_children.append(label, object);
}

T100Object* T100ObjectTree::GetChildPtr(T100WSTRING label)
{
    return m_children[label];
}

T100Object* T100ObjectTree::GetParentPtr()
{
    return m_parentPtr;
}
