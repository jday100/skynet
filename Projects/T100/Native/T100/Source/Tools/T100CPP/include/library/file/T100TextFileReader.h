#ifndef T100TEXTFILEREADER_H
#define T100TEXTFILEREADER_H

#include "T100WString.h"
#include "T100FileReader.h"

class T100TextFileReader : public T100FileReader
{
    public:
        T100TextFileReader();
        virtual ~T100TextFileReader();

        virtual T100BOOL            read(T100WString&);

    protected:

    private:
};

#endif // T100TEXTFILEREADER_H
