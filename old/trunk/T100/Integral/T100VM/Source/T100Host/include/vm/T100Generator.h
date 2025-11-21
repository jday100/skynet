#ifndef T100GENERATOR_H
#define T100GENERATOR_H

#include <atomic>

class T100Host;

class T100Generator
{
    public:
        T100Generator(T100Host*);
        virtual ~T100Generator();

        void                    Start();
        void                    Stop();

    protected:
        std::atomic_bool        m_running;
        T100Host*               m_host      = nullptr;

    private:
};

#endif // T100GENERATOR_H
