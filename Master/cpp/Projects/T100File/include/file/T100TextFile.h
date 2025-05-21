#ifndef T100TEXTFILE_H
#define T100TEXTFILE_H

#include "T100File.h"

class T100TextFile : public T100File
{
    public:
        T100TextFile(T100WSTRING);
        virtual ~T100TextFile();

        T100BOOL            Open();
        T100BOOL            Close();

    protected:

    private:
};

#endif // T100TEXTFILE_H
