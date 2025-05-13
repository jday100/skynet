#ifndef T100OBJECTTREE_H
#define T100OBJECTTREE_H

#include "vessel/T100Vessel.h"
#include "base/T100Object.h"

#define     T100OBJECT_TREE_VESSEL      T100Vessel<T100WSTRING, T100ObjectTree*>

class T100ObjectTree : public T100Class
{
    public:
        T100ObjectTree();
        T100ObjectTree(T100ObjectTree*);
        virtual ~T100ObjectTree();

        T100VOID                    Create(T100ObjectTree*);
        T100VOID                    Destroy();

        T100VOID                    AddChild(T100WSTRING, T100ObjectTree*);
        T100ObjectTree*             GetChildPtr(T100WSTRING);

        T100ObjectTree*             GetRootPtr();
        T100ObjectTree*             GetParentPtr();

    protected:
        T100ObjectTree*             m_rootPtr           = T100NULL;
        T100ObjectTree*             m_parentPtr         = T100NULL;
        T100OBJECT_TREE_VESSEL      m_children;

    private:
};

#endif // T100OBJECTTREE_H
