#ifndef T100THISAPPTEST_H
#define T100THISAPPTEST_H

#include "T100Test.h"
#include "T100LibraryTest.h"
#include "T100AssemblyTest.h"
#include "T100FontBuilderTest.h"
#include "T100VDiskTest.h"
#include "T100VPCTest.h"
#include "T100FullTest.h"
#include "T100OSTest.h"


namespace T100ThisAppTest{

class T100ThisAppTest : public T100Library::T100Test
{
    public:
        T100ThisAppTest();
        virtual ~T100ThisAppTest();

    protected:
        T100Library::T100LibraryTest            test_library;
        T100Assembly::T100AssemblyTest          test_assembly;
        T100Font::T100FontBuilderTest           test_font;
        T100VDisk::T100VDiskTest                test_vdisk;
        T100VPC::T100VPCTest                    test_vpc;

        T100::T100FullTest                      test_full;

        T100OS::T100OSTest                      test_os;

    private:
        static T100WSTRING                      m_name;

};

}

#endif // T100THISAPPTEST_H
