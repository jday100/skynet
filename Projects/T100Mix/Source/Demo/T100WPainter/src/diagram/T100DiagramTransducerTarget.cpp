#include "T100DiagramTransducerTarget.h"

T100DiagramTransducerTarget::T100DiagramTransducerTarget(T100BufferedFile* file)
    :m_file(file)
{
    //ctor
}

T100DiagramTransducerTarget::~T100DiagramTransducerTarget()
{
    //dtor
}

T100BOOL T100DiagramTransducerTarget::setINTEGER(T100INT value)
{
    T100VOID*   data;
    T100WORD    length;

    m_file->write((T100WORD*)value, 1);
}

T100BOOL T100DiagramTransducerTarget::getINTEGER(T100INT& value)
{
    T100VOID*   data;
    T100WORD    length;

    length  = 1;
    m_file->read((T100WORD*)&value, length);
}

T100BOOL T100DiagramTransducerTarget::setWORD(T100WORD value)
{
    T100VOID*   data;
    T100WORD    length;

    m_file->write(&value, 1);
}

T100BOOL T100DiagramTransducerTarget::getWORD(T100WORD& value)
{
    T100VOID*   data;
    T100WORD    length;

    length  = 1;
    m_file->read(&value, length);
}

T100BOOL T100DiagramTransducerTarget::setFLOAT(T100FLOAT value)
{
    T100VOID*   data;
    T100WORD    length;

    m_file->write((T100WORD*)&value, 1);
}

T100BOOL T100DiagramTransducerTarget::getFLOAT(T100FLOAT& value)
{
    T100VOID*   data;
    T100WORD    length;

    length  = 1;
    m_file->read((T100WORD*)&value, length);
}

T100BOOL T100DiagramTransducerTarget::eof()
{
    return m_file->eof();
}
