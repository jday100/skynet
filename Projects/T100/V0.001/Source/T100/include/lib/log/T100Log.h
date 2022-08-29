#ifndef T100LOG_H
#define T100LOG_H

#include "T100LogCommon.h"
#include "T100WinConsole.h"
#include "T100LogHint.h"


class T100Log
{
    public:
        T100Log();
        virtual ~T100Log();

        static T100BOOL                     start();
        static T100BOOL                     stop();

        static T100BOOL                     add(T100LogAppender*);
        static T100BOOL                     remove(T100LogAppender*);

        static T100VOID                     fatal(T100STDSTRING);
        static T100VOID                     error(T100STDSTRING);
        static T100VOID                     warn(T100STDSTRING);
        static T100VOID                     debug(T100STDSTRING);
        static T100VOID                     trace(T100STDSTRING);
        static T100VOID                     info(T100STDSTRING);

        static T100VOID                     out(T100STDSTRING);

        static T100VOID                     setColour(T100COLOUR_TYPE);

        static T100LOG_TYPE                 m_type;

        static T100BOOL                     running();

    protected:
        static T100LOG_APPENDER_VECTOR      m_appenders;
        static T100LOG_QUEUE                m_queue;
        static T100LOG_CALLBACK_VECTOR      m_callbacks;
        static T100BOOL                     m_running;

    private:
        static T100VOID                     out(T100LOG_TYPE, T100STDSTRING);
};

#endif // T100LOG_H
