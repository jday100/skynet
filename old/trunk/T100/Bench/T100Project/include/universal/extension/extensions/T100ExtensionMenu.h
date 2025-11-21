#ifndef T100EXTENSIONMENU_H
#define T100EXTENSIONMENU_H

#include <wx/menu.h>
#include <wx/frame.h>
#include "T100Vessel.h"
#include "T100Extension.h"

typedef struct {
    wxEvtHandler*               Handler     = T100NULL;
    wxObjectEventFunction       Function;
}T100EventHandlerData;

typedef struct {
    T100Plugin*                         Plugin      = T100NULL;
    T100EXTENSION_EVENT_FUNCTION        Function;
}T100EXTENSION_EVENT_FUNCTION_DATA;

#define     T100EXTENSION_EVENT_FUNCTION_DATA_VESSEL            T100Vessel<T100UINT, T100EXTENSION_EVENT_FUNCTION_DATA*>

class T100ExtensionMenu : public T100Extension
{
    public:
        T100ExtensionMenu();
        virtual ~T100ExtensionMenu();

        T100VOID                    SetMenuBar(wxFrame*, wxMenuBar*);
        wxMenuBar*                  GetMenuBar();

        T100VOID                    SetHandler(wxEvtHandler*, wxObjectEventFunction);
        T100EventHandlerData&       GetHandler();

        T100VOID                    Update();

        T100VOID                    SignIn(T100UINT, T100Plugin*, T100EXTENSION_EVENT_FUNCTION);

        T100VOID                    SendEvent(wxCommandEvent&);

    protected:
        wxFrame*                    m_frame         = T100NULL;
        wxMenuBar*                  m_menuBar       = T100NULL;
        T100EventHandlerData        m_eventHandler;

        T100Plugin*                         m_plugin        = T100NULL;
        T100EXTENSION_EVENT_FUNCTION        m_function;

        T100EXTENSION_EVENT_FUNCTION_DATA_VESSEL            m_events;

    private:
};

#endif // T100EXTENSIONMENU_H
