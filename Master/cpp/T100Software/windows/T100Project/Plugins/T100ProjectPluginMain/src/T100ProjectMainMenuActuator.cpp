#include "T100ProjectMainMenuActuator.h"

#include "T100ProjectApplication.h"
#include "skeletal/T100ProjectInvoking.h"
#include "view/dialog/T100ProjectNewDialog.h"

T100ProjectMainMenuActuator::T100ProjectMainMenuActuator(T100EventHandler* handler) :
    T100EventHandler(handler)
{
    //ctor
}

T100ProjectMainMenuActuator::~T100ProjectMainMenuActuator()
{
    //dtor
}

T100VOID T100ProjectMainMenuActuator::OnNew(T100MenuEvent& event)
{
    //T100ProjectInvoking::New();
    T100Frame*                  frame;
    T100ProjectNewDialog        dialog;

    frame   = T100ProjectInvoking::GetApplication()->GetFrame();

    if(!frame){
        return;
    }

    dialog.Create(frame);

    dialog.Show();
}

T100VOID T100ProjectMainMenuActuator::OnOpen(T100MenuEvent& event)
{
    T100ProjectInvoking::Open();
}

T100VOID T100ProjectMainMenuActuator::OnClose(T100MenuEvent& event)
{
    T100ProjectInvoking::Close();
}

T100VOID T100ProjectMainMenuActuator::OnSave(T100MenuEvent& event)
{
    T100ProjectInvoking::Save();
}

T100VOID T100ProjectMainMenuActuator::OnSaveAs(T100MenuEvent& event)
{
    T100ProjectInvoking::SaveAs();
}

T100VOID T100ProjectMainMenuActuator::OnQuit(T100MenuEvent& event)
{
    T100ProjectInvoking::Quit();
}

T100VOID T100ProjectMainMenuActuator::OnUndo(T100MenuEvent& event)
{
    T100ProjectInvoking::Undo();
}

T100VOID T100ProjectMainMenuActuator::OnRedo(T100MenuEvent& event)
{
    T100ProjectInvoking::Redo();
}

T100VOID T100ProjectMainMenuActuator::OnCut(T100MenuEvent& event)
{
    T100ProjectInvoking::Cut();
}

T100VOID T100ProjectMainMenuActuator::OnCopy(T100MenuEvent& event)
{
    T100ProjectInvoking::Copy();
}

T100VOID T100ProjectMainMenuActuator::OnPaste(T100MenuEvent& event)
{
    T100ProjectInvoking::Paste();
}

T100VOID T100ProjectMainMenuActuator::OnFind(T100MenuEvent& event)
{
    T100ProjectInvoking::Find();
}

T100VOID T100ProjectMainMenuActuator::OnReplace(T100MenuEvent& event)
{
    T100ProjectInvoking::Replace();
}

T100VOID T100ProjectMainMenuActuator::OnAbout(T100MenuEvent& event)
{
    T100ProjectInvoking::About();
}
