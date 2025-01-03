#ifndef T100TEST_H
#define T100TEST_H

#include <atomic>
#include "vessel/T100Vessel.h"
#include "console/T100Console.h"

#define     T100TEST_UNIT_HASH          std::unordered_map<T100WString, T100Test*>

class T100Test
{
    public:
        T100Test(T100Test* parent = T100NULL, T100WString name = "");
        virtual ~T100Test();

        virtual T100BOOL                test_all();

    protected:
        virtual T100BOOL                do_test();

        virtual T100VOID                out(T100WString);
        virtual T100VOID                out_test_begin(T100WString&);
        virtual T100VOID                out_test_end(T100WString&, T100BOOL);
        virtual T100VOID                out_list(T100WString&);
        virtual T100VOID                out_list_element(T100WString&);
        virtual T100VOID                out_list_begin();
        virtual T100VOID                out_list_end();

    private:
        virtual T100VOID                create();
        virtual T100VOID                destroy();

        std::atomic_bool                m_need_init;
        std::atomic_bool                m_inited;
        std::atomic_bool                m_need_uninit;
        std::atomic_bool                m_uninited;

        T100Test*                       m_parent            = T100NULL;
        T100WString                     m_name;

        static T100Console*             m_console;

        static T100WORD                 m_index;
        static T100WORD                 m_success;
        static T100WORD                 m_failure;

        static T100TEST_UNIT_HASH       m_units_hash;

        T100Vessel<T100WString, T100Test*>          m_tests;
};

#endif // T100TEST_H
