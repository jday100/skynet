#ifndef T1003DEDITORSETTINGDIALOG_H
#define T1003DEDITORSETTINGDIALOG_H


#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listbook.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>

#include <wx/propgrid/propgrid.h>

#include "T100Common.h"

class T1003DEditorSettingDialog: public wxDialog
{
	public:

		T1003DEditorSettingDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T1003DEditorSettingDialog();

		wxBoxSizer* BoxSizer5;

		wxListbook* Listbook1;

	protected:
	    wxPropertyGrid*         m_gridPtr           = T100NULL;

		static const long ID_PANEL3;

		static const long ID_LISTBOOK1;

	private:

	protected:
	    T100VOID                    init();
	    T100VOID                    uninit();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
