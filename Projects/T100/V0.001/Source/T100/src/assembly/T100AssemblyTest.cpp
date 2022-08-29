#include "T100AssemblyTest.h"

#include "T100ByteScan.h"
#include "T100CharScan.h"
#include "T100StringScan.h"
#include "T100KeywordScan.h"
#include "T100SentenceScan.h"
#include "T100SegmentScan.h"
#include "T100FileScan.h"
#include "T100AssemblyNew.h"
#include "T100VPCApp.h"


T100STDSTRING       T100AssemblyTest::m_unit        = "assembly";


T100AssemblyTest::T100AssemblyTest(T100App* app)
    :T100Test(m_unit), m_app(app),
    test_exe(app), test_new(app), test_drafts(app)
{
    //ctor
}

T100AssemblyTest::~T100AssemblyTest()
{
    //dtor
}

T100BOOL T100AssemblyTest::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_io()){
        result = T100FALSE;
    }

    if(!test_move()){
        result = T100FALSE;
    }

    if(!test_complexus()){
        result = T100FALSE;
    }

    if(!test_byte_empty()){
        result = T100FALSE;
    }

    if(!test_byte_one()){
        result = T100FALSE;
    }

    if(!test_byte()){
        result = T100FALSE;
    }

    if(!test_char()){
        result = T100FALSE;
    }

    if(!test_string()){
        result = T100FALSE;
    }

    if(!test_keyword()){
        result = T100FALSE;
    }

    if(!test_sentence()){
        result = T100FALSE;
    }

    if(!test_segment()){
        result = T100FALSE;
    }

    if(!test_file()){
        result = T100FALSE;
    }

    if(!test_assembly()){
        result = T100FALSE;
    }

    if(!test_jump()){
        result = T100FALSE;
    }

    if(!test_complexus()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_byte_empty()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100ByteScan        test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_byte_empty.txt");

    if(test_scan.open(file)){

        T100ByteToken   token;

        if(test_scan.next(token)){
            if(0 == token.data
               && T100TRUE == token.eof
               && T100ERROR_NONE == token.err
               && 0 == token.row){

               }else{
                    result = T100FALSE;
               }
        }else{
            result = T100FALSE;
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_byte_one()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100ByteScan        test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_byte_one.txt");

    if(test_scan.open(file)){
        T100ByteToken   token;

        for(T100BYTE i=0;i<1;i++){
            if(test_scan.next(token)){
                if(49 == token.data
                   && T100FALSE == token.eof
                   && T100ERROR_NONE == token.err
                   && 0 == token.row){

                   }else{
                        result = T100FALSE;
                        break;
                   }
            }else{
                result = T100FALSE;
                break;
            }
        }

        if(result && test_scan.next(token)){
            if(0 == token.data
               && T100TRUE == token.eof
               && T100ERROR_NONE == token.err
               && 0 == token.row){

               }else{
                    result = T100FALSE;
               }
        }else{
            result = T100FALSE;
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_byte()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100ByteScan        test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_byte.txt");

    if(test_scan.open(file)){
        T100ByteToken   token;

        for(T100WORD i=0;i<256;i++){
            if(test_scan.next(token)){
                if(i == token.data
                   && T100FALSE == token.eof
                   && T100ERROR_NONE == token.err
                   && 0 == token.row){

                   }else{
                        result = T100FALSE;
                        break;
                   }
            }else{
                result = T100FALSE;
                break;
            }
        }

        if(result && test_scan.next(token)){
            if(0 == token.data
               && T100TRUE == token.eof
               && T100ERROR_NONE == token.err
               && 0 == token.row){

               }else{
                    result = T100FALSE;
               }
        }else{
            result = T100FALSE;
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_char()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100CharScan    test_scan;
    T100String      file(u8"test\\scripts\\assembly\\test_char.txt");

    if(test_scan.open(file)){
        T100CharToken   token;

        while(test_scan.next(token)){
            T100Log::info(T100AssemblyHint::char_hint(&token, ""));
            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_string()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100StringScan  test_scan;
    T100String      file(u8"test\\scripts\\assembly\\test_string.txt");

    if(test_scan.open(file)){
        T100StringToken     token;

        while(test_scan.next(token)){
            T100Log::info(T100AssemblyHint::string_hint(&token, ""));
            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_keyword()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100KeywordScan     test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_keyword.txt");

    if(test_scan.open(file)){
        T100KeywordToken    token;

        while(test_scan.next(token)){
            T100Log::info(T100AssemblyHint::keyword_hint(&token, ""));
            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_sentence()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100SentenceScan    test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_sentence.txt");

    if(test_scan.open(file)){
        T100SentenceToken   token;

        while(test_scan.next(token)){
            if(T100ERROR_NONE != token.err){
                T100Log::error(T100AssemblyHint::sentence_hint(&token, ""));
                result = T100FALSE;
            }

            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_segment()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100SegmentScan     test_scan;
    T100String          file(u8"test\\scripts\\assembly\\test_segment.txt");

    if(test_scan.open(file)){
        T100SegmentToken    token;

        while(test_scan.next(token)){
            if(T100ERROR_NONE != token.err){
                T100Log::error(T100AssemblyHint::segment_hint(&token, ""));
                result = T100FALSE;
            }

            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_file()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100FileScan    test_scan;
    T100String      file(u8"test\\scripts\\assembly\\test_file.txt");

    if(test_scan.open(file)){
        T100FileToken   token;

        while(test_scan.next(token)){
            if(T100ERROR_NONE != token.err){
                T100Log::error(T100AssemblyHint::file_hint(&token, ""));
                result = T100FALSE;
            }

            if(token.eof){
                break;
            }
        }

        if(!test_scan.close()){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_assembly()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100String      source(u8"test\\scripts\\assembly\\test_assembly.txt");
    T100String      target(u8"test\\temp\\test_assembly.out");

    value = assembly.run(source.to_std_string(), target.to_std_string());
    if(value){

    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100AssemblyTest::test_jump()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source  = "test\\scripts\\assembly\\test_jump.txt";
    target  = "test\\temp\\test_jump.out";

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target, offset);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}

T100BOOL T100AssemblyTest::test_complexus()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source  = "test\\scripts\\assembly\\test_complexus.txt";
    target  = "test\\temp\\test_complexus.out";

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target, offset);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}

T100BOOL T100AssemblyTest::test_move()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source  = "test\\scripts\\assembly\\test_move.txt";
    target  = "test\\temp\\test_move.out";

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target, offset);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}

T100BOOL T100AssemblyTest::test_io()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100Assembly    assembly;
    T100VPCApp      vpc;
    T100STDSTRING   source;
    T100STDSTRING   target;
    T100WORD        offset      = 1049600;

    source  = "test\\scripts\\assembly\\test_io.txt";
    target  = "test\\temp\\test_io.out";

    value = assembly.run(source, target);
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = vpc.run(m_app, target, offset);
        if(!value){
            result = T100FALSE;
        }

        if(0 == vpc.getReturn()){
            result = T100FALSE;
        }

        vpc.quit();
    }

    return result;
}
