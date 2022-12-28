#ifndef T100EDITORFRAME_H
#define T100EDITORFRAME_H

#include <wx/frame.h>

namespace T100Editor{

class T100EditorFrame : public wxFrame
{
    public:
        T100EditorFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100EditorFrame();

    protected:

    private:

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100EDITORFRAME_H
