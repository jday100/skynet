#include "view/panels/T1003DEditorMainPanel.h"

//#include "T100Debug.h"
#include "skeletal/T1003DEditorCallback.h"

BEGIN_EVENT_TABLE(T1003DEditorMainPanel,wxPanel)
    EVT_ENTER_WINDOW(T1003DEditorMainPanel::OnEnterWindow)
    EVT_LEAVE_WINDOW(T1003DEditorMainPanel::OnLeaveWindow)
    EVT_KEY_DOWN(T1003DEditorMainPanel::OnKeyDown)
    EVT_KEY_UP(T1003DEditorMainPanel::OnKeyUp)
    EVT_LEFT_DOWN(T1003DEditorMainPanel::OnMouseLeftDown)
    EVT_RIGHT_DOWN(T1003DEditorMainPanel::OnMouseRightDown)
    EVT_MOTION(T1003DEditorMainPanel::OnMouseMove)
END_EVENT_TABLE()

T1003DEditorMainPanel::T1003DEditorMainPanel(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name) :
    wxPanel(parent, winid, pos, size, style, name)
{
    //ctor
    init();
}

T1003DEditorMainPanel::~T1003DEditorMainPanel()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorMainPanel::init()
{
    m_ctrlKey       = T100FALSE;
    m_appendState   = T100FALSE;
    SetFocus();
}

T100VOID T1003DEditorMainPanel::uninit()
{

}

T100UINT T1003DEditorMainPanel::GetWidth()
{
    return GetSize().GetWidth();
}

T100UINT T1003DEditorMainPanel::GetHeight()
{
    return GetSize().GetHeight();
}

T100VOID T1003DEditorMainPanel::SetAppendState(T100BOOL value)
{
    m_appendState   = value;
}

T100VOID T1003DEditorMainPanel::OnEnterWindow(wxMouseEvent& event)
{
    if(m_appendState){
        SetCursor(wxCURSOR_HAND);
        SetFocus();
    }
}

T100VOID T1003DEditorMainPanel::OnLeaveWindow(wxMouseEvent& event)
{

}

T100VOID T1003DEditorMainPanel::OnKeyDown(wxKeyEvent& event)
{
    T1003DEditorCallback::OnKeyDown(event.GetKeyCode());

    T100INT     key;

    key     = event.GetKeyCode();
    if(key == WXK_CONTROL){
        //DEBUGPRINT("ctrl");
    }

    switch(key){
    case WXK_CONTROL:
        {
            m_ctrlKey   = T100TRUE;
            if(m_appendState){
                SetCursor(*wxCROSS_CURSOR);
            }
        }
        break;
    }

}

T100VOID T1003DEditorMainPanel::OnKeyUp(wxKeyEvent& event)
{
    T1003DEditorCallback::OnKeyUp(event.GetKeyCode());

    T100INT     key;

    key     = event.GetKeyCode();
    if(key == WXK_CONTROL){
        //DEBUGPRINT("ctrl");
    }

    switch(key){
    case WXK_CONTROL:
        {
            m_ctrlKey   = T100FALSE;
            if(m_appendState){
                SetCursor(wxNullCursor);
            }
        }
        break;
    }
}

T100VOID T1003DEditorMainPanel::OnMouseLeftDown(wxMouseEvent& event)
{
    if(m_appendState){
        T1003DEditorCallback::Append();
        SetCursor(wxNullCursor);
        m_appendState   = T100FALSE;
    }

    SetFocus();
}

T100VOID T1003DEditorMainPanel::OnMouseRightDown(wxMouseEvent& event)
{
    if(m_appendState){
        T1003DEditorCallback::Remove();
        SetCursor(wxNullCursor);
        m_appendState   = T100FALSE;
    }

    SetFocus();
}

T100VOID T1003DEditorMainPanel::OnMouseMove(wxMouseEvent& event)
{
    static T100UINT x = 0;
    static T100UINT y = 0;

    T100INT     dx;
    T100INT     dy;



    dx   = event.GetPosition().x - x;
    dy   = event.GetPosition().y - y;

    x   = event.GetPosition().x;
    y   = event.GetPosition().y;

    if(m_ctrlKey){
        T1003DEditorCallback::Rotation(dx, dy);
    }else{

    }

    if(m_appendState){
        if(m_ctrlKey){
            T1003DEditorCallback::Position(event.GetPosition().x, event.GetPosition().y);
        }
    }

    T1003DEditorCallback::Move(x, y);
}
