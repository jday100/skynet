#ifndef T100LAYOUT_H
#define T100LAYOUT_H

#include "object/T100Tree.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100Window;

class T100Layout : public T100Class
{
    public:
        T100Layout();
        virtual ~T100Layout();

        virtual T100VOID            Update() = 0;

        T100VOID                    SetParent(T100Window*);
        T100VOID                    SetChildren(T100TREE_VECTOR&);

    protected:
        T100Window*                 m_parent        = T100NULL;
        T100TREE_VECTOR*            m_children      = T100NULL;

    private:
};

}

#endif // T100LAYOUT_H
