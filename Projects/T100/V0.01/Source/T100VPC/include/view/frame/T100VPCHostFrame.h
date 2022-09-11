#ifndef T100VPCHOSTFRAME_H
#define T100VPCHOSTFRAME_H

#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include "T100Common.h"


class T100VPCHostFrame : public wxFrame
{
    public:
        T100VPCHostFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHostFrame();

        wxMenu*             Menu1;
		wxMenuBar*          MenuBar1;
		wxMenuItem*         MenuLoad;
		wxMenuItem*         MenuRun;
		wxStatusBar*        StatusBar1;

		wxBoxSizer*         BoxSizer1;

    protected:
        static const long ID_MENU_LOAD;
        static const long ID_MENU_RUN;
		static const long ID_STATUSBAR1;

    private:
        void OnMenuLoadSelected(wxCommandEvent& event);
        void OnMenuRunSelected(wxCommandEvent& event);

    private:
        T100VOID            create();
        T100VOID            destroy();

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100VPCHOSTFRAME_H
