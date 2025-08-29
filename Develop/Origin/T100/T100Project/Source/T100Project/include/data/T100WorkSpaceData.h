#ifndef T100WORKSPACEDATA_H
#define T100WORKSPACEDATA_H

#include "T100TreeItemData.h"
#include "T100WorkSpaceInfo.h"

class T100WorkSpaceData : public T100TreeItemData
{
    public:
        T100WorkSpaceData();
        T100WorkSpaceData(T100WorkSpaceInfo*);
        virtual ~T100WorkSpaceData();

        T100VOID                SetWorkSpaceInfo(T100WorkSpaceInfo*);
        T100WorkSpaceInfo*      GetWorkSpaceInfo();

        virtual wxMenu*         ShowMenu();

        virtual T100VOID        OnItemChanged();

        virtual T100VOID        OnItemActivated();

        virtual T100VOID        OnItemExpanding();

    protected:
        T100WorkSpaceInfo*      m_info      = T100NULL;

    private:
};

#endif // T100WORKSPACEDATA_H
