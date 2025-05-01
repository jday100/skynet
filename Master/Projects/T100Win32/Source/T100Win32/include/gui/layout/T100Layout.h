#ifndef T100LAYOUT_H
#define T100LAYOUT_H

#include "T100Common.h"
#include "gui/T100Window.h"

class T100Layout
{
    public:
        T100Layout();
        virtual ~T100Layout();

        virtual T100VOID            Update() = 0;

        T100VOID                    SetParentPtr(T100Window*);
        T100VOID                    SetChildren(T100WINDOW_VECTOR&);

    protected:
        T100Window*                 m_parentPtr         = T100NULL;
        T100WINDOW_VECTOR*          m_childrenPtr       = T100NULL;

    private:

};

#endif // T100LAYOUT_H
