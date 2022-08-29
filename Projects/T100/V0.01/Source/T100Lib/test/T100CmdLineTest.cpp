#include "T100CmdLineTest.h"

#include "T100Log.h"
#include "T100LibTestHint.h"
#include "T100Unicode.h"
#include "T100CmdLineParser.h"


T100WSTRING         T100CmdLineTest::m_name                     = L"cmdline";


T100CmdLineTest::T100CmdLineTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100CmdLineTest::~T100CmdLineTest()
{
    //dtor
}

T100BOOL T100CmdLineTest::do_init()
{
    m_argv[0] = const_cast<wchar_t*>(m_exec.c_str());
    m_argv[1] = const_cast<wchar_t*>(m_switch.c_str());
    m_argv[2] = const_cast<wchar_t*>(m_option.c_str());
    m_argv[3] = const_cast<wchar_t*>(m_value.c_str());
    m_argv[4] = const_cast<wchar_t*>(m_source.c_str());
    m_argv[5] = const_cast<wchar_t*>(m_target.c_str());

    argc    = 6;
    argv    = m_argv;

    return T100TRUE;
}

T100BOOL T100CmdLineTest::do_uninit()
{
    return T100TRUE;
}

T100BOOL T100CmdLineTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    if(!do_init()){
        result = T100FALSE;
    }

    if(result){
        value = test_string();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_char();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_parameter();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test_cmdline();
        if(!value){
            result = T100FALSE;
        }
    }

    if(!do_uninit()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CmdLineTest::test_string()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;


    T100CmdLineStringScanner        scanner;
    T100CmdLineStringToken          token;

    scanner.setSource(argc, argv);

    value = scanner.next(token);
    if((!value) || (T100CMDLINE_TOKEN_EXEC != token.type)){
        result = T100FALSE;
    }

    if(result){
        value = scanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_STRING != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_STRING != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_STRING != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_STRING != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_STRING != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = scanner.next(token);
        if((value) || (T100CMDLINE_TOKEN_EOF != token.type)){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100CmdLineTest::test_char()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;


    T100CmdLineStringScanner        strscanner;
    T100CmdLineCharScanner          chscanner;
    T100CmdLineCharToken            token;

    strscanner.setSource(argc, argv);
    chscanner.setSource(&strscanner);

    value = chscanner.next(token);
    if((!value) || (T100CMDLINE_TOKEN_EXEC != token.type)){
        result = T100FALSE;
    }

    ///
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_PROMPT != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_END != token.type)){
            result = T100FALSE;
        }
    }

    ///
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_PROMPT != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_END != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_END != token.type)){
            result = T100FALSE;
        }
    }

    ///
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_END != token.type)){
            result = T100FALSE;
        }
    }

    ///
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_CHAR != token.type)){
            result = T100FALSE;
        }
    }
    if(result){
        value = chscanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_END != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = chscanner.next(token);
        if((value) || (T100CMDLINE_TOKEN_EOF != token.type)){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100CmdLineTest::test_parameter()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    /*
    T100CmdLineStringScanner        strscanner;
    T100CmdLineCharScanner          chscanner;
    T100CmdLineParameterScanner     parascanner;
    T100CmdLineParameterToken       token;

    strscanner.setSource(argc, argv);
    chscanner.setSource(&strscanner);
    parascanner.setSource(&chscanner);

    value = parascanner.next(token);
    if((!value) || (T100CMDLINE_TOKEN_EXEC != token.type)){
        result = T100FALSE;
    }

    ///
    if(result){
        value = parascanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_SWITCH != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = parascanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_OPTION != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = parascanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_PARAM != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = parascanner.next(token);
        if((!value) || (T100CMDLINE_TOKEN_PARAM != token.type)){
            result = T100FALSE;
        }
    }

    if(result){
        value = parascanner.next(token);
        if((value) || (T100CMDLINE_TOKEN_EOF != token.type)){
            result = T100FALSE;
        }
    }
    */

    return result;
}

T100BOOL T100CmdLineTest::test_cmdline()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_CMDLINE_TEST_START);

    /*
    T100CmdLineParser       cmdline;
    T100CmdLineExec         exec;

    //-t -l lib.a source.txt target.bin

    value = cmdline.parse(argc, argv);

    if(value){

    }else{
        result = T100FALSE;
    }

    if(result){
        value = cmdline.findExec(exec);
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        T100WSTRING         source;
        T100WSTRING         target;

        target = argv[0];

        if(exec.value == target){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        T100CmdLineSwitch           target;

        value = cmdline.findSwitch(L"t", target);
        if(value){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        T100CmdLineOption           target;
        T100WSTRING                 source;

        value = cmdline.findOption(L"l", target);
        if(value){
            source = L"lib.a";

            if(source == target.value){

            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    if(result){
        T100CmdLineParam            target;
        T100WSTRING                 source;

        value = cmdline.findParam(target);
        if(value){
            source = L"source.txt";

            if(source == target.value){

            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }

    if(result){
        T100CmdLineParam            target;
        T100WSTRING                 source;

        value = cmdline.findParam(target);
        if(value){
            source = L"target.bin";

            if(source == target.value){

            }else{
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }
    */
    show_result(result, T100TEST_HINT_LIB_CMDLINE_TEST_STOP);
    return result;
}
