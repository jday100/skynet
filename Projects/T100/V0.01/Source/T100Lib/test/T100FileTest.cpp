#include "T100FileTest.h"

#include "T100String.h"
#include "T100AppSetup.h"
#include "T100DirectoryEntry.h"
#include "T100File.h"
#include "T100FileReader.h"
#include "T100FileWriter.h"


T100WSTRING         T100FileTest::m_name                    = L"lib.file";


T100FileTest::T100FileTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100FileTest::~T100FileTest()
{
    //dtor
}

T100BOOL T100FileTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_file();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100FileTest::test_file()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100String          name;

    name = T100AppSetup::getTestStores(L"test_file.txt");

    T100DirectoryEntry      entry(name.to_wstring());

    value = entry.exists();
    if(value){
        result = T100FALSE;
    }

    if(result){
        T100File        file(name.to_wstring());

        value = file.exists();
        if(value){
            value = file.remove();
            if(value){
                value = file.exists();
                if(value){
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = file.create();
            if(value){
                value = file.exists();
                if(!value){
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }
        }
    }


    return result;
}
