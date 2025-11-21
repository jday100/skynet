#include "T100CPPByteScannerTest.h"

#include "compiler/scanner/T100ByteScanner.h"

using namespace T100LIBRARY;

T100CPPByteScannerTest::T100CPPByteScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label)
{
    //ctor
}

T100CPPByteScannerTest::~T100CPPByteScannerTest()
{
    //dtor
}

T100BOOL T100CPPByteScannerTest::DoTest()
{
    T100BOOL            result;

    result  = byte_test();

    return result;
}

T100BOOL T100CPPByteScannerTest::byte_test()
{
    T100BOOL                result          = T100FALSE;
    T100INT                 length          = 0;
    T100WSTRING             filename        = L"../../resources/main.cpp";
    T100FileScanner*        fileScanner     = T100NULL;
    T100BufferScanner*      bufferScanner   = T100NULL;
    T100ByteScanner*        byteScanner     = T100NULL;
    T100ByteClassifier*     byteClassifier  = T100NULL;

    fileScanner     = T100NEW T100FileScanner();
    if(!fileScanner){
        return T100FALSE;
    }

    fileScanner->SetFile(filename);

    bufferScanner   = T100NEW T100BufferScanner();
    if(!bufferScanner){
        T100SAFE_DELETE(fileScanner);
        return T100FALSE;
    }

    bufferScanner->SetSource(fileScanner);

    byteScanner     = T100NEW T100ByteScanner();
    if(!byteScanner){
        T100SAFE_DELETE(fileScanner);
        T100SAFE_DELETE(bufferScanner);
        return T100FALSE;
    }

    byteScanner->SetSource(bufferScanner);

    byteClassifier  = T100NEW T100ByteClassifier();
    if(!byteClassifier){
        T100SAFE_DELETE(fileScanner);
        T100SAFE_DELETE(bufferScanner);
        T100SAFE_DELETE(byteScanner);
        return T100FALSE;
    }

    byteClassifier->SetScanner(byteScanner);
    byteScanner->SetClassifier(byteClassifier);

    T100BinaryFile          source(filename);

    length  = source.GetLength();

    if(length == 0){
        return T100FALSE;
    }else{
        result  = T100TRUE;
    }

    if(fileScanner->Open()){
        T100LeafState           state;
        T100ByteToken           token;

        for(int i = 0; i < length; i++){
            if(byteScanner->Next(state, token)){
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
            if(byteScanner->Next(state, token)){
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

    T100SAFE_DELETE(byteScanner);
    return result;
}
