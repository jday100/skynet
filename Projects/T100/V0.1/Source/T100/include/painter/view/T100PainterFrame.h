#ifndef T100PAINTERFRAME_H
#define T100PAINTERFRAME_H

#include <wx/frame.h>
#include "T100Common.h"

namespace T100Painter{
class T100PainterCanvas;


class T100PainterFrame : public wxFrame
{
    public:
        T100PainterFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100PainterFrame();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100PainterCanvas*      m_canvas            = T100NULL;

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERFRAME_H
