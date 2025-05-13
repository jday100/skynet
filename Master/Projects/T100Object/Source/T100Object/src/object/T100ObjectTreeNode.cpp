#include "T100ObjectTreeNode.h"

T100ObjectTreeNode::T100ObjectTreeNode() :
    T100Class()
{
    //ctor
}

T100ObjectTreeNode::T100ObjectTreeNode(T100WSTRING label, T100ObjectTreeNode* parent) :
    T100Class()
{
    //ctor
    Init(label, parent);
}

T100ObjectTreeNode::~T100ObjectTreeNode()
{
    //dtor
}

T100VOID T100ObjectTreeNode::Create(T100WSTRING label, T100ObjectTreeNode* parent)
{
    Init(label, parent);
}

T100VOID T100ObjectTreeNode::Destroy()
{

}

T100VOID T100ObjectTreeNode::Init(T100WSTRING label, T100ObjectTreeNode* parent)
{
    m_label     = label;

    if(parent && this != parent){
        m_parentPtr     = parent;
        m_rootPtr       = parent->GetRootPtr();
        m_rootPtr->AddChild(label, this);
    }else{
        m_rootPtr       = this;
    }
}

T100VOID T100ObjectTreeNode::SetLabel(T100WSTRING label)
{
    m_label     = label;
}

T100WSTRING T100ObjectTreeNode::GetLabel()
{
    return m_label;
}

T100VOID T100ObjectTreeNode::AddChild(T100WSTRING label, T100ObjectTreeNode* child)
{
    m_children.append(label, child);
}

T100ObjectTreeNode* T100ObjectTreeNode::GetChildPtr(T100WSTRING label)
{
    return m_children[label];
}

T100ObjectTreeNode* T100ObjectTreeNode::GetRootPtr()
{
    return m_rootPtr;
}

T100ObjectTreeNode* T100ObjectTreeNode::GetParentPtr()
{
    return m_parentPtr;
}

T100OBJECT_TREE_NODE_VESSEL& T100ObjectTreeNode::GetChildren()
{
    return m_children;
}
