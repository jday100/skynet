#ifndef T100FILEDATA_H
#define T100FILEDATA_H

#include "T100FileInfo.h"
#include "T100TreeItemData.h"

class T100FileData : public T100TreeItemData
{
    public:
        T100FileData(T100FileInfo*);
        virtual ~T100FileData();

        T100FileInfo*           GetFileInfo();

        virtual wxMenu*         CreateMenu();

        virtual T100VOID        OnItemChanged();

        virtual T100VOID        OnItemActivated();

        virtual T100VOID        OnItemExpanding();

    protected:
        T100FileInfo*           m_info      = T100NULL;

    private:
};

#endif // T100FILEDATA_H
