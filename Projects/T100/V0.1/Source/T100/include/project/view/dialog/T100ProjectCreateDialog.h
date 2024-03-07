#ifndef T100PROJECTCREATEDIALOG_H
#define T100PROJECTCREATEDIALOG_H

//(*Headers(T100ProjectCreateDialog)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "T100Common.h"

class T100ProjectCreateDialog: public wxDialog
{
	public:

		T100ProjectCreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100ProjectCreateDialog();

		//(*Declarations(T100ProjectCreateDialog)
		wxChoice* Choice1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:
        void OnButtonApplyClick(wxCommandEvent& event);

		//(*Identifiers(T100ProjectCreateDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		//*)

	private:
	    T100VOID            create();
	    T100VOID            destroy();

		//(*Handlers(T100ProjectCreateDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
