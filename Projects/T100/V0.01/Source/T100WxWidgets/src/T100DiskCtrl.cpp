#include "T100DiskCtrl.h"

#include <wx/dcclient.h>
#include <wx/msgdlg.h>
#include "T100DiskCreatePartDialog.h"
#include "T100DiskDialog.h"

//
#include "T100DiskBrowsePartDemoDialog.h"

#include "T100DiskEditPartDialog.h"
#include "T100DiskFormatPartDialog.h"
#include "T100DiskBrowsePartDialog.h"


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
    Connect(wxEVT_SIZE, (wxObjectEventFunction)&T100DiskCtrl::OnSize);

    Connect(ID_PART_CREATE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnCreatePart);
    Connect(ID_PART_EDIT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnEditPart);
    Connect(ID_PART_REMOVE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnRemovePart);
    Connect(ID_PART_BROWSE, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnBrowsePart);
    Connect(ID_PART_FORMAT, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&T100DiskCtrl::OnFormatPart);

    m_menu.Append(ID_PART_CREATE,   _T("Create"));
    m_menu.Append(ID_PART_EDIT,     _T("Edit"));
    m_menu.Append(ID_PART_REMOVE,   _T("Remove"));
    m_menu.AppendSeparator();
    m_menu.Append(ID_PART_FORMAT,   _T("Format"));
    m_menu.AppendSeparator();
    m_menu.Append(ID_PART_BROWSE,   _T("Browse"));
}

T100VOID T100DiskCtrl::destroy()
{

}

T100VOID T100DiskCtrl::SetLength(T100DWORD length)
{
    m_disk.LENGTH   = length;

    //
    init();
}

T100DWORD T100DiskCtrl::GetLength()
{
    return m_disk.LENGTH;
}

T100BOOL T100DiskCtrl::init()
{
    T100INT         width;
    T100INT         height;

    Clear();

    GetClientSize(&width, &height);

    T100DISK_PART_CTRL*     item    = T100NEW T100DISK_PART_CTRL();

    item->RATIO     = 1.0;
    item->WIDTH     = width;
    item->HEIGHT    = height;
    item->X         = 0;
    item->Y         = 0;

    T100DISK_PART*      part    = T100NEW T100DISK_PART();

    part->LOCATION      = 1;
    part->LENGTH        = m_disk.LENGTH - 1;
    part->BOOT          = T100FALSE;
    part->ISUSED        = T100FALSE;
    part->ISFORMATED    = T100FALSE;

    item->PART      = part;

    m_parts.push_back(item);
    Refresh();

    return T100TRUE;
}

T100DISK_PART_CTRL_VECTOR& T100DiskCtrl::GetAllParts()
{
    return m_parts;
}

T100BOOL T100DiskCtrl::CreatePart(T100DISK_PART_CTRL* source, T100DISK_PART& target)
{
    if(!source)return T100FALSE;
    if(!source->PART)return T100FALSE;

    T100DWORD       start;
    T100DWORD       stop;
    T100DWORD       total;

    start       = source->PART->LOCATION;
    stop        = source->PART->LOCATION + source->PART->LENGTH;

    total       = target.LOCATION + target.LENGTH;

    if(start > target.LOCATION || stop < target.LOCATION){
        return T100FALSE;
    }

    if(start > total || stop < total){
        return T100FALSE;
    }

    if(start != target.LOCATION && stop != total){
        T100DISK_PART_CTRL*     first   = T100NULL;
        T100DISK_PART_CTRL*     second  = T100NULL;
        T100DISK_PART_CTRL*     three   = T100NULL;

        if(splitPart(source, &target, first, second, three)){
            if(updatePart(source, first, second, three)){
                return T100TRUE;
            }else{
                T100SAFE_DELETE(first->PART);
                T100SAFE_DELETE(first);
                T100SAFE_DELETE(second->PART);
                T100SAFE_DELETE(second);
                T100SAFE_DELETE(three->PART);
                T100SAFE_DELETE(three);
            }
        }
    }else if(start == target.LOCATION && stop == total){
        source->PART->NAME      = target.NAME;
        source->PART->BOOT      = target.BOOT;
        source->PART->ISUSED    = T100TRUE;
        return T100TRUE;
    }else{
        T100DISK_PART_CTRL*     first   = T100NULL;
        T100DISK_PART_CTRL*     second  = T100NULL;

        if(splitPart(source, &target, first, second)){
            if(updatePart(source, first, second)){
                return T100TRUE;
            }else{
                T100SAFE_DELETE(first->PART);
                T100SAFE_DELETE(first);
                T100SAFE_DELETE(second->PART);
                T100SAFE_DELETE(second);
            }
        }
    }

    return T100FALSE;
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

    if(resize(GetSize().GetWidth(), GetSize().GetHeight(), item)){

    }else{
        T100SAFE_DELETE(item);
        return T100FALSE;
    }

    m_parts.push_back(item);
    return T100TRUE;
}

T100BOOL T100DiskCtrl::EditPart(T100DISK_PART* part)
{

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

T100BOOL T100DiskCtrl::FormatPart(T100DISK_PART* part)
{

}

T100BOOL T100DiskCtrl::BrowsePart(T100DISK_PART* part)
{

}

T100BOOL T100DiskCtrl::AppendPartCtrl(T100DISK_PART_CTRL* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)){
            return T100FALSE;
        }
    }

    if(resize(part)){
        m_parts.push_back(part);
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100DiskCtrl::RemovePartCtrl(T100DISK_PART_CTRL* part)
{
    T100DISK_PART_CTRL_VECTOR::iterator      it;

    for(it = m_parts.begin(); it != m_parts.end(); it++){
        if(part == (*it)){
            m_parts.erase(it);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100DiskCtrl::splitPart(T100DISK_PART_CTRL* source, T100DISK_PART* target, T100DISK_PART_CTRL*& first, T100DISK_PART_CTRL*& second, T100DISK_PART_CTRL*& three)
{
    if(!source)return T100FALSE;
    if(!source->PART)return T100FALSE;
    if(!target)return T100FALSE;

    T100DISK_PART*          first_part      = T100NULL;
    T100DISK_PART*          second_part     = T100NULL;
    T100DISK_PART*          three_part      = T100NULL;

    first_part      = T100NEW T100DISK_PART();
    second_part     = T100NEW T100DISK_PART();
    three_part      = T100NEW T100DISK_PART();

    first_part->LOCATION        = source->PART->LOCATION;
    first_part->LENGTH          = target->LOCATION - source->PART->LOCATION;
    first_part->BOOT            = T100FALSE;
    first_part->ISFORMATED      = T100FALSE;
    first_part->ISUSED          = T100FALSE;

    second_part->NAME           = target->NAME;
    second_part->LOCATION       = target->LOCATION;
    second_part->LENGTH         = target->LENGTH;
    second_part->BOOT           = target->BOOT;
    second_part->ISFORMATED     = T100FALSE;
    second_part->ISUSED         = T100TRUE;

    three_part->LOCATION        = target->LOCATION + target->LENGTH;
    three_part->LENGTH          = source->PART->LOCATION + source->PART->LENGTH - three_part->LOCATION;
    three_part->BOOT            = T100FALSE;
    three_part->ISFORMATED      = T100FALSE;
    three_part->ISUSED          = T100FALSE;

    if(createPart(first_part, first)){
        if(createPart(second_part, second)){
            if(createPart(three_part, three)){
                T100SAFE_DELETE(first_part);
                T100SAFE_DELETE(second_part);
                T100SAFE_DELETE(three_part);
                return T100TRUE;
            }else{
                T100SAFE_DELETE(second->PART);
                T100SAFE_DELETE(second);
                T100SAFE_DELETE(first->PART);
                T100SAFE_DELETE(first);
            }
        }else{
            T100SAFE_DELETE(first->PART);
            T100SAFE_DELETE(first);
        }
    }

    T100SAFE_DELETE(first_part);
    T100SAFE_DELETE(second_part);
    T100SAFE_DELETE(three_part);

    return T100FALSE;
}

T100BOOL T100DiskCtrl::splitPart(T100DISK_PART_CTRL* source, T100DISK_PART* target, T100DISK_PART_CTRL*& first, T100DISK_PART_CTRL*& second)
{
    if(!source)return T100FALSE;
    if(!source->PART)return T100FALSE;
    if(!target)return T100FALSE;

    T100DISK_PART*          first_part      = T100NULL;
    T100DISK_PART*          second_part     = T100NULL;

    first_part      = T100NEW T100DISK_PART();
    second_part     = T100NEW T100DISK_PART();

    first_part->NAME            = target->NAME;
    first_part->LOCATION        = target->LOCATION;
    first_part->LENGTH          = target->LENGTH;
    first_part->BOOT            = target->BOOT;
    first_part->ISFORMATED      = T100FALSE;
    first_part->ISUSED          = T100TRUE;

    second_part->LOCATION       = target->LOCATION + target->LENGTH;
    second_part->LENGTH         = source->PART->LENGTH - target->LENGTH;
    second_part->BOOT           = T100FALSE;
    second_part->ISFORMATED     = T100FALSE;
    second_part->ISUSED         = T100FALSE;

    if(createPart(first_part, first)){
        if(createPart(second_part, second)){
            T100SAFE_DELETE(first_part);
            T100SAFE_DELETE(second_part);
            return T100TRUE;
        }else{
            T100SAFE_DELETE(first->PART);
            T100SAFE_DELETE(first);
        }
    }

    T100SAFE_DELETE(first_part);
    T100SAFE_DELETE(second_part);

    return T100FALSE;
}

T100BOOL T100DiskCtrl::updatePart(T100DISK_PART_CTRL* source, T100DISK_PART_CTRL* first, T100DISK_PART_CTRL* second)
{
    if(RemovePartCtrl(source)){
        if(AppendPartCtrl(first)){
            if(AppendPartCtrl(second)){
                T100SAFE_DELETE(source->PART);
                T100SAFE_DELETE(source);
                return T100TRUE;
            }else{
                RemovePartCtrl(first);
                AppendPartCtrl(source);
            }
        }else{
            AppendPartCtrl(source);
        }
    }

    return T100FALSE;
}

T100BOOL T100DiskCtrl::updatePart(T100DISK_PART_CTRL* source, T100DISK_PART_CTRL* first, T100DISK_PART_CTRL* second, T100DISK_PART_CTRL* three)
{
    if(RemovePartCtrl(source)){
        if(AppendPartCtrl(first)){
            if(AppendPartCtrl(second)){
                if(AppendPartCtrl(three)){
                    T100SAFE_DELETE(source->PART);
                    T100SAFE_DELETE(source);
                    return T100TRUE;
                }else{
                    RemovePartCtrl(first);
                    RemovePartCtrl(second);
                    AppendPartCtrl(source);
                }
            }else{
                RemovePartCtrl(first);
                AppendPartCtrl(source);
            }
        }else{
            AppendPartCtrl(source);
        }
    }

    return T100FALSE;
}

T100BOOL T100DiskCtrl::createPart(T100DISK_PART* source, T100DISK_PART_CTRL*& target)
{
    if(!source)return T100FALSE;

    T100DISK_PART_CTRL*     item    = T100NULL;
    T100DISK_PART*          part    = T100NULL;

    item = T100NEW T100DISK_PART_CTRL();
    part = T100NEW T100DISK_PART();

    part->NAME          = source->NAME;
    part->LOCATION      = source->LOCATION;
    part->LENGTH        = source->LENGTH;
    part->BOOT          = source->BOOT;
    part->ISFORMATED    = source->ISFORMATED;
    part->ISUSED        = source->ISUSED;

    item->PART      = part;
    item->RATIO     = part->LENGTH * 1.0 / m_disk.LENGTH;
    item->HEIGHT    = GetSize().GetHeight() - 4;

    if(resize(item)){
        target = item;
        return T100TRUE;
    }

    T100SAFE_DELETE(part);
    T100SAFE_DELETE(item);

    return T100FALSE;
}

T100VOID T100DiskCtrl::OnCreatePart(wxCommandEvent& event)
{
    if(-1 == m_current)return;

    T100DiskCreatePartDialog        dialog(this);

    T100BOOL                boot;
    T100DISK_PART_CTRL*     item    = T100NULL;
    T100DISK_PART*          part    = T100NULL;

    item = m_parts[m_current];
    if(!item)return;
    if(!item->PART)return;

    part = item->PART;

    dialog.LocationComboBox->SetEditable(T100FALSE);
    dialog.LocationComboBox->SetValue(std::to_string(part->LOCATION));
    dialog.LengthComboBox->SetValue(std::to_string(part->LENGTH));

    if(hasBoot(boot)){

    }else{
        return;
    }

    if(boot){
        dialog.BootCheckBox->Enable(T100FALSE);
    }

    if(dialog.ShowModal() == wxID_OK){
        T100String          name;
        T100LONG            location;
        T100LONG            length;
        T100DISK_PART       temp;

        name    = dialog.NameTextCtrl->GetValue().ToStdWstring();
        if(dialog.LocationComboBox->GetValue().ToLongLong(&location)){

        }else{
            return;
        }
        if(dialog.LengthComboBox->GetValue().ToLongLong(&length)){

        }else{
            return;
        }
        boot    = dialog.BootCheckBox->IsChecked();

        temp.NAME       = name;
        temp.LOCATION   = location;
        temp.LENGTH     = length;
        temp.BOOT       = boot;

        if(OnMenuCreate(&temp)){
            if(CreatePart(item, temp)){
                Refresh();
            }
        }
    }
}

T100VOID T100DiskCtrl::OnEditPart(wxCommandEvent& event)
{
    T100DiskEditPartDialog      dialog(this);

    if(dialog.ShowModal() == wxID_OK){

    }
}

T100VOID T100DiskCtrl::OnRemovePart(wxCommandEvent& event)
{
    if(-1 == m_current)return;

    wxMessageDialog         dialog(this, _("Are you sure?"));

    if(dialog.ShowModal() == wxID_OK){
        T100DISK_PART_CTRL*     item    = T100NULL;

        item = m_parts[m_current];

        if(item){
            if(item->PART){
                if(OnMenuRemove(item->PART)){
                    item->PART->BOOT        = T100FALSE;
                    item->PART->ISFORMATED  = T100FALSE;
                    item->PART->ISUSED      = T100FALSE;

                    Refresh();
                }
            }
        }
    }
}

T100VOID T100DiskCtrl::OnBrowsePart(wxCommandEvent& event)
{
    if(-1 == m_current)return;

    T100DISK_PART_CTRL*     item    = T100NULL;

    item = m_parts[m_current];

    if(!item)return;
    if(!item->PART)return;


    T100DiskBrowsePartDialog        dialog(this);

    dialog.DiskDirCtrl->SetDiskCtrl(this);
    dialog.DiskDirCtrl->Load();

    if(dialog.ShowModal() == wxID_OK){

    }
}

T100VOID T100DiskCtrl::OnFormatPart(wxCommandEvent& event)
{
    if(-1 == m_current)return;

    T100DISK_PART_CTRL*     item    = T100NULL;

    item = m_parts[m_current];

    if(!item)return;
    if(!item->PART)return;

    T100BOOL                isboot = T100TRUE;
    T100DISK_PART_INFO      info;

    isboot      = item->PART->BOOT;
    info.PART   = item->PART;

    if(isboot){
        T100DiskFormatPartDialog        dialog(this);

        if(dialog.ShowModal() == wxID_OK){
            info.BOOT_FILE  = dialog.FileComboBox->GetValue().ToStdWstring();
        }else{
            return;
        }
    }else{
        wxMessageDialog         dialog(this, _("Are you sure?"));

        if(dialog.ShowModal() == wxID_OK){

        }else{
            return;
        }
    }

    if(OnMenuFormat(&info)){
        item->PART->ISFORMATED  = T100TRUE;
        Refresh();
    }
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
    m_current   = Hit(event.GetX());

    SetMenu(m_current);

    ShowMenu(m_current);
}

T100VOID T100DiskCtrl::OnSize(wxSizeEvent& event)
{
    ReSize();
}

T100BOOL T100DiskCtrl::ReSize()
{
    T100INT         width;
    T100INT         height;

    GetClientSize(&width, &height);


    for(T100DISK_PART_CTRL* item : m_parts){
        if(item){
            resize(width, height, item);
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100DiskCtrl::resize(T100WORD width, T100WORD height, T100DISK_PART_CTRL* item)
{
    item->WIDTH     = width * item->RATIO;
    item->HEIGHT    = item->HEIGHT;
    item->X         = width * (item->PART->LOCATION * 1.0 / m_disk.LENGTH);
    item->Y         = item->Y;

    return T100TRUE;
}

T100BOOL T100DiskCtrl::resize(T100DISK_PART_CTRL* item)
{
    T100WORD        width;
    T100WORD        height;

    width   = GetSize().GetWidth();
    height  = GetSize().GetHeight();

    item->WIDTH     = width * item->RATIO;
    item->HEIGHT    = item->HEIGHT;
    item->X         = width * (item->PART->LOCATION * 1.0 / m_disk.LENGTH);
    item->Y         = item->Y;

    //
    T100WORD        value;

    value = item->WIDTH;
    value = item->HEIGHT;
    value = item->X;
    value = item->Y;

    return T100TRUE;
}

T100BOOL T100DiskCtrl::hasBoot(T100BOOL& result)
{
    for(T100DISK_PART_CTRL* item : m_parts){
        if(item){
            if(item->PART){
                if(item->PART->BOOT){
                    result = T100TRUE;
                    return T100TRUE;
                }
            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    result = T100FALSE;
    return T100TRUE;
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

    if(item->PART->ISUSED){
        dc.SetBrush(*wxYELLOW_BRUSH);
    }else{
        dc.SetBrush(*wxGREEN_BRUSH);
    }

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
    T100WORD    left;
    T100WORD    right;
    T100WORD    index;


    for(index = 0; index < m_parts.size(); index++){
        T100DISK_PART_CTRL*     item;

        item = m_parts[index];
        if(item){
            left    = item->X;
            right   = left + item->WIDTH;

            if(x >= left && x <= right){
                return index;
            }
        }
    }

    return result;
}

T100VOID T100DiskCtrl::ShowMenu(T100WORD index)
{
    if(index < 0 || index >= m_parts.size()){
        PopupMenu(&m_menu);
    }else{
        T100DISK_PART_CTRL*     ctrl    = T100NULL;

        ctrl = m_parts[index];

        if(ctrl){
            PopupMenu(&m_menu);
        }
    }
}

T100VOID T100DiskCtrl::SetMenu(T100INT index)
{
    if(-1 == index)return;

    T100DISK_PART_CTRL*     item    = T100NULL;
    T100DISK_PART*          part    = T100NULL;

    if(0 <= index && m_parts.size() > index){

    }else{
        return;
    }

    item    = m_parts[index];
    if(!item)return;
    if(!item->PART)return;

    part = item->PART;

    if(!part->ISUSED){
        m_menu.Enable(ID_PART_CREATE,       T100TRUE);
        m_menu.Enable(ID_PART_EDIT,         T100FALSE);
        m_menu.Enable(ID_PART_REMOVE,       T100FALSE);
        m_menu.Enable(ID_PART_FORMAT,       T100FALSE);
        m_menu.Enable(ID_PART_BROWSE,       T100FALSE);
    }else{
        if(part->ISFORMATED){
            m_menu.Enable(ID_PART_CREATE,       T100FALSE);
            m_menu.Enable(ID_PART_EDIT,         T100TRUE);
            m_menu.Enable(ID_PART_REMOVE,       T100TRUE);
            m_menu.Enable(ID_PART_FORMAT,       T100TRUE);
            m_menu.Enable(ID_PART_BROWSE,       T100TRUE);
        }else{
            m_menu.Enable(ID_PART_CREATE,       T100FALSE);
            m_menu.Enable(ID_PART_EDIT,         T100TRUE);
            m_menu.Enable(ID_PART_REMOVE,       T100TRUE);
            m_menu.Enable(ID_PART_FORMAT,       T100TRUE);
            m_menu.Enable(ID_PART_BROWSE,       T100FALSE);
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

    if(0 == parts.size()){

    }else{
        Clear();
    }

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

T100BOOL T100DiskCtrl::Clear()
{
    m_location  = 1;
    m_parts.clear();
    return T100TRUE;
}
