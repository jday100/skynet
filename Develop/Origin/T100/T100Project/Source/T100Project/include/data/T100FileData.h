#ifndef T100FILEDATA_H
#define T100FILEDATA_H

#include <atomic>
#include "T100FileInfo.h"
#include "T100TreeItemData.h"

class T100FileData : public T100TreeItemData
{
    public:
        T100FileData();
        T100FileData(T100FileInfo*);
        virtual ~T100FileData();

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

#endif // T100FILEDATA_H
