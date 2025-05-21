#ifndef T100LOGGER_H
#define T100LOGGER_H

#include <atomic>
#include "base/T100Class.h"
#include "common/T100LogCommon.h"

class T100Logger : public T100Class
{
    public:
        T100Logger();
        virtual ~T100Logger();

        static T100VOID                 Start();
        static T100VOID                 Stop();

        static T100BOOL                 IsRunning();

        static T100BOOL                 Append(T100LogBase*);
        static T100BOOL                 Remove(T100LogBase*);

        static T100VOID                 Fatal(T100WSTRING);
        static T100VOID                 Error(T100WSTRING);
        static T100VOID                 Warn(T100WSTRING);
        static T100VOID                 Debug(T100WSTRING);
        static T100VOID                 Trace(T100WSTRING);
        static T100VOID                 Info(T100WSTRING);

    protected:
        T100VOID                        init();
        T100VOID                        uninit();

        static T100LOG_VECTOR           m_logs;

    private:
        static std::atomic_bool         m_running;
        static T100LOG_TYPE             m_logType;

        static T100VOID                 OutLine(T100LOG_TYPE, T100WSTRING);
};

#endif // T100LOGGER_H
