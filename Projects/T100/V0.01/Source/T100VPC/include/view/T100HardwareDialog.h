#ifndef T100HARDWAREDIALOG_H
#define T100HARDWAREDIALOG_H

//(*Headers(T100HardwareDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class T100HardwareDialog: public wxDialog
{
	public:

		T100HardwareDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100HardwareDialog();

		//(*Declarations(T100HardwareDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100HardwareDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(T100HardwareDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
