#ifndef T100LISTVIEW_H
#define T100LISTVIEW_H

#include "T100Window.h"

typedef enum T100EVENT_LISTVIEW_TYPE{
    T100EVENT_LISTVIEW_SELECTED         = T100EVENT_MAX
}T100EVENT_LISTVIEW_TYPE;

class T100ListView : public T100Window
{
    public:
        T100ListView();
        T100ListView(T100Win32Application*, T100Window*);
        virtual ~T100ListView();

        T100VOID            Create(T100Win32Application*, T100Window*);

        T100VOID            Append(T100WSTRING);

    protected:

    private:
};

#endif // T100LISTVIEW_H
