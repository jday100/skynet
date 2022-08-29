#include "T100VDiskTest.h"

T100STDSTRING       T100VDiskTest::m_unit       = "vdisk";


T100VDiskTest::T100VDiskTest()
    :T100Test(m_unit)
{
    //ctor
}

T100VDiskTest::~T100VDiskTest()
{
    //dtor
}

T100BOOL T100VDiskTest::test_all()
{
    T100BOOL    result      = T100TRUE;

    return result;
}
