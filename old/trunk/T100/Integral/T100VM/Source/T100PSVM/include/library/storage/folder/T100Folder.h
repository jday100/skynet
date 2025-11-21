#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "T100Common.h"

class T100Folder
{
    public:
        T100Folder(const T100STRING&);
        virtual ~T100Folder();

        T100VOID                SetPath(const T100STRING&);
        const T100STRING&       GetPath();

        T100BOOL                IsExists();

        T100BOOL                Create();
        T100BOOL                Remove();

        T100VOID                List(T100STRING_VECTOR&, T100STRING_VECTOR&);

        T100VOID                GetAllFiles(T100STRING_VECTOR&);
        T100VOID                GetAllSubFolders(T100STRING_VECTOR&);

    protected:
        T100STRING              m_path;

    private:
};

#endif // T100FOLDER_H
