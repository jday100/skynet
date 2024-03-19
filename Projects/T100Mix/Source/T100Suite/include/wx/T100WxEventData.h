#ifndef T100WXEVENTDATA_H
#define T100WXEVENTDATA_H

#include <wx/event.h>
#include "T100Common.h"


class T100WxEventData : public wxObject
{
    public:
        T100WxEventData();
        virtual ~T100WxEventData();

        T100VOID            setObject(T100VOID*);
        T100VOID*           getObject();

    protected:

    private:
        T100VOID*           m_object        = T100NULL;
};

#endif // T100WXEVENTDATA_H
