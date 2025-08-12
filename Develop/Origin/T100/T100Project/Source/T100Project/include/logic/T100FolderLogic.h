#ifndef T100FOLDERLOGIC_H
#define T100FOLDERLOGIC_H

#include "T100Common.h"

class T100FolderLogic
{
    public:
        T100FolderLogic();
        virtual ~T100FolderLogic();

        T100BOOL            IsExists(const T100WSTRING&);

        T100BOOL            Open(const T100WSTRING&);

    protected:

    private:
};

#endif // T100FOLDERLOGIC_H
