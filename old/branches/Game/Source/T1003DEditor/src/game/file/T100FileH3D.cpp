#include "T100FileH3D.h"

#include "T100FileTools.h"
#include "T100FileH3DDecoder.h"

T100FileH3D::T100FileH3D(T100WSTRING filename) :
    m_filename(filename)
{
    //ctor
}

T100FileH3D::~T100FileH3D()
{
    //dtor
}

T100VOID T100FileH3D::Load()
{
    T100FileH3DDecoder          decoder;

    m_buffer    = T100FileTools::ReadBinaryFile(m_filename);

    decoder.Decode(this);
}
