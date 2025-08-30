#include "T100SearchPanel.h"

T100SearchPanel::T100SearchPanel(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxValidator& validator ,
                const wxString &name ) :
    wxListView(parent, winid, pos, size, style, validator, name)
{
    //ctor
}

T100SearchPanel::~T100SearchPanel()
{
    //dtor
}
