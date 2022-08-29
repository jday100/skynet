#ifndef T100TESTSYSTEM_H
#define T100TESTSYSTEM_H

#include "T100Test.h"


class T100TestSystem : public T100Test
{
    public:
        T100TestSystem();
        virtual ~T100TestSystem();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_font();
        T100BOOL                    test_font_file();
        T100BOOL                    test_vdisk();
        T100BOOL                    test_vdisk_file();
        T100BOOL                    test_vfs();
        T100BOOL                    test_vfs_item();
        T100BOOL                    test_vfs_table();
        T100BOOL                    test_vfs_path();
        T100BOOL                    test_vfs_file();

    private:
        static T100STDSTRING        m_unit;

        T100BOOL                    test_font_file_read();
};

#endif // T100TESTSYSTEM_H
