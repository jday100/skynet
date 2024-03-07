#ifndef T100TREECTRLITEMDATA_H
#define T100TREECTRLITEMDATA_H

#include <wx/treectrl.h>
#include "T100Common.h"

namespace T100PROJECT{

class T100TreeCtrlItemData : public wxTreeItemData
{
    public:
        T100TreeCtrlItemData();
        virtual ~T100TreeCtrlItemData();

        T100VOID            ShowMenu(wxTreeCtrl*);

    protected:

    private:
};

}

#endif // T100TREECTRLITEMDATA_H
