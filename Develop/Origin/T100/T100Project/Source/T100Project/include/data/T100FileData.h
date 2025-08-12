#ifndef T100FILEDATA_H
#define T100FILEDATA_H

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

        virtual wxMenu*             ShowMenu();

        virtual T100VOID            OnItemExpanding();

    protected:
        T100WSTRING                 m_label;

    private:
};

#endif // T100FILEDATA_H
