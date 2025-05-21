#include "T100FontDialog.h"

T100FontDialog::T100FontDialog(T100SelfLoopWindow* parent) :
    T100Dialog()
{
    //ctor
    Init();
}

T100FontDialog::~T100FontDialog()
{
    //dtor
}

T100VOID T100FontDialog::Init()
{
    CHOOSEFONT      cf;

    ChooseFont(&cf);
}
