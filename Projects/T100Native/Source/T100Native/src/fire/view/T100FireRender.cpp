#include "T100FireRender.h"

BEGIN_EVENT_TABLE(T100FireRender,T100WxRender)
    EVT_KEY_DOWN(T100FireRender::OnKeyDown)
    EVT_CHAR(T100FireRender::OnChar)
END_EVENT_TABLE()

T100FireRender::T100FireRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :T100WxRender(parent, id, pos, size, style, name)
{
    //ctor
}

T100FireRender::~T100FireRender()
{
    //dtor
}

T100VOID T100FireRender::OnKeyDown(wxKeyEvent& event)
{
    T100INT         key;

    key     = event.GetKeyCode();

    switch(key){
    case WXK_UP:
        {

        }
        break;
    case WXK_DOWN:
        {
            m_render->Move(10, 10, 10);
        }
        break;
    }

    Refresh();
}

T100VOID T100FireRender::OnChar(wxKeyEvent& event)
{

}
