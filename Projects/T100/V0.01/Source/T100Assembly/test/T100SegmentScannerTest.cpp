#include "T100SegmentScannerTest.h"

#include "T100AssemblySetup.h"
#include "T100AssemblyTestHint.h"
#include "T100ByteScanner.h"
#include "T100CharScanner.h"
#include "T100StringScanner.h"
#include "T100KeywordScanner.h"
#include "T100SentenceScanner.h"
#include "T100SegmentScanner.h"


T100WSTRING         T100SegmentScannerTest::m_name                      = L"scanner.segment";


T100SegmentScannerTest::T100SegmentScannerTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100SegmentScannerTest::~T100SegmentScannerTest()
{
    //dtor
}

T100BOOL T100SegmentScannerTest::do_test()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;


    if(result){
        value = test_segment();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100SegmentScannerTest::test_segment()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_START);

    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100StringScanner*          strscanner      = T100NULL;
    T100KeywordScanner*         kscanner        = T100NULL;
    T100SentenceScanner*        senscanner      = T100NULL;
    T100SegmentScanner*         segscanner      = T100NULL;
    T100SegmentToken            token;
    T100WSTRING                 file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_segment.txt");

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

        if(result){
            segscanner  = T100NEW T100SegmentScanner();
            if(segscanner){
                segscanner->setSource(senscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){
        value = segscanner->next(token);
        if((!value) || (T100SEGMENT_MODE != token.type)){
            result = T100FALSE;
        }
        if(result){
            if(1 != token.sentences.size()){
                result = T100FALSE;
            }
        }
        if(result){
            value = segscanner->next(token);
            if((!value) || (T100SEGMENT_CODE != token.type)){
                result = T100FALSE;
            }
            if(result){
                if(2 != token.sentences.size()){
                    result = T100FALSE;
                }
            }
        }
        if(result){
            value = segscanner->next(token);
            if((!value) || (T100SEGMENT_DATA != token.type)){
                result = T100FALSE;
            }
            if(result){
                if(2 != token.sentences.size()){
                    result = T100FALSE;
                }
            }
        }

        //
        if(result){
            value = segscanner->next(token);
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
        T100SAFE_DELETE(strscanner);
        T100SAFE_DELETE(kscanner);
        T100SAFE_DELETE(senscanner);
        T100SAFE_DELETE(segscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_SEGMENT_TEST_STOP);
    return result;
}
