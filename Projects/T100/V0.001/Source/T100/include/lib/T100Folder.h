#ifndef T100FOLDER_H
#define T100FOLDER_H

#include <io.h>
#include "T100Common.h"
#include "T100FileInfo.h"


class T100Folder
{
    public:
        T100Folder(T100String);
        virtual ~T100Folder();

        T100BOOL            exists();

        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            getAllFolders(T100STDSTRING_VECTOR&);
        T100BOOL            getAllFiles(T100STDSTRING_VECTOR&);
        T100BOOL            getAll(T100STDSTRING_VECTOR&);

        T100BOOL            getAllFolders(T100FILE_VECTOR&);

    protected:
        T100String          m_folder;
        T100VOID            parse(::_finddata_t&, T100FILE_VECTOR&);

    private:
};

#endif // T100FOLDER_H
