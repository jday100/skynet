#ifndef T100APP_H
#define T100APP_H

#include <atomic>
#include "T100Common.h"


#define         T100APP_VECTOR          std::vector<T100App*>


class T100App
{
    public:
        T100App();
        virtual ~T100App();

        static T100VOID             getCmdLine(int&, wchar_t**&);

        static T100VOID             quit();

        static T100VOID             wait();

    protected:
        static T100APP_VECTOR       m_apps;
        static std::atomic_int      m_count;

        virtual T100VOID            create();
        virtual T100VOID            destroy();

        T100VOID                    open();
        T100VOID                    close();

    private:

};

#endif // T100APP_H
