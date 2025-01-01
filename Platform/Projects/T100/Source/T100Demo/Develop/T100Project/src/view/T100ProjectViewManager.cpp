#include "T100ProjectViewManager.h"

#include "T100ProjectTextDocument.h"
#include "T100ProjectTextView.h"

T100ProjectViewManager::T100ProjectViewManager()
{
    //ctor
    create();
}

T100ProjectViewManager::~T100ProjectViewManager()
{
    //dtor
    destroy();
}

T100VOID T100ProjectViewManager::create()
{
    m_aui   = T100NEW wxAuiManager();
    m_doc   = T100NEW wxDocManager();

    init();
}

T100VOID T100ProjectViewManager::destroy()
{
    m_aui->UnInit();

    T100SAFE_DELETE m_doc;
    T100SAFE_DELETE m_aui;
}

wxAuiManager* T100ProjectViewManager::getAuiManager()
{
    return m_aui;
}

wxDocManager* T100ProjectViewManager::getDocManager()
{
    return m_doc;
}

T100VOID T100ProjectViewManager::init()
{
    new wxDocTemplate(m_doc, "Text", "*.txt;*.text", "", "txt;text",
                      "Text Doc", "Text View",
                      CLASSINFO(T100ProjectTextDocument), CLASSINFO(T100ProjectTextView));
}


