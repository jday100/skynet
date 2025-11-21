#include "T100WindowExtension.h"

#include "gui/event/T100WindowEvent.h"

T100WindowExtension::T100WindowExtension() :
    T100Extension()
{
    //ctor
}

T100WindowExtension::~T100WindowExtension()
{
    //dtor
}

T100VOID T100WindowExtension::SendEvent(...)
{
    va_list args;
    va_start(args, 1);

    T100WindowEvent*  event   = va_arg(args, T100WindowEvent*);

    va_end(args);

    if(event){
        for(auto& [_, v] : m_events){
            if(v.HANDLER && v.FUNCTION){
                (v.HANDLER->*(v.FUNCTION))(*event);
            }
        }

        if(m_data){
            void (*method)(T100WindowEvent&) = (void(*)(T100WindowEvent&))m_data;

            if(method){
                method(*event);
            }
        }
    }
}

T100VOID T100WindowExtension::Connect(T100VOID* data)
{
    m_data  = data;
}
