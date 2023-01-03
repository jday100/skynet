#include "T100DiagramTransducerTarget.h"

namespace T100Painter{

T100DiagramTransducerTarget::T100DiagramTransducerTarget(T100Library::T100BufferedFileReader* reader)
    :T100Library::T100TransducerTarget(), m_reader(reader)
{
    //ctor
}

T100DiagramTransducerTarget::T100DiagramTransducerTarget(T100Library::T100BufferedFileWriter* writer)
    :T100Library::T100TransducerTarget(), m_writer(writer)
{
    //ctor
}

T100DiagramTransducerTarget::~T100DiagramTransducerTarget()
{
    //dtor
}

T100BOOL T100DiagramTransducerTarget::reset()
{
    if(m_reader){
        return m_reader->seek(0);
    }

    if(m_writer){
        return m_writer->seek(0);
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::eof()
{
    if(m_reader){
        return m_reader->eof();
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::setWORD(T100WORD value)
{
    return m_writer->write(&value, 1);
}

T100BOOL T100DiagramTransducerTarget::getWORD(T100WORD& value)
{
    T100WORD        length;

    length  = 1;

    if(m_reader->read(&value, length)){
        if(1 == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::setFLOAT(T100FLOAT value)
{
    T100WORD*       data            = T100NULL;

    data = (T100WORD*)&value;

    return m_writer->write(data, 1);
}

T100BOOL T100DiagramTransducerTarget::getFLOAT(T100FLOAT& value)
{
    T100WORD        length          = 1;
    T100WORD*       data            = T100NULL;

    data = (T100WORD*)&value;

    if(m_reader->read(data, length)){
        if(1 == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

}
