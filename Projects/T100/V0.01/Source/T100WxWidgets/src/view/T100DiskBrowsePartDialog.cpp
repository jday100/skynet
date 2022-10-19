#include "T100DiskBrowsePartDialog.h"

#include <wx/intl.h>
#include <wx/string.h>
#include <wx/dnd.h>


const long T100DiskBrowsePartDialog::ID_GENERICDIRCTRL = wxNewId();
const long T100DiskBrowsePartDialog::ID_VDISKDIRCTRL = wxNewId();

BEGIN_EVENT_TABLE(T100DiskBrowsePartDialog,wxDialog)
    EVT_TREE_BEGIN_DRAG     (wxID_TREECTRL, T100DiskBrowsePartDialog::OnTreeBeginDrag)
    EVT_TREE_END_DRAG       (wxID_TREECTRL, T100DiskBrowsePartDialog::OnTreeEndDrag)
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
	DiskDirCtrl = T100NEW T100DiskBrowseCtrl(this);
	BoxSizer4->Add(DiskDirCtrl, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

}

void T100DiskBrowsePartDialog::OnTreeBeginDrag(wxTreeEvent& event)
{
    wxDirItemData*      itemData        = T100NULL;
    wxTreeItemId        itemId;

    wxFileDataObject    data;
    wxDropSource        source(this);


    itemId      = event.GetItem();

    itemData    = static_cast<wxDirItemData*>(GenericDirCtrl->GetTreeCtrl()->GetItemData(itemId));

    if(itemData){
        if(itemData->m_isDir){

        }else{
            data.AddFile(itemData->m_path);
            source.SetData(data);
            source.DoDragDrop();
        }
    }
}

void T100DiskBrowsePartDialog::OnTreeEndDrag(wxTreeEvent& event)
{

}
