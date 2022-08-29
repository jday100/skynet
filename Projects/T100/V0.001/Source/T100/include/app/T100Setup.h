#ifndef T100SETUP_H
#define T100SETUP_H

#include "T100Common.h"

static T100STDSTRING        T100APP_LOG_PATH                            =   "logs";
static T100STDSTRING        T100APP_LOG_FILE                            =   "app.log";

static T100STDSTRING        T100APP_BUILD_PATH                          =   "build";

static T100STDSTRING        T100APP_RESOURCE_PATH                       =   "resources";

static T100STDSTRING        T100APP_SCRIPT_PATH                         =   "scripts";

static T100STDSTRING        T100APP_STORE_PATH                          =   "stores";

static T100STDSTRING        T100APP_TEST_PATH                           =   "test";


class T100Setup
{
    public:
        T100Setup();
        virtual ~T100Setup();

        static T100BOOL             LOG;
        static T100BOOL             DEBUG;

        static T100VOID             setLogFile(T100STDSTRING);
        static T100STDSTRING        getLogFile();

    protected:

    private:
        static T100STDSTRING        log_file;
};

#endif // T100SETUP_H
