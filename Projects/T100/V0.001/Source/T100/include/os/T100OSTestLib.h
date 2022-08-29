#ifndef T100OSTESTLIB_H
#define T100OSTESTLIB_H

#include "T100Test.h"
class T100App;

class T100OSTestLib : public T100Test
{
    public:
        T100OSTestLib(T100App*);
        virtual ~T100OSTestLib();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_string();
        T100BOOL                    test_disk();
        T100BOOL                    test_part();

        T100BOOL                    test_word();
        T100BOOL                    test_dword();


    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;
};

#endif // T100OSTESTLIB_H
