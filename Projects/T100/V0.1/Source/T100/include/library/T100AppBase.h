#ifndef T100APPBASE_H
#define T100APPBASE_H

#include <mutex>
#include <atomic>
#include <condition_variable>
#include "T100DataStructure.h"
#include "T100Class.h"


namespace T100Library{
class T100AppManager;
class T100AppThread;


class T100AppBase : public T100Class
{
    public:
        T100AppBase(T100AppManager*, T100BOOL = T100FALSE);
        virtual ~T100AppBase();

        static T100VOID                 getCmdLine(int&, wchar_t**&);

        virtual T100VOID                quit();

        virtual T100VOID                wait();

    protected:
        virtual T100VOID                create();
        virtual T100VOID                destroy();

        T100BOOL                        m_quit              = T100FALSE;

        T100VOID                        open();
        T100VOID                        close();

    private:
        std::mutex                      m_mutex;
        T100AppManager*                 m_manager           = T100NULL;
        T100AppThread*                  m_thread            = T100NULL;

};

}

#endif // T100APPBASE_H
