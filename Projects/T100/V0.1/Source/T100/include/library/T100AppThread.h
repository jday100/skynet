#ifndef T100APPTHREAD_H
#define T100APPTHREAD_H

#include <mutex>
#include <condition_variable>
#include "T100Thread.h"

namespace T100Library{

class T100AppThread : public T100Thread
{
    public:
        T100AppThread();
        virtual ~T100AppThread();

        T100VOID                    resume();

    protected:
        T100VOID                    run();

    private:
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

};

}

#endif // T100APPTHREAD_H
