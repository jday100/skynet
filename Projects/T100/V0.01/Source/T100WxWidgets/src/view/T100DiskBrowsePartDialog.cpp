#include "T100DiskBrowsePartDialog.h"

#include <wx/intl.h>
#include <wx/string.h>

const long T100DiskBrowsePartDialog::ID_GENERICDIRCTRL = wxNewId();
const long T100DiskBrowsePartDialog::ID_VDISKDIRCTRL = wxNewId();

BEGIN_EVENT_TABLE(T100DiskBrowsePartDialog,wxDialog)

END_EVENT_TABLE()

T100DiskBrowsePartDialog::T100DiskBrowsePartDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100DiskBrowsePartDialog::~T100DiskBrowsePartDialog()
{
    //dtor
}

void T100DiskBrowsePartDialog::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	GenericDirCtrl = new wxGenericDirCtrl(this, ID_GENERICDIRCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString, 0, _T("ID_GENERICDIRCTRL1"));
	BoxSizer3->Add(GenericDirCtrl, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	VDiskDirCtrl = T100NEW T100FileSystemCtrl(this);
	BoxSizer4->Add(VDiskDirCtrl, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

}
