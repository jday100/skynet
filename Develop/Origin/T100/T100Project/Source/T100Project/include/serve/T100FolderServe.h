#ifndef T100FOLDERSERVE_H
#define T100FOLDERSERVE_H

#include "T100FolderInfo.h"

class T100FolderServe
{
    public:
        T100FolderServe();
        virtual ~T100FolderServe();

        T100BOOL            IsExists(const T100WSTRING&);

        T100BOOL            List(T100FolderInfo*);

        T100BOOL            Clear();

    protected:

    private:
};

#endif // T100FOLDERSERVE_H
