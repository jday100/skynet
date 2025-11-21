#include "T100CPPFileScannerTest.h"

#include "compiler/scanner/T100FileScanner.h"

using namespace T100LIBRARY;

T100CPPFileScannerTest::T100CPPFileScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label)
{
    //ctor
}

T100CPPFileScannerTest::~T100CPPFileScannerTest()
{
    //dtor
}


T100BOOL T100CPPFileScannerTest::DoTest()
{
    T100BOOL        result;

    result  = file_test();

    return result;
}

T100BOOL T100CPPFileScannerTest::file_test()
{
    T100BOOL                result      = T100FALSE;
    T100WSTRING             filename    = L"../../resources/main.cpp";
    T100FileScanner*        scanner     = T100NULL;

    scanner     = T100NEW T100FileScanner();

    if(!scanner){
        return T100FALSE;
    }

    scanner->SetFile(filename);

    if(scanner->Open()){
        result  = T100TRUE;

        T100LeafState       state;
        T100FileToken       token;
        T100BYTE            data[1024];
        T100UINT            length      = 1024;

        token.Data      = data;
        token.Length    = length;

        if(scanner->Next(state, token)){
            if(token.Length == 115){

            }else{
                result  = T100FALSE;
            }

            if(state.Eof || state.Error){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }

        if(result){
            if(scanner->Next(state, token)){
                result = T100FALSE;
            }else{
                if(state.Eof){
                    if(state.Error){
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }

                if(token.Length != 0){
                    result = T100FALSE;
                }
            }
        }

        if(!scanner->Close()){
            result  = T100FALSE;
        }
    }

    T100SAFE_DELETE(scanner);
    return result;
}
