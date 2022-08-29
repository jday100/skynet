#include "T100Setup.h"

T100BOOL            T100Setup::LOG          =   T100TRUE;
T100BOOL            T100Setup::DEBUG        =   T100FALSE;
T100STDSTRING       T100Setup::log_file     =   "";


T100Setup::T100Setup()
{
    //ctor
}

T100Setup::~T100Setup()
{
    //dtor
}

T100VOID T100Setup::setLogFile(T100STDSTRING str)
{
    log_file = str;
}

T100STDSTRING T100Setup::getLogFile()
{
    if(log_file.empty()){
        return T100APP_LOG_PATH + "\\" + T100APP_LOG_FILE;
    }
    return log_file;
}
