#include "T100DiskCtrl.h"

#include <wx/dcclient.h>
#include "T100DiskCreatePartDialog.h"
#include "T100DiskDialog.h"

//
#include "T100DiskBrowsePartDemoDialog.h"


const long T100DiskCtrl::ID_PAINT = wxNewId();
const long T100DiskCtrl::ID_PART_CREATE = wxNewId();
const long T100DiskCtrl::ID_PART_EDIT = wxNewId();
const long T100DiskCtrl::ID_PART_REMOVE = wxNewId();
const long T100DiskCtrl::ID_PART_BROWSE = wxNewId();
const long T100DiskCtrl::ID_PART_FORMAT = wxNewId();


T100DiskCtrl::T100DiskCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos,
                     const wxSize& size, long style, const wxValidator& validator,
                     const wxString& name)
    :wxControl(parent, id, pos, size, style, validator, name)
{
    //ctor
    create();
}

T100DiskCtrl::~T100DiskCtrl()
{
    //dtor
    destroy();
}

T100VOID T100DiskCtrl::create()
{
    Connect(wxEVT_ERASE_BACKGROUND, (wxObjectEventFunction)&T100DiskCtrl::OnEraseBackground);

    Connect(wxEVT_PAINT, (wxObjectEventFunction)&T100DiskCtrl::OnPaint);
    Connect(wxEVT_RIGHT_DOWN, (wxObjectEventFunction)&T100DiskCtrl::OnMouse);

    Connect(ID_PART_CREATE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnCreatePart);
    Connect(ID_PART_EDIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnEditPart);
    Connect(ID_PART_REMOVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnRemovePart);
    Connect(ID_PART_BROWSE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnBrowsePart);
    Connect(ID_PART_FORMAT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnFormatPart);

    menu.Append(ID_PART_CREATE, _T("Create"));
    menu.Append(ID_PART_EDIT, _T("Edit"));
    menu.Append(ID_PART_REMOVE, _T("Remove"));
    menu.AppendSeparator();
    menu.Append(ID_PART_FORMAT, _T("Format"));
    menu.AppendSeparator();
    menu.Append(ID_PART_BROWSE, _T("Browse"));
}

T100VOID T100DiskCtrl::destroy()
{

}

T100VOID T100DiskCtrl::SetLength(T100DWORD length)
{
    m_disk.LENGTH   = length;
}

T100DWORD T100DiskCtrl::GetLength()
{
    return m_disk.LENGTH;
}

T100BOOL T100DiskCtrl::AppendPart(T100DISK_PART* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)->PART){
            return T100FALSE;
        }
    }

    T100DISK_PART_CTRL*     item    = T100NEW T100DISK_PART_CTRL();

    item->PART      = part;

    item->RATIO     = part->LENGTH * 1.0 / m_disk.LENGTH;

    T100FLOAT       temp;

    temp = item->RATIO;

    item->X         = m_current;
    item->Y         = 0;
    item->WIDTH     = GetSize().GetWidth() * item->RATIO;
    item->HEIGHT    = 25;

    m_current += item->WIDTH;

    m_parts.push_back(item);
    return T100TRUE;
}

T100BOOL T100DiskCtrl::RemovePart(T100DISK_PART* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)->PART){
            T100DISK_PART_CTRL* item = (*it);
            m_parts.erase(it);
            T100SAFE_DELETE(item);
            T100SAFE_DELETE(part);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100VOID T100DiskCtrl::OnCreatePart(wxCommandEvent& event)
{
    T100DiskCreatePartDialog        dialog(this);

    if(dialog.ShowModal() == wxID_OK){
        T100String          name;
        T100LONG            length;
        T100BOOL            boot;
        T100DISK_PART       part;

        name    = dialog.NameTextCtrl->GetValue().ToStdWstring();
        if(dialog.LengthComboBox->GetValue().ToLongLong(&length)){

        }else{
            return;
        }
        boot    = dialog.BootCheckBox->IsChecked();

        part.NAME       = name;
        part.LOCATION   = m_location;
        part.LENGTH     = length;
        part.BOOT       = boot;

        if(OnMenuCreate(&part)){
            T100DISK_PART*      item    = T100NEW T100DISK_PART();

            item->NAME      = part.NAME;
            item->LOCATION  = part.LOCATION;
            item->LENGTH    = part.LENGTH;
            item->BOOT      = part.BOOT;

            AppendPart(item);

            Refresh();
        }
    }
}

T100VOID T100DiskCtrl::OnEditPart(wxCommandEvent& event)
{

}

T100VOID T100DiskCtrl::OnRemovePart(wxCommandEvent& event)
{

}

T100VOID T100DiskCtrl::OnBrowsePart(wxCommandEvent& event)
{
    T100DiskBrowsePartDemoDialog        dialog(this);

    if(dialog.ShowModal() == wxID_OK){

    }
}

T100VOID T100DiskCtrl::OnFormatPart(wxCommandEvent& event)
{

}

T100VOID T100DiskCtrl::OnEraseBackground(wxEraseEvent& event)
{

}

T100VOID T100DiskCtrl::OnPaint(wxPaintEvent& event)
{
    wxClientDC      dc(this);

    DrawDisk(dc);

    DrawParts(dc);

}

T100VOID T100DiskCtrl::OnMouse(wxMouseEvent& event)
{
    T100INT     result;

    result = Hit(event.GetX());


    //PopupMenu(&menu);

    ShowMenu(result);
}

T100VOID T100DiskCtrl::DrawDisk(wxDC& dc)
{
    T100WORD        width;
    T100WORD        height;

    width   = GetSize().GetWidth() - 5;
    height  = GetSize().GetHeight() - 5;

    dc.SetBrush(*wxGREEN_BRUSH);

    dc.DrawRectangle(wxPoint(0, 0), wxSize(width, height));

    //dc.DrawText(L"1G", wxPoint(150, 5));


}

T100VOID T100DiskCtrl::DrawParts(wxDC& dc)
{
    for(T100DISK_PART_CTRL* item : m_parts){
        if(item){
            DrawPart(dc, item);
        }
    }
}

T100VOID T100DiskCtrl::DrawPart(wxDC& dc, T100DISK_PART_CTRL* item)
{
    T100WORD        x;
    T100WORD        y;
    T100WORD        width;
    T100WORD        height;

    x       = item->X;
    y       = item->Y;
    width   = item->WIDTH;
    height  = item->HEIGHT;

    dc.SetBrush(*wxYELLOW_BRUSH);

    dc.DrawRectangle(wxPoint(item->X, item->Y), wxSize(item->WIDTH, item->HEIGHT));

    //dc.DrawText(L"1G", wxPoint(150, 5));
}


const wxBrush* T100DiskCtrl::GetBrush(T100COLOUR_PRIMITIVE_TYPE type)
{
    switch(type){
    case T100COLOUR_BLACK:
        {
            return wxBLACK_BRUSH;
        }
        break;
    case T100COLOUR_WHITE:
        {
            return wxWHITE_BRUSH;
        }
        break;
    case T100COLOUR_RED:
        {
            return wxRED_BRUSH;
        }
        break;
    case T100COLOUR_GREEN:
        {
            return wxGREEN_BRUSH;
        }
        break;
    case T100COLOUR_BLUE:
        {
            return wxBLUE_BRUSH;
        }
        break;
    case T100COLOUR_ORANGE:
        {
            return wxBLACK_BRUSH;
        }
        break;
    case T100COLOUR_YELLOW:
        {
            return wxYELLOW_BRUSH;
        }
        break;
    case T100COLOUR_PURPLE:
        {
            return wxBLACK_BRUSH;
        }
        break;
    }

    return wxBLACK_BRUSH;
}

T100INT T100DiskCtrl::Hit(T100WORD x)
{
    T100INT     result      = -1;
    T100WORD    current     = 0;
    T100WORD    left;
    T100WORD    right;
    T100WORD    index;


    for(index = 0; index < m_parts.size(); index++){
        T100DISK_PART_CTRL*     item;

        item = m_parts[index];
        if(item){
            left    = current;
            right   = left + item->WIDTH;

            if(x >= left && x <= right){
                return index;
            }else{
                current += item->WIDTH;
            }
        }
    }

    return result;
}

T100VOID T100DiskCtrl::ShowMenu(T100WORD index)
{
    if(index < 0 || index >= m_parts.size()){
        PopupMenu(&menu);
    }else{
        T100DISK_PART_CTRL*     ctrl    = T100NULL;

        ctrl = m_parts[index];

        if(ctrl){
            PopupMenu(&menu);
        }
    }
}

T100BOOL T100DiskCtrl::Load(T100DISK_PART_CTRL_VECTOR& parts)
{
    T100BOOL            result          = T100TRUE;
    T100DWORD           total           = 0;

    m_parts = parts;

    for(T100DISK_PART_CTRL* item : parts){
        if(item){
            total += item->PART->LENGTH;
        }else{
            return T100FALSE;
        }
    }

    m_location = total + 1;

    return result;
}

T100BOOL T100DiskCtrl::Load(T100DISK_PART_VECTOR& parts)
{
    T100BOOL            result          = T100TRUE;
    T100DWORD           total           = 0;

    for(T100DISK_PART* item : parts){
        if(item){
            T100DISK_PART_CTRL*     part = T100NEW T100DISK_PART_CTRL();

            part->RATIO     = item->LENGTH * 1.0 / m_disk.LENGTH;
            part->HEIGHT    = 30;
            part->WIDTH     = GetSize().GetWidth() * part->RATIO;
            part->X         = GetSize().GetWidth() * (total * 1.0 / m_disk.LENGTH);
            part->Y         = 0;

            part->PART      = item;

            T100DISK_PART_CTRL& temp = *part;

            m_parts.push_back(part);

            total += item->LENGTH;
        }else{
            return T100FALSE;
        }
    }

    m_location = total + 1;

    return result;
}
