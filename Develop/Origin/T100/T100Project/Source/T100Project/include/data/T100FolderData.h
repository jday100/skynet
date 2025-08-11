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

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        virtual wxMenu*         ShowMenu();

    protected:
        T100WSTRING             m_label;

    private:
};

#endif // T100FOLDERDATA_H
