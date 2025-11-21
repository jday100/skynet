#ifndef T100MEMORY_H
#define T100MEMORY_H

#include <mutex>
#include <atomic>
#include <condition_variable>

class T100Host;

class T100Memory
{
    public:
        T100Memory(T100Host*);
        virtual ~T100Memory();

        void                        Read();

        void                        Request();
        bool                        Ready();

        void                        Pulse();

    protected:
        std::atomic_bool            m_flag;
        std::atomic_bool            m_ready;
        std::atomic_uint            m_count;
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

        T100Host*                   m_host      = nullptr;

    private:
};

#endif // T100MEMORY_H
