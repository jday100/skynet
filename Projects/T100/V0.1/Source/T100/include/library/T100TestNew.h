#ifndef T100TESTNEW_H
#define T100TESTNEW_H

#include <atomic>
#include "T100Class.h"
#include "T100Vessel.h"
#include "T100LogNew.h"
#include "T100Console.h"


namespace T100Library{

class T100TestNew : public T100Class
{
    public:
        T100TestNew(T100TestNew* parent = T100NULL, T100WSTRING name = L"all");
        virtual ~T100TestNew();

        int                         argc;
        wchar_t**                   argv;

        T100VOID                    setGlobalInit(T100BOOL);
        T100VOID                    setGlobalUninit(T100BOOL);

        T100VOID                    setInit(T100BOOL);
        T100VOID                    setUninit(T100BOOL);

        virtual T100BOOL            test_all();
        virtual T100BOOL            test_unit(T100WSTRING);

        virtual T100VOID            list();
        virtual T100BOOL            find(T100WSTRING);

        virtual T100VOID            show_result(T100BOOL, T100WSTRING&);

    protected:
        virtual T100BOOL            do_init();
        virtual T100BOOL            do_uninit();

        virtual T100BOOL            init();
        virtual T100BOOL            uninit();

        virtual T100BOOL            do_global_init();
        virtual T100BOOL            do_global_uninit();

        virtual T100BOOL            global_init();
        virtual T100BOOL            global_uninit();

        virtual T100VOID            index();
        virtual T100VOID            success();
        virtual T100VOID            failure();

    protected:
        virtual T100VOID            create();
        virtual T100VOID            destroy();

        virtual T100Console*        getConsole();

        virtual T100VOID            add();

        virtual T100BOOL            do_test();

        virtual T100VOID            out(T100WSTRING);
        virtual T100VOID            out_test_begin(T100WSTRING&);
        virtual T100VOID            out_test_end(T100BOOL, T100WSTRING&);
        virtual T100VOID            out_list(T100WSTRING&);
        virtual T100VOID            out_list_begin();
        virtual T100VOID            out_list_end();

        virtual T100VOID            insert(T100WSTRING, T100TestNew*);
        virtual T100VOID            append(T100WSTRING, T100TestNew*);
        virtual T100VOID            remove(T100WSTRING);

    private:
        std::atomic_bool            m_global_inited;
        std::atomic_bool            m_global_uninited;

        std::atomic_bool            m_unit_inited;
        std::atomic_bool            m_unit_uninited;

        std::atomic_bool            m_need_global_init;
        std::atomic_bool            m_need_global_uninit;

        std::atomic_bool            m_need_unit_init;
        std::atomic_bool            m_need_unit_uninit;

        T100TestNew*                m_parent            = T100NULL;
        T100WSTRING                 m_name;

        T100Console*                m_console           = T100NULL;
        T100WORD                    m_units             = 0;
        T100WORD                    m_index             = 0;
        T100WORD                    m_success           = 0;
        T100WORD                    m_failure           = 0;

        T100Vessel<T100WSTRING, T100TestNew*>           m_tests;

};

}

#endif // T100TESTNEW_H
