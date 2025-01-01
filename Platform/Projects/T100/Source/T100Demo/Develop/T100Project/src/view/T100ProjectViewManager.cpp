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
    m_doc   = T100NEW wxDocManager();

    init();
}

T100VOID T100ProjectViewManager::destroy()
{

}

T100VOID T100ProjectViewManager::init()
{
    new wxDocTemplate(m_doc, "Text", "*.txt;*.text", "", "txt;text",
                      "Text Doc", "Text View",
                      CLASSINFO(T100ProjectTextDocument), CLASSINFO(T100ProjectTextView));
}

wxDocManager* T100ProjectViewManager::getDocManager()
{
    return m_doc;
}
