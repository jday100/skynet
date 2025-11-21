#ifndef T100DATAPARSER_H
#define T100DATAPARSER_H

#include "T100File.h"

class T100DataParser
{
    public:
        T100DataParser(T100FILE_DATA&);
        virtual ~T100DataParser();

        T100BYTE*               Get(T100UINT);

    protected:
        T100FILE_DATA&          m_file;

    private:
        T100BYTE*               m_current           = T100NULL;
};

#endif // T100DATAPARSER_H
