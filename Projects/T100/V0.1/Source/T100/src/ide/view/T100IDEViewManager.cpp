#include "T100IDEViewManager.h"

#include "T100MDITextDocument.h"
#include "T100MDITextView.h"

namespace T100IDE{

T100IDEViewManager::T100IDEViewManager()
{
    //ctor
    create();
}

T100IDEViewManager::~T100IDEViewManager()
{
    //dtor
    destroy();
}

T100VOID T100IDEViewManager::create()
{
    m_aui   = T100NEW wxAuiManager();
    m_doc   = T100NEW wxDocManager();
}

T100VOID T100IDEViewManager::destroy()
{
    T100SAFE_DELETE(m_doc);
    T100SAFE_DELETE(m_aui);
}

wxAuiManager* T100IDEViewManager::getAuiManager()
{
    return m_aui;
}

wxDocManager* T100IDEViewManager::getDocManager()
{
    return m_doc;
}

}
