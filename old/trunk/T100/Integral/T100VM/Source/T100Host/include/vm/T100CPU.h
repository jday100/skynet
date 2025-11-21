#ifndef T100CPU_H
#define T100CPU_H

#include <atomic>

class T100Host;

class T100CPU
{
    public:
        T100CPU(T100Host*);
        virtual ~T100CPU();

        void                    Pulse();

    protected:
        std::atomic_bool        m_flag;
        std::atomic_bool        m_ready;
        std::atomic_bool        m_request;
        std::atomic_uint        m_count;
        T100Host*               m_host      = nullptr;

    private:
};

#endif // T100CPU_H
