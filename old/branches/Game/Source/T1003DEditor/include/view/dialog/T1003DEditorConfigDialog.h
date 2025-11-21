#ifndef T1003DEDITORCONFIGDIALOG_H
#define T1003DEDITORCONFIGDIALOG_H

//(*Headers(T1003DEditorConfigDialog)
#include <wx/clrpicker.h>
#include <wx/dialog.h>
//*)

class T1003DEditorConfigDialog: public wxDialog
{
	public:

		T1003DEditorConfigDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T1003DEditorConfigDialog();

		//(*Declarations(T1003DEditorConfigDialog)
		wxColourPickerCtrl* ColourPickerCtrl1;
		//*)

	protected:

		//(*Identifiers(T1003DEditorConfigDialog)
		static const long ID_COLOURPICKERCTRL1;
		//*)

	private:

		//(*Handlers(T1003DEditorConfigDialog)
		void OnColourPickerCtrl1ColourChanged(wxColourPickerEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
