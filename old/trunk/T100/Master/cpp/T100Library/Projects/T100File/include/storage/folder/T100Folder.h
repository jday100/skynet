#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "storage/filesystem/T100FileSystemEntry.h"

namespace T100LIBRARY{

class T100Folder : public T100FileSystemEntry
{
    public:
        T100Folder(const T100WSTRING&);
        virtual ~T100Folder();

        T100BOOL            FindFirst(T100WSTRING&, const T100WSTRING&, T100INT);
        T100BOOL            FindNext(T100WSTRING&);
        T100BOOL            FindFinished();

    protected:

    private:
};

}

#endif // T100FOLDER_H
