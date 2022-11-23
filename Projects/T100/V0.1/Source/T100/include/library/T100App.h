#ifndef T100APP_H
#define T100APP_H

#include <mutex>
#include <atomic>
#include <condition_variable>
#include "T100DataStructure.h"
#include "T100Class.h"

#define         T100APP_VECTOR                  std::vector<T100App*>

namespace T100Library{
class T100AppManager;
class T100AppThread;

class T100App : public T100Class
{
    public:
        T100App(T100AppManager*);
        virtual ~T100App();

        static T100VOID                 getCmdLine(int&, wchar_t**&);

        virtual T100VOID                quit();

        virtual T100VOID                wait();

    protected:
        static T100APP_VECTOR           m_apps;
        static std::atomic_int          m_count;

        virtual T100VOID                create();
        virtual T100VOID                destroy();

        T100VOID                        open();
        T100VOID                        close();

    private:
        std::mutex                      m_mutex;
        std::condition_variable         m_condition;
        T100AppManager*                 m_manager           = T100NULL;
        T100AppThread*                  m_thread            = T100NULL;

};

}

#endif // T100APP_H
