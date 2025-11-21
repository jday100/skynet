#ifndef T100EDITABLE_H
#define T100EDITABLE_H

#include <atomic>
#include "T1003DObject.h"

class T100Editable : public T1003DObject
{
    public:
        T100Editable();
        virtual ~T100Editable();

        T100VOID                    SetEditable(T100BOOL = T100TRUE);
        T100BOOL                    IsEditable();

    protected:
        std::atomic_bool            m_editable;
        T1003DObject*               m_selectionPtr          = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100EDITABLE_H
