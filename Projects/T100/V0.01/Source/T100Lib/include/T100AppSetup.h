#ifndef T100APPSETUP_H
#define T100APPSETUP_H

#include "T100Setup.h"


class T100AppSetup : public T100Setup
{
    public:
        T100AppSetup();
        virtual ~T100AppSetup();

        static T100WSTRING              getTestResources(T100WSTRING);
        static T100WSTRING              getTestBuild(T100WSTRING);
        static T100WSTRING              getTestStores(T100WSTRING);
        static T100WSTRING              getWork(T100WSTRING);
        static T100WSTRING              getLog(T100WSTRING);

        static T100WSTRING              APP_TEST_PATH;

    protected:

    private:
        static T100WSTRING              m_resources;
        static T100WSTRING              m_build;
        static T100WSTRING              m_stores;
        static T100WSTRING              m_work;
        static T100WSTRING              m_log;


};

#endif // T100APPSETUP_H
