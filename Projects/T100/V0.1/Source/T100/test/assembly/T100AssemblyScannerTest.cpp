#include "T100AssemblyScannerTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100ByteToken.h"
#include "T100ByteScanner.h"


namespace T100Library{

T100AssemblyScannerTest::T100AssemblyScannerTest(T100Test* parent)
    :T100Library::T100Test(parent, L"")
{
    //ctor
}

T100AssemblyScannerTest::~T100AssemblyScannerTest()
{
    //dtor
}

T100BOOL T100AssemblyScannerTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_byte();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyScannerTest::test_byte()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100Assembly::T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START);

    T100Assembly::T100ByteScanner*          scanner         = T100NULL;
    T100Assembly::T100ByteToken             token;
    T100STRING                              file;

    if(result){
        file    = T100ThisAppSetup::getTestResources(L"assembly\\scanner\\test_byte.txt");
        scanner = T100NEW T100Assembly::T100ByteScanner();
        if(scanner){
            if(scanner->open(file)){

            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner->next(token);
        if((!value) || (T100Component::T100BYTE_ASCII != token.type)){
            result = T100FALSE;
        }

        if(!scanner->close()){
            result = T100FALSE;
        }

        T100SAFE_DELETE(scanner);
    }

    show_result(result, T100Assembly::T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP);
    return result;
}

}
