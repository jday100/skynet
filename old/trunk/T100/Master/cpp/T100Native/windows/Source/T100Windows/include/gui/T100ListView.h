#ifndef T100LISTVIEW_H
#define T100LISTVIEW_H

#include "gui/T100ListViewStyle.h"
#include "gui/control/T100Control.h"
#include "gui/common/T100ListViewCommon.h"

namespace T100WINDOWS{

class T100ListView : public T100Control
{
    public:
        T100ListView();
        T100ListView(T100Window*);
        virtual ~T100ListView();

        virtual T100VOID            Create(T100Window*, T100ListViewStyle* = T100NULL);
        virtual T100VOID            Destroy();

        T100VOID                    Append(const T100WSTRING&);
        T100VOID                    Remove();

    protected:

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100LISTVIEW_H
