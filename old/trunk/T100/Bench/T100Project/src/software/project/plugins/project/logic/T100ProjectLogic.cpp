#include "T100ProjectLogic.h"

#include <wx/dialog.h>
#include "T100ExtensionDialog.h"
#include "T100PluginProject.h"
#include "T100ExtensionManager.h"
#include "T100ExtensionCommon.h"

#include "T100ProjectInfo.h"

T100ProjectLogic::T100ProjectLogic(T100PluginProject* plugin) :
    m_plugin(plugin)
{
    //ctor
}

T100ProjectLogic::~T100ProjectLogic()
{
    //dtor
}

T100VOID T100ProjectLogic::Create()
{
    T100ExtensionDialog*    dialogExtension  = dynamic_cast<T100ExtensionDialog*>(m_plugin->GetExtensionManager()->Find(T100PROJECT_VIEW_PROJECT_DIALOG_CREATE));

    if(!dialogExtension){
        return;
    }

    wxDialog*   dialog      = dialogExtension->GetDialog();

    dialog->Show();

    T100UINT            type        = 1;
    T100ProjectInfo     info;
    m_plugin->GetServe()->GetManager()->Create(1, info);

    m_plugin->GetStore()->Create(info);

    m_plugin->GetView()->Append(info);
}
