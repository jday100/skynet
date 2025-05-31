#include "object/T100ObjectTreeNode.h"

T100ObjectTreeNode::T100ObjectTreeNode() :
    T100Object()
{
    //ctor
}

T100ObjectTreeNode::T100ObjectTreeNode(T100WSTRING label, T100ObjectTreeNode* parent) :
    T100Object(label)
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
    m_children.clear();
}

T100VOID T100ObjectTreeNode::Init(T100WSTRING label, T100ObjectTreeNode* parent)
{
    if(parent && this != parent){
        m_parentPtr     = parent;
        m_rootPtr       = parent->GetRootPtr();
        m_parentPtr->AddChild(label, this);
    }else{
        m_rootPtr       = this;
    }
}

T100VOID T100ObjectTreeNode::AddChild(T100WSTRING label, T100ObjectTreeNode* child)
{
    T100ObjectTreeNode*     node    = m_children[label];
    if(node){

    }else{

    }

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
