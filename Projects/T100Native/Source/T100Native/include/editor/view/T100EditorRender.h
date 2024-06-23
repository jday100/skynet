#ifndef T100EDITORRENDER_H
#define T100EDITORRENDER_H

#include "T100WxRender.h"

class T100EditorRender : public T100WxRender
{
    public:
        T100EditorRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPanelNameStr);
        virtual ~T100EditorRender();

    protected:
        T100VOID            OnKeyDown(wxKeyEvent& event);
        T100VOID            OnChar(wxKeyEvent& event);

        T100VOID            OnMouseMove(wxMouseEvent& event);
        T100VOID            OnLeftDown(wxMouseEvent& event);
        T100VOID            OnLeftUp(wxMouseEvent& event);

    private:
        T100INT             m_begin_x, m_begin_y;
        T100INT             m_end_x, m_end_y;

        DECLARE_EVENT_TABLE()
};

#endif // T100EDITORRENDER_H
