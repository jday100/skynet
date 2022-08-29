#include "T100TestLib.h"

#include "T100Log.h"
#include "T100Clock.h"
#include "T100File.h"
#include "T100HintTest.h"
#include "T100TestString.h"

T100STDSTRING       T100TestLib::m_unit     = "lib";


T100TestLib::T100TestLib()
    :T100Test(m_unit)
{
    //ctor
}

T100TestLib::~T100TestLib()
{
    //dtor
}

T100VOID T100TestLib::load()
{

}

T100BOOL T100TestLib::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_thread.test_all()){
        result = T100FALSE;
    }

    if(!test_clock()){
        result = T100FALSE;
    }

    if(!test_string()){
        result = T100FALSE;
    }

    if(!test_unicode()){
        result = T100FALSE;
    }

    if(!test_string_tools()){
        result = T100FALSE;
    }

    if(!test_winconsole()){
        result = T100FALSE;
    }

    if(!test_path()){
        result = T100FALSE;
    }

    if(!test_file()){
        result = T100FALSE;
    }

    if(!test_file_tools()){
        result = T100FALSE;
    }

    if(!test_console()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestLib::test_clock()
{
    T100BOOL    result      = T100TRUE;
    T100Clock   clock;
    T100WORD    current;

    current = clock.second();

    if(0 == current){
        result = T100FALSE;
    }

    current = clock.millisecond();

    if(0 == current){
        result = T100FALSE;
    }

    current = clock.microsecond();

    if(0 == current){
        result = T100FALSE;
    }

    current = clock.nanosecond();

    if(0 == current){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestLib::test_console()
{
    T100BOOL    result      = T100TRUE;

    return result;
}

T100BOOL T100TestLib::test_file()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;

    T100File        test(T100String("test\\temp\\test.bin"));

    T100Log::info(T100TEST_LIB_FILE_TEST_START);

    if(test.exists()){
        value = test.remove();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test.exists();
        if(value){
            result = T100FALSE;
        }
    }

    if(result){
        value = test.create();
        if(!value){
            result = T100FALSE;
        }
    }

    if(result){
        if(!test.exists()){
            result = T100FALSE;
        }
    }

    if(result){
        if(0 != test.length()){
            result = T100FALSE;
        }
    }

    T100WORD    source[1024];
    T100WORD    target[1024];
    T100WORD    length;
    T100WORD*   data            = T100NULL;

    data    = source;
    length  = 1024;

    if(test.open(T100FILE_READWRITE)){
        if(test.opened()){
            for(int i=0;i<1024;i++){
                source[i] = i;
            }
            if(test.write(data, length)){
                if(1024 == length){
                    data = target;
                    if(test.seek(0)){
                        if(test.read(data, length)){
                            if(1024 == length){
                                for(int i=0;i<1024;i++){
                                    if(source[i] == target[i]){

                                    }else{
                                        result = T100FALSE;
                                        break;
                                    }
                                }
                            }else{
                                result = T100FALSE;
                            }
                        }else{
                            result = T100FALSE;
                        }
                    }else{
                        result = T100FALSE;
                    }
                }else{
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }
            if(!test.close()){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    if(result){
        T100DWORD   l;

        l = test.length();
        if(1024 != l){
            result = T100FALSE;
        }
    }

    T100Log::info(T100TEST_LIB_FILE_TEST_STOP);

    return result;
}

T100BOOL T100TestLib::test_file_tools()
{
    T100BOOL    result      = T100TRUE;

    return result;
}

T100BOOL T100TestLib::test_path()
{
    T100BOOL    result      = T100TRUE;

    return result;
}

T100BOOL T100TestLib::test_string()
{
    T100BOOL    result      = T100TRUE;
    T100TestString          test;

    if(!test.test_all()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100TestLib::test_string_tools()
{
    T100BOOL    result      = T100TRUE;

    return result;
}

T100BOOL T100TestLib::test_unicode()
{
    T100BOOL    result      = T100TRUE;

    return result;
}

T100BOOL T100TestLib::test_winconsole()
{
    T100BOOL    result      = T100TRUE;

    return result;
}


