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

        T100VOID            setTitle(T100STRING);
        T100STRING          getTitle();

        T100VOID            setIndex(T100INT);
        T100INT             getIndex();

    protected:

    private:
        T100INT             m_index;
        T100VOID*           m_data          = T100NULL;
        T100STRING          m_title;
};

#endif // T100WXEVENTDATA_H
