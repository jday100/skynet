#ifndef T100OBJECTTREENODE_H
#define T100OBJECTTREENODE_H

#include "vessel/T100Vessel.h"
#include "base/T100Object.h"

#define     T100OBJECT_TREE_NODE_VESSEL             T100Vessel<T100WSTRING, T100ObjectTreeNode*>

class T100ObjectTreeNode : public T100Class
{
    public:
        T100ObjectTreeNode();
        T100ObjectTreeNode(T100WSTRING, T100ObjectTreeNode*);
        virtual ~T100ObjectTreeNode();

        virtual T100VOID                        Create(T100WSTRING, T100ObjectTreeNode*);
        virtual T100VOID                        Destroy();

        virtual T100VOID                        SetLabel(T100WSTRING);
        virtual T100WSTRING                     GetLabel();

        virtual T100VOID                        AddChild(T100WSTRING, T100ObjectTreeNode*);
        virtual T100ObjectTreeNode*             GetChildPtr(T100WSTRING);

        virtual T100ObjectTreeNode*             GetRootPtr();
        virtual T100ObjectTreeNode*             GetParentPtr();

        virtual T100OBJECT_TREE_NODE_VESSEL&    GetChildren();

    protected:
        T100WSTRING                             m_label;
        T100ObjectTreeNode*                     m_rootPtr           = T100NULL;
        T100ObjectTreeNode*                     m_parentPtr         = T100NULL;
        T100OBJECT_TREE_NODE_VESSEL             m_children;

    private:
        T100VOID                                Init(T100WSTRING, T100ObjectTreeNode*);
};

#endif // T100OBJECTTREENODE_H
