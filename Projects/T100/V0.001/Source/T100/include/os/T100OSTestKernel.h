#ifndef T100OSTESTKERNEL_H
#define T100OSTESTKERNEL_H

#include "T100Test.h"
class T100App;


class T100OSTestKernel : public T100Test
{
    public:
        T100OSTestKernel(T100App*);
        virtual ~T100OSTestKernel();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    init();

        T100BOOL                    test_kernel();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app           = T100NULL;
};

#endif // T100OSTESTKERNEL_H
