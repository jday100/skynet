#ifndef T100LISTVIEW_H
#define T100LISTVIEW_H

#include <windows.h>
#include <commctrl.h>
#include "gui/control/T100Control.h"

typedef enum T100EVENT_LISTVIEW_TYPE{
    T100EVENT_LISTVIEW_SELECTED         = NM_CLICK
}T100EVENT_LISTVIEW_TYPE;

class T100Win32Application;

class T100ListView : public T100Control
{
    public:
        T100ListView();
        T100ListView(T100Win32Application*, T100Window*);
        virtual ~T100ListView();

        T100VOID                    Create(T100Win32Application*, T100Window*);

        T100VOID                    Append(T100WSTRING);

        virtual T100VOID            ProcessWindowMessage(T100WindowMessageData&);
        virtual T100VOID            ProcessNotifyMessage(T100WindowMessageData&);

    protected:

    private:
};

#endif // T100LISTVIEW_H
