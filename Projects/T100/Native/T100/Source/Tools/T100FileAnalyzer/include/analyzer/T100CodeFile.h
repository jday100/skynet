#ifndef T100CODEFILE_H
#define T100CODEFILE_H

#include "T100ByteBuffer.h"


class T100CodeFile
{
    public:
        T100CodeFile(T100ByteBuffer&);
        virtual ~T100CodeFile();

        int run();

    protected:
        int parse();

        T100ByteBuffer&             m_buffer;

    private:

};

#endif // T100CODEFILE_H
