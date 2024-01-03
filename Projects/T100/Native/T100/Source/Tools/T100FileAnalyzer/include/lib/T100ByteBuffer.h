#ifndef T100BYTEBUFFER_H
#define T100BYTEBUFFER_H

#include "T100FileReader.h"


class T100ByteBuffer
{
    public:
        T100ByteBuffer(T100FileReader&);
        virtual ~T100ByteBuffer();

        char                getByte();

    protected:

    private:
        T100FileReader&     m_reader;
};

#endif // T100BYTEBUFFER_H
