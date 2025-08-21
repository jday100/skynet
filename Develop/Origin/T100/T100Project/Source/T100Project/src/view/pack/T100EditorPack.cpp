#include "T100EditorPack.h"

T100EditorPack::T100EditorPack(wxWindow* parent) :
    T100Pack(parent)
{
    //ctor
}

T100EditorPack::~T100EditorPack()
{
    //dtor
}

T100VOID T100EditorPack::SetEditor(T100Editor* editor)
{
    m_editor        = editor;
}

T100Editor* T100EditorPack::GetEditor()
{
    return m_editor;
}
