#ifndef T100APPMANAGER_H
#define T100APPMANAGER_H

#include <mutex>
#include <atomic>
#include "T100Class.h"
#include "T100SafeVector.h"
#include "T100AppBase.h"

#define         T100APP_SAFE_VECTOR         T100SafeVector<T100AppBase*>

namespace T100Library{

class T100AppManager : public T100Class
{
    friend class T100AppBase;
    public:
        T100AppManager();
        virtual ~T100AppManager();

        virtual T100BOOL            start();

        virtual T100BOOL            stop();

        virtual T100BOOL            quit(T100WORD = 0);

    protected:
        virtual T100VOID            create();
        virtual T100VOID            destroy();

        virtual T100VOID            open();
        virtual T100VOID            close();

    private:
        std::mutex                  m_mutex;
        std::atomic_int             m_count;
        std::atomic_bool            m_running;
        T100APP_SAFE_VECTOR         m_apps;

};

}

#endif // T100APPMANAGER_H
