#include "T100Master.h"

#include "T100TestTools.h"
#include "T100Main.h"


T100Master::T100Master()
{
    //ctor
}

T100Master::~T100Master()
{
    //dtor
}

T100VOID T100Master::setMain(T100Main* value)
{
    m_main = value;
}

T100VOID T100Master::run()
{
    while(1){
        T100TestTools::Print(L"Master");

        if(m_main->m_flag){
            T100TestTools::Print(L"true");
        }else{
            T100TestTools::Print(L"false");
        }
        m_main->m_flag = false;
        sleep(1000);
    }
}
