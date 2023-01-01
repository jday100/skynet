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

T100BOOL T100DiagramTransducerTarget::setWORD(T100WORD value)
{
    m_writer->write(&value, 1);
}

T100BOOL T100DiagramTransducerTarget::setFLOAT(T100FLOAT value)
{
    T100WORD*       data            = T100NULL;

    data = (T100WORD*)&value;

    m_writer->write(data, 1);
}

}
