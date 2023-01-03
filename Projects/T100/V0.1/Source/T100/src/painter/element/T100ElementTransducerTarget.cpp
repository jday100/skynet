#include "T100ElementTransducerTarget.h"

namespace T100Painter{

T100ElementTransducerTarget::T100ElementTransducerTarget(T100Library::T100BufferedFileWriter* writer)
    :T100DiagramTransducerTarget(writer)
{
    //ctor
}

T100ElementTransducerTarget::~T100ElementTransducerTarget()
{
    //dtor
}

/*
T100BOOL T100ElementTransducerTarget::setWORD(T100WORD value)
{
    m_writer->write(&value, 1);
}

T100BOOL T100ElementTransducerTarget::setFLOAT(T100FLOAT value)
{
    T100WORD*       data            = T100NULL;

    data = (T100WORD*)&value;

    m_writer->write(data, 1);
}
*/

}
