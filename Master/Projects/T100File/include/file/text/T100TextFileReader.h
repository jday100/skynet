#ifndef T100TEXTFILEREADER_H
#define T100TEXTFILEREADER_H

#include "T100FileReader.h"

class T100TextFileReader : public T100FileReader
{
    public:
        T100TextFileReader();
        virtual ~T100TextFileReader();

        T100BOOL            Read();
        T100DWORD           Seek();

    protected:

    private:
};

#endif // T100TEXTFILEREADER_H
