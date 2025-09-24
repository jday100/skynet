#ifndef T100PROJECTFILE_H
#define T100PROJECTFILE_H

#include "T100XML.h"

class T100ProjectFile : public T100XML
{
    public:
        T100ProjectFile(const T100WSTRING&);
        virtual ~T100ProjectFile();

        T100BOOL            Check();

    protected:

    private:
};

#endif // T100PROJECTFILE_H
