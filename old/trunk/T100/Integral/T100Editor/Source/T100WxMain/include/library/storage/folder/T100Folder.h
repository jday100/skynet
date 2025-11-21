#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "T100Common.h"

class T100Folder
{
    public:
        T100Folder(const T100WSTRING&);
        virtual ~T100Folder();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100BOOL                IsExists();

        T100BOOL                Create();
        T100BOOL                Remove();

        T100VOID                List(T100WSTRING_VECTOR&, T100WSTRING_VECTOR&);

        T100VOID                GetAllFiles(T100WSTRING_VECTOR&);
        T100VOID                GetAllSubFolders(T100WSTRING_VECTOR&);

        T100VOID                GetAllFiles(T100WSTRING_VECTOR&, T100WSTRING);

    protected:
        T100WSTRING             m_path;

    private:
};

#endif // T100FOLDER_H
