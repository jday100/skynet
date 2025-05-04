#ifndef T100OBJECTTREE_H
#define T100OBJECTTREE_H

#include "T100Vessel.h"
#include "T100Object.h"

#define     T100OBJECT_TREE_VESSEL      T100Vessel<T100WSTRING, T100Object*>

class T100ObjectTree
{
    public:
        T100ObjectTree(T100Object*);
        virtual ~T100ObjectTree();

        T100VOID                    AddChild(T100WSTRING, T100Object*);
        T100Object*                 GetChildPtr(T100WSTRING);

        T100Object*                 GetParentPtr();

    protected:
        T100Object*                 m_parentPtr         = T100NULL;
        T100OBJECT_TREE_VESSEL      m_children;

    private:
};

#endif // T100OBJECTTREE_H
