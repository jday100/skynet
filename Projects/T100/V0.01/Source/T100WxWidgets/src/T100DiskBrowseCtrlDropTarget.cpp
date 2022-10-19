#include "T100DiskBrowseCtrlDropTarget.h"

T100DiskBrowseCtrlDropTarget::T100DiskBrowseCtrlDropTarget(T100DiskBrowseCtrl* ctrl)
    :m_ctrl(ctrl)
{
    //ctor
}

T100DiskBrowseCtrlDropTarget::~T100DiskBrowseCtrlDropTarget()
{
    //dtor
}

bool T100DiskBrowseCtrlDropTarget::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
    wxTreeItemId    id;
    int             flag;

    id = m_ctrl->GetTreeCtrl()->HitTest(wxPoint(x, y), flag);

    m_ctrl->Copy(filenames, id);

}
