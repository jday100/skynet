#ifndef T100PROJECTDATA_H
#define T100PROJECTDATA_H

#include "T100ProjectInfo.h"
#include "T100TreeItemData.h"

class T100ProjectData : public T100TreeItemData
{
    public:
        T100ProjectData();
        T100ProjectData(T100ProjectInfo*);
        virtual ~T100ProjectData();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        virtual wxMenu*         ShowMenu();

        virtual T100VOID        OnItemActivated();

        virtual T100VOID        OnItemExpanding();

    protected:
        T100WSTRING             m_label;

    private:
};

#endif // T100PROJECTDATA_H
