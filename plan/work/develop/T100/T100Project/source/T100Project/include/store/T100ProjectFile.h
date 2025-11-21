#ifndef T100PROJECTFILE_H
#define T100PROJECTFILE_H

#include "T100XML.h"

class T100ProjectFile : T100XML
{
    public:
        T100ProjectFile(const T100WSTRING&);
        virtual ~T100ProjectFile();

        T100BOOL                IsExists();

        T100BOOL                Check(const T100WSTRING&);

        T100BOOL                Create();

    protected:

    private:
};

#endif // T100PROJECTFILE_H
