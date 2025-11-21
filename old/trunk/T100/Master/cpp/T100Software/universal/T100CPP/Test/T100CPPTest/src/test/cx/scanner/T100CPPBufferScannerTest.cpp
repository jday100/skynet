#include "T100CPPBufferScannerTest.h"

#include "compiler/scanner/T100BufferScanner.h"

using namespace T100LIBRARY;

T100CPPBufferScannerTest::T100CPPBufferScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label)
{
    //ctor
}

T100CPPBufferScannerTest::~T100CPPBufferScannerTest()
{
    //dtor
}

T100BOOL T100CPPBufferScannerTest::DoTest()
{
    T100BOOL            result;

    result  = buffer_test();

    return result;
}

T100BOOL T100CPPBufferScannerTest::buffer_test()
{
    T100BOOL                result          = T100FALSE;
    T100WSTRING             filename        = L"../../resources/main.cpp";
    T100FileScanner*        fileScanner     = T100NULL;
    T100BufferScanner*      bufferScanner   = T100NULL;

    fileScanner     = T100NEW T100FileScanner();
    bufferScanner   = T100NEW T100BufferScanner();

    if(fileScanner){
        if(bufferScanner){
            result  = T100TRUE;
        }else{
            T100SAFE_DELETE(fileScanner);
            return T100FALSE;
        }
    }else{
        return T100FALSE;
    }

    fileScanner->SetFile(filename);
    bufferScanner->SetSource(fileScanner);

    if(fileScanner->Open()){
        T100LeafState           state;
        T100BufferToken         token;

        for(int i = 0; i < 115; i++){
            if(bufferScanner->Next(state, token)){
                if(token.Value == 0){
                    result = T100FALSE;
                    break;
                }
            }else{
                result = T100FALSE;
                break;
            }
        }

        if(result){
            if(bufferScanner->Next(state, token)){
                result = T100FALSE;
            }else{
                if(state.Eof){

                }else{
                    if(state.Error){
                        result = T100FALSE;
                    }
                }
            }
        }

        if(fileScanner->Close()){

        }else{
            result  = T100FALSE;
        }
    }else{
        result  = T100FALSE;
    }

    T100SAFE_DELETE(bufferScanner);
    return result;
}
