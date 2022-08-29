#include "T100PartTest.h"

#include "T100String.h"
#include "T100AppSetup.h"
#include "T100PartDrawer.h"

#include "T100PartScannerTools.h"


T100WSTRING         T100PartTest::m_name                        = L"produce.part";


T100PartTest::T100PartTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100PartTest::~T100PartTest()
{
    //dtor
}

T100BOOL T100PartTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_part();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100PartTest::test_part()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100PartDrawer              drawer;
    T100STRING                  source;
    T100STRING                  target;

    source = T100AppSetup::getTestResources(L"assembly\\real\\test_basic.txt");
    target = T100AppSetup::getTestBuild(L"test_basic.prt");

    if(result){
        drawer.parse(source);
    }

    return result;
}
