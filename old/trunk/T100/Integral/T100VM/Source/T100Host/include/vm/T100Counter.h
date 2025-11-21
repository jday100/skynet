#ifndef T100COUNTER_H
#define T100COUNTER_H

#include <atomic>

class T100Host;

class T100Counter
{
    public:
        T100Counter(T100Host*);
        virtual ~T100Counter();

        void                Pulse();

    protected:
        std::atomic_uint    m_count;
        T100Host*           m_host      = nullptr;

    private:
};

#endif // T100COUNTER_H
