#include "T100TestLog.h"

#include "T100Log.h"
#include "T100LogAppenderConsole.h"
#include "T100LogAppenderFile.h"

T100STDSTRING       T100TestLog::m_unit     = "log";


T100TestLog::T100TestLog()
    :T100Test(m_unit)
{
    //ctor
}

T100TestLog::~T100TestLog()
{
    //dtor
}

T100VOID T100TestLog::load()
{

}

T100BOOL T100TestLog::test_all()
{
    T100BOOL    result      = T100TRUE;

    result = test_log();

    return result;
}

T100BOOL T100TestLog::test_log()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log                     log;
    T100LogAppenderConsole      console;

    value = log.remove(&console);
    if(value){
        return T100FALSE;
    }

    value = log.add(&console);
    if(value){
        value = log.add(&console);
        if(value){
            result = T100FALSE;
        }else{
            //test
            log.stop();
            value = log.start();
            if(value){
                log.fatal("FATAL");
                log.error("ERROR");
                log.warn("WARN");
                log.debug("DEBUG");
                log.trace("TRACE");
                log.info("INFO");

                value = log.stop();
                if(value){

                }else{
                    result = T100FALSE;
                }
            }else{
                result = T100FALSE;
            }

            value = log.remove(&console);
            if(value){

            }else{
                result = T100FALSE;
            }
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
