#include "T100AssemblyPartScannerTest.h"

#include "T100ThisAppSetup.h"
#include "T100AssemblyTestHint.h"
#include "T100ByteScanner.h"
#include "T100CharScanner.h"
#include "T100StringScanner.h"
#include "T100KeywordScanner.h"
#include "T100SentenceScanner.h"
#include "T100SegmentScanner.h"
#include "T100PartScanner.h"

namespace T100Assembly{

T100WSTRING         T100AssemblyPartScannerTest::m_name                         = L"scanner.part";

T100AssemblyPartScannerTest::T100AssemblyPartScannerTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AssemblyPartScannerTest::~T100AssemblyPartScannerTest()
{
    //dtor
}

T100BOOL T100AssemblyPartScannerTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(result){
        value = test_part();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100AssemblyPartScannerTest::test_part()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    T100Library::T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_START);


    T100ByteScanner*            bscanner        = T100NULL;
    T100CharScanner*            cscanner        = T100NULL;
    T100StringScanner*          strscanner      = T100NULL;
    T100KeywordScanner*         kscanner        = T100NULL;
    T100SentenceScanner*        senscanner      = T100NULL;
    T100SegmentScanner*         segscanner      = T100NULL;
    T100PartScanner*            pscanner        = T100NULL;
    T100PartToken               token;
    T100STRING                  file;

    if(result){
        file        = T100ThisAppSetup::getTestResources(L"assembly\\scanner\\test_part.txt");
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

        if(result){
            pscanner  = T100NEW T100PartScanner();
            if(segscanner){
                pscanner->setSource(segscanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){
        value = pscanner->next(token);
        if((!value) || (T100PART_IMPORT != token.type)){
            result = T100FALSE;
        }
        if(result){
            int i;

            i = token.segments.size();
            //i = token.segments[0]->sentences.size();

        }

        if(result){
            value = pscanner->next(token);
            if((!value) || (T100PART_SOURCE != token.type)){
                result = T100FALSE;
            }
            if(result){
                if(3 != token.segments.size()){
                    result = T100FALSE;
                }else if(1 != token.segments[0]->sentences.size()
                         || 2 != token.segments[1]->sentences.size()
                         || 2 != token.segments[2]->sentences.size()){
                    result = T100FALSE;
                }
            }
        }

        //
        if(result){
            value = pscanner->next(token);
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
        T100SAFE_DELETE(segscanner);
        T100SAFE_DELETE(pscanner);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_PART_TEST_STOP);
    return result;
}

}
