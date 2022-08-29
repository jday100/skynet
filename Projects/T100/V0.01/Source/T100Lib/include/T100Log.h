#ifndef T100LOG_H
#define T100LOG_H

#include <atomic>
#include "T100LogCommon.h"


class T100Log
{
    public:
        T100Log();
        virtual ~T100Log();

        static T100BOOL                         start();
        static T100BOOL                         stop();

        static T100BOOL                         running();

        static T100BOOL                         append(T100LogAppender*);
        static T100BOOL                         erase(T100LogAppender*);

        static T100VOID                         fatal(T100WSTRING);
        static T100VOID                         error(T100WSTRING);
        static T100VOID                         warn(T100WSTRING);
        static T100VOID                         debug(T100WSTRING);
        static T100VOID                         trace(T100WSTRING);
        static T100VOID                         info(T100WSTRING);

    protected:
        T100VOID                                create();
        T100VOID                                destroy();

        static T100LOG_APPENDER_VECTOR          m_appenders;

    private:
        static std::atomic_bool                 m_running;
        static T100LOG_TYPE                     m_type;

        static T100VOID                         outline(T100LOG_TYPE, T100WSTRING);

};

#endif // T100LOG_H
