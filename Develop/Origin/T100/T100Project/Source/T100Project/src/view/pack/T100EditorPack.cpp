#include "T100EditorPack.h"

T100EditorPack::T100EditorPack(wxWindow* parent) :
    T100Pack(parent)
{
    //ctor
    init();
}

T100EditorPack::~T100EditorPack()
{
    //dtor
    uninit();
}

T100VOID T100EditorPack::init()
{
    m_editor        = T100NEW T100Editor(this);

    wxBoxSizer*     sizer   = T100NEW wxBoxSizer(wxVERTICAL);

    sizer->Add(m_editor, 1, wxALL|wxEXPAND, 5);

    SetSizer(sizer);
    sizer->Fit(this);
    sizer->SetSizeHints(this);
}

T100VOID T100EditorPack::uninit()
{
    T100SAFE_DELETE(m_editor);
}

T100VOID T100EditorPack::SetEditor(T100Editor* editor)
{
    m_editor    = editor;
}

T100Editor* T100EditorPack::GetEditor()
{
    return m_editor;
}
