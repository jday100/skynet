#include "T100MenuExtension.h"

#include "gui/event/T100MenuEvent.h"
#include "T100ProjectInvoking.h"

using namespace T100WINDOWS;

T100MenuExtension::T100MenuExtension() :
    T100Extension()
{
    //ctor
}

T100MenuExtension::~T100MenuExtension()
{
    //dtor
}

T100VOID T100MenuExtension::SendEvent(...)
{
    va_list args;
    va_start(args, 1);

    T100MenuEvent*  event   = va_arg(args, T100MenuEvent*);

    va_end(args);

    if(event){
        for(auto& [_, v] : m_events){
            if(v.HANDLER && v.FUNCTION){
                (v.HANDLER->*(v.FUNCTION))(*event);
            }
        }
    }
}

T100VOID T100MenuExtension::FindEvent(T100MenuEvent& event)
{
    T100UINT            id;

    id  = event.GetID();

    T100WSTRING         label;

    label   = m_menus[id];

    if(!label.empty()){
        T100ProjectInvoking::CallMenu(label, &event);
    }
}

T100VOID T100MenuExtension::ConnectMenu(T100UINT id, T100EventHandler* handler, T100EVENT_FUNCTION call, T100EventHandler* data)
{
    T100EVENT_FUNCTION_DATA         item;

    item.FUNCTION       = call;

    if(data){
        item.HANDLER    = data;
    }else{
        item.HANDLER    = handler;
    }

    m_events[id]    = item;
}

T100VOID T100MenuExtension::Append(T100UINT type, const T100WSTRING& label)
{
    m_menus[type]   = label;
}
