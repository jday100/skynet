#include "T100Tree.h"

T100Tree::T100Tree(T100Tree* parent, const T100WSTRING& label) :
    T100Object()
{
    //ctor
    m_label     = label;

    if(parent){
        parent->AppendChild(m_label, this);
    }
}

T100Tree::~T100Tree()
{
    //dtor
}

T100VOID T100Tree::AppendChild(const T100WSTRING& label, T100Tree* child)
{
    m_children.Append(label, child);
}

T100VOID T100Tree::RemoveChild(const T100WSTRING& label)
{
    m_children.Remove(label);
}
