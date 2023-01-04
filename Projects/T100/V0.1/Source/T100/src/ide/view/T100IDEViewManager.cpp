#include "T100IDEViewManager.h"

#include "T100MDITextDocument.h"
#include "T100MDITextView.h"

#include "T100MDIPaintDocument.h"
#include "T100MDIPaintView.h"


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

    init();
}

T100VOID T100IDEViewManager::destroy()
{
    m_aui->UnInit();

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

T100VOID T100IDEViewManager::init()
{
    new wxDocTemplate(m_doc, "Text", "*.txt;*.text", "", "txt;text",
                      "Text Doc", "Text View",
                      CLASSINFO(T100MDITextDocument), CLASSINFO(T100MDITextView));

    new wxDocTemplate(m_doc, "Paint", "*.cht;*.chart", "", "cht;chart",
                      "Paint Doc", "Paint View",
                      CLASSINFO(T100MDIPaintDocument), CLASSINFO(T100MDIPaintView));

}

}
