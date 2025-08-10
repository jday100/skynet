#ifndef T100WORKSPACEFILE_H
#define T100WORKSPACEFILE_H

#include "T100XML.h"

class T100WorkSpaceFile : public T100XML
{
    public:
        T100WorkSpaceFile(const T100WSTRING&);
        virtual ~T100WorkSpaceFile();

        T100BOOL                IsExists();

        T100BOOL                Load();
        T100VOID                Save();

    protected:
        T100WSTRING             m_filename;

    private:
};

#endif // T100WORKSPACEFILE_H
