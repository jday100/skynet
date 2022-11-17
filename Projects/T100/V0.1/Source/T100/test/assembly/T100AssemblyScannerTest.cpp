#include "T100AssemblyScannerTest.h"

#include "T100Log.h"
#include "T100ThisAppSetup.h"
#include "T100AssemblyCommon.h"
#include "T100AssemblyTestHint.h"
#include "T100ByteToken.h"
#include "T100ByteScanner.h"
#include "T100CharScanner.h"


namespace T100Assembly{

T100WSTRING         T100AssemblyScannerTest::m_name                     = L"scanner";

T100AssemblyScannerTest::T100AssemblyScannerTest(T100Test* parent)
    :T100Library::T100Test(parent, m_name)
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

    if(result){
        value = test_char();
        if(!value){
            result = T100FALSE;
        }
    }


    return result;
}

T100BOOL T100AssemblyScannerTest::test_byte()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100Assembly::T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START);

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
        if((!value) || (T100Assembly::T100BYTE_ASCII != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_ONE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_TWO != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_THREE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_FOUR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_FIVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_SIX != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_SEVEN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_SEVEN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Assembly::T100BYTE_ASCII != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100Component::T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }

        if(!scanner->close()){
            result = T100FALSE;
        }

        T100SAFE_DELETE(scanner);
    }

    show_result(result, T100Assembly::T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP);
    return result;
}

T100BOOL T100AssemblyScannerTest::test_char()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_START);

    T100ByteScanner*            bscanner            = T100NULL;
    T100CharScanner*            cscanner            = T100NULL;
    T100CharToken               token;
    T100STRING                  file;

    if(result){
        file        = T100ThisAppSetup::getTestResources(L"assembly\\scanner\\test_char.txt");
        bscanner    = T100NEW T100ByteScanner();
        if(bscanner){
            if(bscanner->open(file)){

            }else{
                result = T100FALSE;
                T100SAFE_DELETE(bscanner);
            }
        }else{
            result = T100FALSE;
        }

        if(result){
            cscanner    = T100NEW T100CharScanner();
            if(cscanner){
                cscanner->setSource(bscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){
        value = cscanner->next(token);
        if((!value) || (T100Component::T100TOKEN_BR != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100Component::T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100Component::T100TOKEN_SPACE != token.type)){
                result = T100FALSE;
            }
        }

        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_EXCLAMATION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_DOUBLE_QUOTES != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_POUND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_DOLLAR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_PERCENT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_AND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_APOSTROPHE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_OPEN_PARENS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_CLOSED_PARENS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_ASTERISK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_PLUS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_COMMA != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_MINUS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_DOT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_SLASH != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<10;i++){
                value = cscanner->next(token);
                if((!value) || (T100CHAR_DIGIT != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_COLON != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_SEMICOLON != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_LESSTHAN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_EQUAL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_GREATERTHAN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_QUESTION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_EMAIL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<26;i++){
                value = cscanner->next(token);
                if((!value) || (T100CHAR_UPPER != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_OPEN_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_BACKSLASH != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_CLOSED_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_CARET != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_UNDERLINE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_GRAVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<26;i++){
                value = cscanner->next(token);
                if((!value) || (T100CHAR_LOWER != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_OPEN_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_VERTICALBAR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_CLOSED_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_TILDE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_UNICODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100CHAR_UNICODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if(value && T100Component::T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if(value && T100Component::T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if(!value || (T100Component::T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }

        value = bscanner->close();
        if(!value){
            result = T100FALSE;
        }
        T100SAFE_DELETE(bscanner);
        T100SAFE_DELETE(cscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_STOP);
    return result;
}

}
