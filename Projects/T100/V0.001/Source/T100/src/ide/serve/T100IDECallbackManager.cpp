#include "T100IDECallbackManager.h"

#include "T100IDECallbackProject.h"
#include "T100IDECallbackFile.h"
#include "T100IDECallbackEdit.h"
#include "T100IDECallbackView.h"
#include "T100IDECallbackSearch.h"
#include "T100IDECallbackBuild.h"
#include "T100IDECallbackDebug.h"
#include "T100IDECallbackSetup.h"
#include "T100IDECallbackHelp.h"


T100IDECallbackManager::T100IDECallbackManager()
{
    //ctor
}

T100IDECallbackManager::~T100IDECallbackManager()
{
    //dtor
}

T100BOOL T100IDECallbackManager::init(T100IDEStore* store, T100IDEServe* serve, T100IDEView* view)
{
    if(!store)return T100FALSE;
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_store     = store;
    m_serve     = serve;
    m_view      = view;

    T100IDECallbackProject::init(store, serve, view);
    T100IDECallbackFile::init(store, serve, view);
    T100IDECallbackEdit::init(store, serve, view);
    T100IDECallbackView::init(store, serve, view);
    T100IDECallbackSearch::init(store, serve, view);
    T100IDECallbackBuild::init(store, serve, view);
    T100IDECallbackDebug::init(store, serve, view);
    T100IDECallbackSetup::init(store, serve, view);
    T100IDECallbackHelp::init(store, serve, view);

    return T100TRUE;
}
