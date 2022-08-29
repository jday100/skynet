#include "T100ScannerTest.h"

#include "T100AssemblyTestHint.h"
#include "T100AssemblySetup.h"
#include "T100ByteScanner.h"
#include "T100CharScanner.h"
#include "T100StringScanner.h"
#include "T100KeywordScanner.h"


T100WSTRING     T100ScannerTest::m_name                 = L"scanner";


T100ScannerTest::T100ScannerTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100ScannerTest::~T100ScannerTest()
{
    //dtor
}

T100BOOL T100ScannerTest::do_test()
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
    if(result){
        value = test_keyword();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ScannerTest::test_byte()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START);

    T100ByteScanner*            scanner         = T100NULL;
    T100ByteToken               token;
    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_byte.txt");
        scanner = T100NEW T100ByteScanner();
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
        if((!value) || (T100BYTE_ASCII != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_ONE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_TWO != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_THREE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_FOUR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_FIVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_SIX != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_SEVEN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_SEVEN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100BYTE_ASCII != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = scanner->next(token);
            if((!value) || (T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }

        if(!scanner->close()){
            result = T100FALSE;
        }

        T100SAFE_DELETE(scanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP);
    return result;
}

T100BOOL T100ScannerTest::test_char()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_START);

    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100CharToken               token;
    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_char.txt");

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
        if((!value) || (T100TOKEN_BR != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if((!value) || (T100TOKEN_SPACE != token.type)){
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
            if(value && T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if(value && T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscanner->next(token);
            if(!value || (T100TOKEN_EOF != token.type)){
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

T100BOOL T100ScannerTest::test_keyword()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_KEYWORD_TEST_START);

    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100StringScanner*          sscanner        = T100NULL;
    T100KeywordScanner*         kscanner        = T100NULL;
    T100KeywordToken            token;
    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_keyword.txt");
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

        if(result){
            sscanner    = T100NEW T100StringScanner();
            if(sscanner){
                sscanner->setSource(cscanner);
            }else{
                result = T100FALSE;
            }
        }

        if(result){
            kscanner    = T100NEW T100KeywordScanner();
            if(kscanner){
                kscanner->setSource(sscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){
        value = kscanner->next(token);
        if((!value) || (T100KEYWORD_ADD != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_SUB != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_MUL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_DIV != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_AND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_OR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_NOT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_XOR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LOCK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_UNLOCK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_NOP != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_HALT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_CMT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_DEBUG != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_CALL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_RETURN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_INT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_IRET != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_JUMP != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_JZ != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_JNZ != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LOOP != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_IN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_OUT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_INTEGER != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_FLOAT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_STRING != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_MODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_REAL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_TINY != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VIRTUAL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LOCATION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LENGTH != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_DEFAULT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_IMPORT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_CODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_DATA != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_PROCEDURE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_END != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_COR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_CBR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_CCR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_AAR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_ABR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_ACR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_ADR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_ACF != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_AMF != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_AOF != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        //
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_EXCLAMATION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_STRING != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_POUND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_COMMENT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_COLON != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_EMAIL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_OPEN_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_CLOSED_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_OPEN_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CHAR_CLOSED_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_INTEGER != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_INTEGER != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_INTEGER != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_INTEGER != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_FLOAT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100CONSTANT_FLOAT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        //
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100KEYWORD_LABEL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }


        if(result){
            value = kscanner->next(token);
            if((!value) || (T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }


        value = bscanner->close();
        if(!value){
            result = T100FALSE;
        }
        T100SAFE_DELETE(bscanner);
        T100SAFE_DELETE(cscanner);
        T100SAFE_DELETE(sscanner);
        T100SAFE_DELETE(kscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_KEYWORD_TEST_STOP);
    return result;
}
