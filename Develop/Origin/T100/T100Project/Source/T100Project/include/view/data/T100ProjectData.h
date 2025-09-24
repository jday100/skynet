#ifndef T100PROJECTDATA_H
#define T100PROJECTDATA_H

#include "T100ProjectInfo.h"
#include "T100TreeItemData.h"

class T100ProjectData : public T100TreeItemData
{
    public:
        T100ProjectData(T100ProjectInfo*);
        virtual ~T100ProjectData();

        T100ProjectInfo*            GetProjectInfo();

        virtual wxMenu*             CreateMenu();

        virtual T100VOID            OnItemChanged();

        virtual T100VOID            OnItemActivated();

        virtual T100VOID            OnItemExpanding();

    protected:
        T100ProjectInfo*            m_info      = T100NULL;

    private:
};

#endif // T100PROJECTDATA_H
