#ifndef T100DISKBROWSECREATEFOLDERDIALOG_H
#define T100DISKBROWSECREATEFOLDERDIALOG_H

#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>


class T100DiskBrowseCreateFolderDialog : public wxDialog
{
    public:
        T100DiskBrowseCreateFolderDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskBrowseCreateFolderDialog();

        wxStaticText* StaticText1;
		wxTextCtrl* FolderTextCtrl;

    protected:
        static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_FOLDER;

    private:
        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKBROWSECREATEFOLDERDIALOG_H
