#include "T100EditorRender.h"

BEGIN_EVENT_TABLE(T100EditorRender,T100WxRender)
    EVT_KEY_DOWN(T100EditorRender::OnKeyDown)
    EVT_CHAR(T100EditorRender::OnChar)
    EVT_MOTION(T100EditorRender::OnMouseMove)
    EVT_LEFT_DOWN(T100EditorRender::OnLeftDown)
    EVT_LEFT_UP(T100EditorRender::OnLeftUp)
END_EVENT_TABLE()

T100EditorRender::T100EditorRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :T100WxRender(parent, id, pos, size, style, name)
{
    //ctor
}

T100EditorRender::~T100EditorRender()
{
    //dtor
}

T100VOID T100EditorRender::OnKeyDown(wxKeyEvent& event)
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

T100VOID T100EditorRender::OnChar(wxKeyEvent& event)
{

}

T100VOID T100EditorRender::OnMouseMove(wxMouseEvent& event)
{
    T100INT         x, y;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;
}

T100VOID T100EditorRender::OnLeftDown(wxMouseEvent& event)
{
    T100INT         x, y;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    m_begin_x   = x;
    m_begin_y   = y;
}

T100VOID T100EditorRender::OnLeftUp(wxMouseEvent& event)
{
    T100INT         x, y;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    m_end_x     = x;
    m_end_y     = y;
}
