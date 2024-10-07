#include "T100File.h"

#include "T100BinaryFileReader.h"

T100File::T100File()
{
    //ctor
}

T100File::T100File(T100WString name)
{
    //ctor
}

T100File::~T100File()
{
    //dtor
}

T100BOOL T100File::open()
{
    return T100FALSE;
}

T100BOOL T100File::close()
{
    return T100FALSE;
}

T100BinaryFileReader& T100File::GetBinaryReader()
{

}
