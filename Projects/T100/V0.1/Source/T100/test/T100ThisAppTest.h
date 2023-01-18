#ifndef T100THISAPPTEST_H
#define T100THISAPPTEST_H

#include "T100Test.h"
#include "T100LibraryTest.h"
#include "T100AssemblyTest.h"
#include "T100WidgetTest.h"
#include "T100PainterTest.h"
#include "T100FontBuilderTest.h"
#include "T100VDiskTest.h"
#include "T100VPCTest.h"
#include "T100FullTest.h"
#include "T100OSTest.h"
#include "T100DeployTest.h"
#include "T100DeployBTest.h"


namespace T100{

class T100ThisAppTest : public T100Library::T100Test
{
    public:
        T100ThisAppTest();
        virtual ~T100ThisAppTest();

    protected:
        T100Library::T100LibraryTest            test_library;
        T100Assembly::T100AssemblyTest          test_assembly;
        T100WxWidgets::T100WidgetTest           test_widget;
        T100Painter::T100PainterTest            test_painter;
        T100Font::T100FontBuilderTest           test_font;
        T100VDisk::T100VDiskTest                test_vdisk;
        T100VPC::T100VPCTest                    test_vpc;

        T100::T100FullTest                      test_full;

        T100OS::T100OSTest                      test_os;

        T100::T100DeployTest                    test_deploy;
        T100::T100DeployBTest                   test_deploy_b;

    private:
        static T100WSTRING                      m_name;

};

}

#endif // T100THISAPPTEST_H
