#ifndef T100FOLDERDATA_H
#define T100FOLDERDATA_H

#include "T100FolderInfo.h"
#include "T100TreeItemData.h"

class T100FolderData : public T100TreeItemData
{
    public:
        T100FolderData();
        T100FolderData(T100FolderInfo*);
        virtual ~T100FolderData();

        T100VOID                    SetFolderInfo(T100FolderInfo*);
        T100FolderInfo*             GetFolderInfo();

        virtual wxMenu*             ShowMenu();

        virtual T100VOID            OnItemChanged();

        virtual T100VOID            OnItemActivated();

        virtual T100VOID            OnItemExpanding();

    protected:
        T100FolderInfo*             m_info      = T100NULL;

    private:
};

#endif // T100FOLDERDATA_H
