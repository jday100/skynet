#include "T100IDEViewManager.h"

#include <wx/object.h>

#include "T100IDEView.h"
#include "T100IDEFrameText.h"

#include "T100IDEProjectDocument.h"
#include "T100IDEProjectView.h"

#include "T100IDETextDocument.h"
#include "T100IDETextView.h"


T100IDEViewManager::T100IDEViewManager(T100IDEView* view)
    :m_view(view)
{
    //ctor
    create();
}

T100IDEViewManager::~T100IDEViewManager()
{
    //dtor
    destroy();
}

wxDocManager* T100IDEViewManager::getDocManager()
{
    return m_doc;
}

wxAuiManager* T100IDEViewManager::getAuiManager()
{
    return m_aui;
}

T100VOID T100IDEViewManager::create()
{
    m_doc       = T100NEW wxDocManager();

    m_view->setFrame(T100NEW T100IDEFrameNew(m_doc, T100NULL));

    m_aui       = T100NEW wxAuiManager(m_view->getFrame(), wxAUI_MGR_DEFAULT);

    //T100NEW wxDocTemplate(m_doc, "#docDescription", "*.txt", "", "#docExtention", "Doc", "View", CLASSINFO(T100IDEProjectDocument), CALSSINFO(T100IDEProjectView) );

    /*
    new wxDocTemplate(m_doc, "Drawing", "*.drw", "", "drw",
                      "Drawing Doc", "Drawing View",
                      CLASSINFO(T100IDEProjectDocument), CLASSINFO(T100IDEProjectView));
    */

    new wxDocTemplate(m_doc, "Text", "*.txt;*.text", "", "txt;text",
                          "Text Doc", "Text View",
                          CLASSINFO(T100IDETextDocument), CLASSINFO(T100IDETextView));

    m_aui->Update();
}

T100VOID T100IDEViewManager::destroy()
{

}

T100BOOL T100IDEViewManager::create_child(T100EditorData* data)
{
    m_doc->CreateNewDocument();

    m_aui->Update();

    return T100TRUE;


    T100IDEFrameText*   frame;

    wxDocument* doc;
    wxView*     view;

    doc     = T100NEW T100IDEProjectDocument();
    view    = T100NEW T100IDEProjectView();

    frame   = T100NEW T100IDEFrameText(doc, view, (wxDocMDIParentFrame*)m_view->getFrame(), wxID_ANY, _("d"));

    frame->load(data);

    m_aui->Update();

    return T100FALSE;
}

T100IDEFrameText* T100IDEViewManager::getCurrent()
{
    T100IDEFrameText*     current;

    current = dynamic_cast<T100IDEFrameText*>(m_view->getFrame()->GetActiveChild());

    if(current){
        return current;
    }

    return T100NULL;
}
