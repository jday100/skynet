#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "storage/filesystem/T100FileSystemEntry.h"

namespace T100LIBRARY{

class T100Folder : public T100FileSystemEntry
{
    public:
        T100Folder(const T100WSTRING&);
        virtual ~T100Folder();

    protected:

    private:
};

}

#endif // T100FOLDER_H
