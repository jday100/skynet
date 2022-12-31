#include "T100BufferedFile.h"

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100BufferedFileStream.h"

namespace T100Library{

T100BufferedFile::T100BufferedFile(T100WSTRING file)
    :T100File(file)
{
    //ctor
}

T100BufferedFile::~T100BufferedFile()
{
    //dtor
}

T100BufferedFileReader* T100BufferedFile::getReader()
{
    return T100NEW T100BufferedFileReader(getName());
}

T100BufferedFileWriter* T100BufferedFile::getWriter()
{
    return T100NEW T100BufferedFileWriter(getName());
}

T100BufferedFileStream* T100BufferedFile::getStream()
{
    return T100NEW T100BufferedFileStream(getName());
}

}
