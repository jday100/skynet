#include "T100CPPStringScannerTest.h"

#include "console/T100Console.h"
#include "compiler/scanner/T100StringScanner.h"

using namespace T100LIBRARY;

T100CPPStringScannerTest::T100CPPStringScannerTest(T100Test* parent, const T100WSTRING& label) :
    T100Test(parent, label)
{
    //ctor
}

T100CPPStringScannerTest::~T100CPPStringScannerTest()
{
    //dtor
}

T100BOOL T100CPPStringScannerTest::DoTest()
{
    T100BOOL        result;

    result  = string_test();

    return result;
}

T100BOOL T100CPPStringScannerTest::string_test()
{
    T100BOOL                result          = T100FALSE;
    T100Console             console;
    T100WSTRING             filename        = L"../../resources/main.cpp";
    T100FileScanner*        fileScanner     = T100NULL;
    T100BufferScanner*      bufferScanner   = T100NULL;
    T100ByteScanner*        byteScanner     = T100NULL;
    T100CharScanner*        charScanner     = T100NULL;

    T100ByteClassifier*     byteClassifier  = T100NULL;
    T100CharClassifier*     charClassifier  = T100NULL;

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

    charScanner     = T100NEW T100CharScanner();
    if(!charScanner){
        T100SAFE_DELETE(fileScanner);
        T100SAFE_DELETE(bufferScanner);
        T100SAFE_DELETE(byteScanner);
        return T100FALSE;
    }

    charScanner->SetSource(byteScanner);

    charClassifier  = T100NEW T100CharClassifier();
    if(!charClassifier){
        T100SAFE_DELETE(fileScanner);
        T100SAFE_DELETE(bufferScanner);
        T100SAFE_DELETE(byteScanner);
        T100SAFE_DELETE(charScanner);
        return T100FALSE;
    }

    charClassifier->SetScanner(charScanner);
    charScanner->SetClassifier(charClassifier);

    T100LeafState           state;
    T100CharToken           token;

    if(fileScanner->Open()){
        do{
            result  = charScanner->Next(state, token);
            if(result){
                if(token.Value == 0){
                    result  = T100FALSE;
                    break;
                }else{
                    T100WSTRING     value   = &token.Value;
                    console.OutLine(value);
                }
            }
        }while(result);

        if(state.Eof){
            if(state.Error){
                result  = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }

        if(fileScanner->Close()){

        }else{
            result  = T100FALSE;
        }
    }else{
        result  = T100FALSE;
    }

    T100SAFE_DELETE(charScanner);
    return result;
}
