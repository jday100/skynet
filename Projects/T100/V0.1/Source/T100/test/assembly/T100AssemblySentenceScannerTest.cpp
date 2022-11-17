#include "T100AssemblySentenceScannerTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100ByteScanner.h"
#include "T100CharScanner.h"
#include "T100StringScanner.h"
#include "T100KeywordScanner.h"
#include "T100SentenceScanner.h"


namespace T100Assembly{

T100WSTRING         T100AssemblySentenceScannerTest::m_name                         = L"scanner.sentence";

T100AssemblySentenceScannerTest::T100AssemblySentenceScannerTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AssemblySentenceScannerTest::~T100AssemblySentenceScannerTest()
{
    //dtor
}

T100BOOL T100AssemblySentenceScannerTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_sentence();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100AssemblySentenceScannerTest::test_sentence()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_START);

    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100StringScanner*          strscanner      = T100NULL;
    T100KeywordScanner*         kscanner        = T100NULL;
    T100SentenceScanner*        senscanner      = T100NULL;
    T100SentenceToken           token;
    T100STRING                  file;

    if(result){
        file    = T100ThisAppSetup::getTestResources(L"assembly\\scanner\\test_sentence.txt");

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
            strscanner  = T100NEW T100StringScanner();
            if(strscanner){
                strscanner->setSource(cscanner);
            }else{
                result = T100FALSE;
            }
        }

        if(result){
            kscanner    = T100NEW T100KeywordScanner();
            if(kscanner){
                kscanner->setSource(strscanner);
            }else{
                result = T100FALSE;
            }
        }

        if(result){
            senscanner  = T100NEW T100SentenceScanner();
            if(senscanner){
                senscanner->setSource(kscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){

        value = senscanner->next(token);
        if((!value) || (T100SENTENCE_ADD != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_SUB != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MUL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_DIV != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_AND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_OR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_NOT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_XOR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_LOCK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_UNLOCK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_NOP != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_HALT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_CMT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_DEBUG != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_CALL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_RETURN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_INT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_IRET != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_JUMP != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_JZ != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_JNZ != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_LOOP != token.type)){
                result = T100FALSE;
            }
        }


        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_IN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_OUT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MOVE != token.type)){
                result = T100FALSE;
            }
        }

        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_VARIABLE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_MODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_IMPORT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_CODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_DATA != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_END != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100SENTENCE_PROCEDURE != token.type)){
                result = T100FALSE;
            }
        }



        //
        if(result){
            value = senscanner->next(token);
            if((!value) || (T100Component::T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }

        value = bscanner->close();
        if(!value){
            result = T100FALSE;
        }
        T100SAFE_DELETE(bscanner);
        T100SAFE_DELETE(cscanner);
        T100SAFE_DELETE(strscanner);
        T100SAFE_DELETE(kscanner);
        T100SAFE_DELETE(senscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_SENTENCE_TEST_STOP);
    return result;
}

}
