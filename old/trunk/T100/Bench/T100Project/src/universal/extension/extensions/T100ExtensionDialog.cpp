#include "T100ExtensionDialog.h"

#include "T100ProjectCreateDialog.h"

T100ExtensionDialog::T100ExtensionDialog() :
    T100Extension()
{
    //ctor
}

T100ExtensionDialog::~T100ExtensionDialog()
{
    //dtor
}

T100VOID T100ExtensionDialog::SetDialog(wxDialog* dialog)
{
    m_dialog    = dialog;
}

wxDialog* T100ExtensionDialog::GetDialog()
{
    if(!m_dialog){
        m_dialog    = (T100ProjectCreateDialog*)(m_function.Handler->*(m_function.Method))(T100NULL);
    }
    return m_dialog;
}

T100VOID T100ExtensionDialog::SetHandler(T100Class* handler, T100CLASS_METHOD method)
{
    m_function.Handler      = handler;
    m_function.Method       = method;
}
