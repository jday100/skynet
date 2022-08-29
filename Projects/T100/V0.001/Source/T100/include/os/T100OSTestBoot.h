#ifndef T100OSTESTBOOT_H
#define T100OSTESTBOOT_H

#include "T100Test.h"
class T100App;


class T100OSTestBoot : public T100Test
{
    public:
        T100OSTestBoot(T100App*);
        virtual ~T100OSTestBoot();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    init();

        T100BOOL                    test_boot();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app           = T100NULL;
};

#endif // T100OSTESTBOOT_H
