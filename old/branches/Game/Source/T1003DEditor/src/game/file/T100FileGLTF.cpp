#include "T100FileGLTF.h"

#include "T100FileTools.h"
#include "T1003DFileReader.h"
#include "T100FileGLTFDecoder.h"

T100FileGLTF::T100FileGLTF(T100WSTRING filename) :
    m_filename(filename)
{
    //ctor
}

T100FileGLTF::~T100FileGLTF()
{
    //dtor
}

T100VOID T100FileGLTF::Load()
{
    T1003DFileReader            reader(m_filename);
    T100JSON                    json;
    T100FileGLTFDecoder         decoder;

    reader >> json;

    m_basePath  = T100FileTools::GetBasePath(m_filename);
    decoder.Decode(json, this);
}
