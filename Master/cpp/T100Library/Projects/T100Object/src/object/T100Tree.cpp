#include "T100Tree.h"

namespace T100LIBRARY{

T100Tree::T100Tree() :
    T100Object()
{
    //ctor
}

T100Tree::T100Tree(T100Tree* parent, const T100WSTRING& label) :
    T100Object()
{
    //ctor
    SetLabel(label);
    init(parent);
}

T100Tree::~T100Tree()
{
    //dtor
    uninit();
}

T100VOID T100Tree::init(T100Tree* parent)
{
    if(parent){
        m_parent    = parent;
        m_root      = parent->GetRoot();

        m_parent->AppendChild(this);
    }else{
        m_root      = this;
    }
}

T100VOID T100Tree::uninit()
{

}

T100VOID T100Tree::Create(T100Tree* parent, const T100WSTRING& label)
{

}

T100VOID T100Tree::Destroy()
{

}

T100VOID T100Tree::SetRoot(T100Tree* root)
{
    m_root      = root;
}

T100Tree* T100Tree::GetRoot()
{
    return m_root;
}

T100VOID T100Tree::SetParent(T100Tree* parent)
{
    m_parent    = parent;
}

T100Tree* T100Tree::GetParent()
{
    return m_parent;
}

T100TREE_VECTOR& T100Tree::GetChildren()
{
    return m_children;
}

T100VOID T100Tree::AppendChild(T100Tree* child)
{
    m_children.push_back(child);
}

T100VOID T100Tree::RemoveChild(T100Tree* child)
{
    T100TREE_VECTOR::iterator   it;

    for(it = m_children.begin(); it != m_children.end(); ++it){
        if(child == *it){
            m_children.erase(it);
            return;
        }
    }
}

}
