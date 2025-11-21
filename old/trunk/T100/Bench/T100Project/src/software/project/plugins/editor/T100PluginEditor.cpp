#include "T100PluginEditor.h"

#include "T100ExtensionCommon.h"
#include "T100ExtensionFrame.h"
#include "T100ExtensionManager.h"
#include "T100ProjectMain.h"
#include "T100PluginEditorEditorPanel.h"

T100PluginEditor::T100PluginEditor() :
    T100Plugin()
{
    //ctor
}

T100PluginEditor::~T100PluginEditor()
{
    //dtor
}

T100VOID T100PluginEditor::Init(T100ExtensionManager* manager)
{
    T100Plugin::Init(manager);

    Load();
}

T100VOID T100PluginEditor::Load()
{
    T100ExtensionFrame*     frameExtension  = dynamic_cast<T100ExtensionFrame*>(m_extensionManager->Find(T100PROJECT_VIEW_MAIN_FRAME));

    if(!frameExtension){
        return;
    }

    T100ProjectFrame*       frame       = dynamic_cast<T100ProjectFrame*>(frameExtension->GetFrame());

    if(!frame){
        return;
    }

    //T100PluginEditorEditorPanel*        panel       = T100NEW T100PluginEditorEditorPanel(frame);

}
