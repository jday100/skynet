#ifndef T100LOG_H
#define T100LOG_H

#include <atomic>
#include "T100Class.h"
#include "T100LogCommon.h"

namespace T100Library{

class T100Log : public T100Class
{
    public:
        T100Log();
        virtual ~T100Log();

        static T100BOOL                     start();
        static T100BOOL                     stop();

        static T100BOOL                     running();

        static T100BOOL                     append(T100LogBase*);
        static T100BOOL                     remove(T100LogBase*);

        static T100VOID                     fatal(T100WSTRING);
        static T100VOID                     error(T100WSTRING);
        static T100VOID                     warn(T100WSTRING);
        static T100VOID                     debug(T100WSTRING);
        static T100VOID                     trace(T100WSTRING);
        static T100VOID                     info(T100WSTRING);

    protected:
        T100VOID                            create();
        T100VOID                            destroy();

        static T100LOG_VECTOR               m_logs;

    private:
        static std::atomic_bool             m_running;
        static T100LOG_TYPE                 m_type;


};

}

#endif // T100LOG_H
