#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"

class T100File
{
    public:
        T100File(const T100WSTRING&);
        virtual ~T100File();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100BOOL                IsExists();

        T100BOOL                Remove();

    protected:
        T100WSTRING             m_path;

    private:
};

#endif // T100FILE_H
