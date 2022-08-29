#include "T100Test.h"

#include "T100Log.h"


T100TEST_UNIT_HASH T100Test::m_units;

T100Test::T100Test(T100STDSTRING unit)
    :m_unit(unit)
{
    //ctor
    create();
}

T100Test::~T100Test()
{
    //dtor
    destroy();
}

T100VOID T100Test::create()
{
    T100TEST_UNIT_HASH::iterator it;

    it = m_units.find(m_unit);

    if(m_units.end() == it){
        m_units[m_unit] = this;
    }else{

    }

    load();
}

T100VOID T100Test::destroy()
{

}

T100VOID T100Test::load()
{

}

T100VOID T100Test::unload()
{

}

T100BOOL T100Test::list()
{
    for(auto it : m_units){
        T100Log::info(it.first);
    }
    return T100TRUE;
}

T100BOOL T100Test::test_unit(T100STDSTRING name)
{
    T100BOOL    result      = T100TRUE;
    T100TEST_UNIT_HASH::iterator it;

    if("all" == name){
        return test_all();
    }

    it = m_units.find(name);

    if(m_units.end() == it){
        result = T100FALSE;
    }else{
        T100Test* test = T100NULL;

        test = it->second;

        if(test){
            result = test->test_all();
        }else{
            result = T100FALSE;
        }

    }
    return result;
}

T100VOID T100Test::show_result(T100BOOL result, T100STDSTRING msg)
{
    if(result){

    }else{

    }
}
