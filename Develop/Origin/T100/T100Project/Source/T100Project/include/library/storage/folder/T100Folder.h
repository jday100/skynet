#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "T100FSEntry.h"

class T100Folder : public T100FSEntry
{
    public:
        T100Folder(const T100WSTRING&);
        virtual ~T100Folder();

        T100BOOL            Create();

        T100VOID            List(T100WSTRING_VECTOR&, T100WSTRING_VECTOR&);

        T100VOID            GetAllSubFolders(T100WSTRING_VECTOR&);
        T100VOID            GetAllFiles(T100WSTRING_VECTOR&);

    protected:

    private:
};

#endif // T100FOLDER_H
