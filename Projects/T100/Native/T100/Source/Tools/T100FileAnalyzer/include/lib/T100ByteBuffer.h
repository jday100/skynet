#ifndef T100BYTEBUFFER_H
#define T100BYTEBUFFER_H

#include "T100FileReader.h"


class T100ByteBuffer
{
    public:
        T100ByteBuffer(T100FileReader&);
        virtual ~T100ByteBuffer();

        char                getByte();

        bool                load();

    protected:

    private:
        int                 m_index         = -1;
        int                 m_count         = -1;
        int                 m_length        = 1024;
        char*               m_buffer        = nullptr;
        T100FileReader&     m_reader;
};

#endif // T100BYTEBUFFER_H
