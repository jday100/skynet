#ifndef T100TREEVIEW_H
#define T100TREEVIEW_H

#include "gui/T100TreeCtrlStyle.h"
#include "gui/control/T100Control.h"

namespace T100WINDOWS{

class T100TreeView : public T100Control
{
    public:
        T100TreeView();
        T100TreeView(T100Window*);
        virtual ~T100TreeView();

        virtual T100VOID            Create(T100Window*, T100TreeCtrlStyle* = T100NULL);
        virtual T100VOID            Destroy();

        T100VOID                    Append(const T100WSTRING&);


    protected:

    private:
        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100TREEVIEW_H
