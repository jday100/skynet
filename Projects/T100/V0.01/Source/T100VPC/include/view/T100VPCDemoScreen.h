#ifndef T100VPCDEMOSCREEN_H
#define T100VPCDEMOSCREEN_H

#include <wx/panel.h>
#include "T100Common.h"
class T100Display;


class T100VPCDemoScreen : public wxPanel
{
    public:
        T100VPCDemoScreen(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCDemoScreen();

        T100VOID            setDisplay(T100Display*);
        T100Display*        getDisplay();

    protected:
        T100Display*        m_display           = T100NULL;

    private:
        void OnEraseBackground(wxEraseEvent& event);
        void OnPaint(wxPaintEvent& event);

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100VPCDEMOSCREEN_H
