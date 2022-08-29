#include "T100ExecutableNormalSmallFile.h"

#include <assert.h>


T100ExecutableNormalSmallFile::T100ExecutableNormalSmallFile()
{
    //ctor
}

T100ExecutableNormalSmallFile::~T100ExecutableNormalSmallFile()
{
    //dtor
}

T100BOOL T100ExecutableNormalSmallFile::load(T100FileData* data)
{
    assert(data != T100NULL);
    assert(data->getCode() != T100NULL);
    assert(data->getData() != T100NULL);

    //m_file      = data;
    //m_code      = data->getCode();
    //m_data      = data->getData();

    return T100TRUE;
}
