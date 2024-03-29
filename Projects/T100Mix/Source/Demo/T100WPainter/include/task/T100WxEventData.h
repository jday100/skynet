#ifndef T100WXEVENTDATA_H
#define T100WXEVENTDATA_H

#include <wx/event.h>
#include "T100Common.h"

class T100WxEventData : public wxObject
{
    public:
        T100WxEventData();
        virtual ~T100WxEventData();

        T100VOID            setData(T100VOID*);
        T100VOID*           getData();

    protected:

    private:
        T100VOID*           m_data          = T100NULL;
};

#endif // T100WXEVENTDATA_H
