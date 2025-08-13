#ifndef T100FOLDERDATA_H
#define T100FOLDERDATA_H

#include <atomic>
#include "T100FolderInfo.h"
#include "T100TreeItemData.h"

class T100FolderData : public T100TreeItemData
{
    public:
        T100FolderData();
        T100FolderData(T100FolderInfo*);
        virtual ~T100FolderData();

        T100VOID                    SetLabel(const T100WSTRING&);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

        T100VOID                    SetOpened(T100BOOL);

        virtual wxMenu*             ShowMenu();

        virtual T100VOID            OnItemChanged();

        virtual T100VOID            OnItemActivated();

        virtual T100VOID            OnItemExpanding();

    protected:
        std::atomic_bool            m_opened;
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100FOLDERDATA_H
