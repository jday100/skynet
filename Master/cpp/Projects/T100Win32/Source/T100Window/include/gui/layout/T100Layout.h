#ifndef T100LAYOUT_H
#define T100LAYOUT_H

#include "T100Common.h"
#include "base/T100Class.h"
#include "object/T100ObjectTreeNode.h"

class T100Window;

class T100Layout : public T100Class
{
    public:
        T100Layout();
        virtual ~T100Layout();

        virtual T100VOID                    Update() = 0;

        T100VOID                            SetParent(T100Window*);
        T100VOID                            SetChildren(T100OBJECT_TREE_NODE_VECTOR&);

    protected:
        T100Window*                         m_parentPtr         = T100NULL;
        T100OBJECT_TREE_NODE_VECTOR*        m_childrenPtr       = T100NULL;

    private:
};

#endif // T100LAYOUT_H
