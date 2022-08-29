#ifndef T100OSTESTFS_H
#define T100OSTESTFS_H

#include "T100Test.h"
class T100App;

class T100OSTestFS : public T100Test
{
    public:
        T100OSTestFS(T100App*);
        virtual ~T100OSTestFS();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_fs();


    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;
};

#endif // T100OSTESTFS_H
