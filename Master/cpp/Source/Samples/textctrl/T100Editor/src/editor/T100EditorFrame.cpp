#include "T100EditorFrame.h"

#include "gui/T100FillLayout.h"

T100EditorFrame::T100EditorFrame() :
    T100Frame()
{
    //ctor
}

T100EditorFrame::~T100EditorFrame()
{
    //dtor
}

T100VOID T100EditorFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    T100TextCtrl*   editor  = T100NEW T100TextCtrl();

    editor->Create(app, this);

    editor->Show();

    T100FillLayout* layout = T100NEW T100FillLayout();

    SetLayout(layout);
}
