#ifndef T100TEST_H
#define T100TEST_H

#include <atomic>
#include "T100Class.h"
#include "T100Vessel.h"
#include "T100Log.h"
#include "T100Console.h"

#define     T100TEST_UNIT_HASH      std::unordered_map<T100WSTRING, T100Test*>

namespace T100Library{
class T100Test;

typedef     T100BOOL(*T100TEST_CALL)(T100Test*);

class T100Test : public T100Class
{
    public:
        T100Test(T100Test* parent = T100NULL, T100WSTRING name = L"");
        virtual ~T100Test();

        static int                  argc;
        static wchar_t**            argv;

        virtual T100BOOL            test_all();
        virtual T100BOOL            test_unit(T100WSTRING);

        virtual T100VOID            list();

        virtual T100BOOL            find();

        virtual T100VOID            show_result(T100BOOL, T100WSTRING&);

    protected:
        virtual T100VOID            create();
        virtual T100VOID            destroy();

        virtual T100VOID            add();

        virtual T100BOOL            do_init();
        virtual T100BOOL            do_uninit();

        virtual T100BOOL            init();
        virtual T100BOOL            uninit();

        virtual T100BOOL            do_test();

        virtual T100VOID            out(T100WSTRING);
        virtual T100VOID            out_test_begin(T100WSTRING&);
        virtual T100VOID            out_test_end(T100WSTRING&, T100BOOL);
        virtual T100VOID            out_list(T100WSTRING&);
        virtual T100VOID            out_list_element(T100WSTRING&);
        virtual T100VOID            out_list_begin();
        virtual T100VOID            out_list_end();

        virtual T100VOID            append(T100WSTRING, T100Test*);
        virtual T100VOID            remove(T100WSTRING, T100Test*);

    private:
        std::atomic_bool            m_need_init;
        std::atomic_bool            m_inited;
        std::atomic_bool            m_need_uninit;
        std::atomic_bool            m_uninited;

        T100Test*                   m_parent            = T100NULL;
        T100WSTRING                 m_name;

        static T100Console*         m_console;
        static T100WORD             m_units;
        static T100WORD             m_elements;
        static T100WORD             m_index;
        static T100WORD             m_success;
        static T100WORD             m_failure;

        static T100TEST_UNIT_HASH   m_unit_hash;

        T100Vessel<T100WSTRING, T100Test*>          m_tests;
        T100Vessel<T100WSTRING, T100TEST_CALL>      m_test_call;

};

}

#endif // T100TEST_H
