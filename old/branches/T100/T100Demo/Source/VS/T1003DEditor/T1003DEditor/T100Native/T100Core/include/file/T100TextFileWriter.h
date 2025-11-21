#ifndef T100TEXTFILEWRITER_H
#define T100TEXTFILEWRITER_H

#include "T100Common.h"

class T100TextFileWriter
{
    public:
        T100TextFileWriter(T100WSTRING);
        virtual ~T100TextFileWriter();

        T100BOOL            Open();
        T100BOOL            Close();

        T100BOOL            Write(T100WSTRING);

    protected:

    private:
};

#endif // T100TEXTFILEWRITER_H
