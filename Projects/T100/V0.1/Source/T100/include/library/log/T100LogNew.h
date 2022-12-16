#ifndef T100LOGNEW_H
#define T100LOGNEW_H

#include <mutex>
#include <atomic>
#include "T100Class.h"
#include "T100LogCommon.h"

namespace T100Library{

class T100LogNew : public T100Class
{
    public:
        T100LogNew();
        virtual ~T100LogNew();

        T100BOOL                        start();
        T100BOOL                        stop();

        T100BOOL                        running();

        T100BOOL                        append(T100LogBase*);
        T100BOOL                        remove(T100LogBase*);

    public:
        T100VOID                        fatal(T100WSTRING);
        T100VOID                        error(T100WSTRING);
        T100VOID                        warn(T100WSTRING);
        T100VOID                        debug(T100WSTRING);
        T100VOID                        trace(T100WSTRING);
        T100VOID                        info(T100WSTRING);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

        T100LOG_SAFE_VECTOR             m_logs;

    private:
        std::atomic_bool                m_running;
        std::mutex                      m_mutex;
        T100LOG_TYPE                    m_type;

        T100VOID                        outline(T100LOG_TYPE, T100WSTRING);

};

}

#endif // T100LOGNEW_H
