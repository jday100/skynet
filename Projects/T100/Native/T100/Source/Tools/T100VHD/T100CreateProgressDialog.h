#ifndef T100CREATEPROGRESSDIALOG_H
#define T100CREATEPROGRESSDIALOG_H

//(*Headers(T100CreateProgressDialog)
#include <wx/dialog.h>
#include <wx/gauge.h>
#include <wx/sizer.h>
//*)

#include "T100Common.h"
#include "T100VDISKCommon.h"
#include "T100VHDCommon.h"
#include "T100WXCreateThread.h"


class T100CreateProgressDialog: public wxDialog
{
	public:

		T100CreateProgressDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100CreateProgressDialog();

		//(*Declarations(T100CreateProgressDialog)
		wxGauge* Gauge1;
		//*)

		T100STRING                          m_filename;
        T100INT64                           m_length                = 0LL;
        T100VDISK_TYPE                      m_type                  = T100VDISK_TYPE_NONE;
        T100VDISK_STORAGE_TYPE              m_storage               = T100VDISK_STORAGE_TYPE_NONE;

        static const long ID_THREAD_PROGRESS;
        static const long ID_THREAD_FINISHED;

	protected:
	    T100VOID            create();
	    T100VOID            destroy();

		//(*Identifiers(T100CreateProgressDialog)
		static const long ID_GAUGE1;
		//*)

		T100WXCreateThread*     m_thread            = T100NULL;

		static void    progress(T100VOID*, T100BYTE);
		static void    finished(T100VOID*, T100BYTE);

		void    OnButtonCancelClick(wxCommandEvent& event);
		void    OnThreadProgress(wxThreadEvent& event);
		void    OnThreadFinished(wxThreadEvent& event);

	private:

		//(*Handlers(T100CreateProgressDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
