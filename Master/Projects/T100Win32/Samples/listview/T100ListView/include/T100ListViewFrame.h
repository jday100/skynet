#ifndef T100LISTVIEWFRAME_H
#define T100LISTVIEWFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100ListView.h"

class T100ListViewFrame : public T100Frame
{
    public:
        T100ListViewFrame(T100Win32Application*);
        virtual ~T100ListViewFrame();

        T100VOID            Create(T100WSTRING);

    protected:
        T100ListView        m_listView;

        T100VOID            OnWindowMessage(T100WindowEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100LISTVIEWFRAME_H
