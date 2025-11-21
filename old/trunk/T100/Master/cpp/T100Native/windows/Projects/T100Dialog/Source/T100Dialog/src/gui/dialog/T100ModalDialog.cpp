#include "T100ModalDialog.h"

namespace T100DIALOG{

T100ModalDialog::T100ModalDialog() :
    T100SelfLoopWindow()
{
    //ctor
}

T100ModalDialog::~T100ModalDialog()
{
    //dtor
}

T100VOID T100ModalDialog::Create(T100SelfLoopWindow* parent)
{
    T100SelfLoopWindow::Create(parent);
}

}
