#ifndef T100FOLDERLOGIC_H
#define T100FOLDERLOGIC_H

#include "T100FolderInfo.h"

class T100FolderLogic
{
    public:
        T100FolderLogic();
        virtual ~T100FolderLogic();

        T100BOOL            IsExists(const T100WSTRING&);

        T100BOOL            Create(const T100WSTRING&);
        T100BOOL            Remove(T100FolderInfo*);

        T100BOOL            List(const T100WSTRING&, T100FolderInfo*);

        T100BOOL            Rename(T100FolderInfo*);

    protected:

    private:
};

#endif // T100FOLDERLOGIC_H
