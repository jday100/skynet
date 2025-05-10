#ifndef T100TEXTFILEWRITER_H
#define T100TEXTFILEWRITER_H

#include "T100FileWriter.h"

class T100TextFileWriter : public T100FileWriter
{
    public:
        T100TextFileWriter();
        virtual ~T100TextFileWriter();

        T100BOOL            Write();
        T100DWORD           Seek();

    protected:

    private:
};

#endif // T100TEXTFILEWRITER_H
