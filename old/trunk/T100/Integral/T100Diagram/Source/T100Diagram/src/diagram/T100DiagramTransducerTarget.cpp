#include "T100DiagramTransducerTarget.h"

T100DiagramTransducerTarget::T100DiagramTransducerTarget(T100BufferedFileReader* reader) :
    T100TransducerTarget(),
    m_reader(reader)
{
    //ctor
}

T100DiagramTransducerTarget::T100DiagramTransducerTarget(T100BufferedFileWriter* writer) :
    T100TransducerTarget(),
    m_writer(writer)
{
    //ctor
}

T100DiagramTransducerTarget::~T100DiagramTransducerTarget()
{
    //dtor
}

T100BOOL T100DiagramTransducerTarget::SetUINT(T100UINT value)
{
    T100BYTE*       data        = T100NULL;

    data = (T100BYTE*)&value;

    return m_writer->Write(data, sizeof(T100UINT));
}

T100BOOL T100DiagramTransducerTarget::GetUINT(T100UINT& value)
{
    T100UINT        length;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100UINT);
    data    = (T100BYTE*)&value;

    if(m_reader->Read(data, length)){
        if(sizeof(T100UINT) == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::SetINTEGER(T100INT value)
{
    T100UINT        length;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100INT);
    data    = (T100BYTE*)&value;

    return m_writer->Write(data, length);
}

T100BOOL T100DiagramTransducerTarget::GetINTEGER(T100INT& value)
{
    T100UINT        length;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100INT);
    data    = (T100BYTE*)&value;

    if(m_reader->Read(data, length)){
        if(sizeof(T100INT) == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::SetFLOAT(T100FLOAT value)
{
    T100UINT        length;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100FLOAT);
    data    = (T100BYTE*)&value;

    return m_writer->Write(data, length);
}

T100BOOL T100DiagramTransducerTarget::GetFLOAT(T100FLOAT& value)
{
    T100UINT        length;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100FLOAT);
    data    = (T100BYTE*)&value;

    if(m_reader->Read(data, length)){
        if(sizeof(T100FLOAT) == length){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::SetSTRING(T100WSTRING& value)
{
    T100UINT        length          = 0;
    T100BYTE*       data            = T100NULL;

    length  = sizeof(T100WCHAR) * value.length();
    data    = (T100BYTE*)value.c_str();

    if(!SetUINT(length))return T100FALSE;

    if(m_writer->Write(data, length)){
        if(SetUINT(0)){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::GetSTRING(T100WSTRING& value)
{
    T100UINT        size            = 0;
    T100UINT        length          = 0;
    T100BYTE*       data            = T100NULL;

    if(!GetUINT(size))return T100FALSE;

    T100BYTE        buffer[size + 2];

    data    = buffer;
    length  = size;

    buffer[size] = 0;
    buffer[size + 1] = 0;

    if(!m_reader->Read(data, length))return T100FALSE;

    if(size == length){

    }else{
        return T100FALSE;
    }

    value = (T100WCHAR*)data;

    T100UINT        temp;

    if(!GetUINT(temp))return T100FALSE;

    if(temp != 0)return T100FALSE;

    return T100TRUE;
}

T100BOOL T100DiagramTransducerTarget::Reset()
{
    if(m_reader){
        return m_reader->Seek(0);
    }

    if(m_writer){
        return m_writer->Seek(0);
    }
    return T100FALSE;
}

T100BOOL T100DiagramTransducerTarget::Eof()
{
    if(m_reader){
        return m_reader->Eof();
    }
    return T100FALSE;
}
