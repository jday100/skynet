#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "T100DirectoryEntry.h"


class T100Folder : public T100DirectoryEntry
{
    public:
        T100Folder(T100WSTRING);
        virtual ~T100Folder();

    protected:

    private:
};

#endif // T100FOLDER_H
