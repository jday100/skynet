#ifndef T100THREAD_H
#define T100THREAD_H

#include <thread>
#include <functional>


class T100Thread
{
    public:
        T100Thread();
        virtual ~T100Thread();

        void                start();
        void                stop();

        void                sleep(int);

    protected:

        void                run();

        std::function<void()>       m_method;

    private:
        std::thread*        m_thread            = nullptr;
};

#endif // T100THREAD_H
