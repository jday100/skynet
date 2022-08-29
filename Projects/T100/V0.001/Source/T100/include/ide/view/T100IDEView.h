#ifndef T100IDEVIEW_H
#define T100IDEVIEW_H

#include "IView.h"
#include "T100IDEMenu.h"
#include "T100IDEStatusBar.h"
#include "T100IDEFrameNew.h"
#include "T100IDEViewFile.h"
#include "T100IDEViewEdit.h"
#include "T100IDEViewView.h"
#include "T100IDEViewSearch.h"
#include "T100IDEViewProject.h"
#include "T100IDEViewBuild.h"
#include "T100IDEViewDebug.h"
#include "T100IDEViewSetup.h"
#include "T100IDEViewHelp.h"
#include "T100IDEViewManager.h"


class T100IDEView : public IView
{
    public:
        T100IDEView();
        virtual ~T100IDEView();

        T100VOID                create();

        T100IDEViewManager*     getManager();

        T100VOID                setFrame(T100IDEFrameNew*);
        T100IDEFrameNew*        getFrame();

        T100IDEViewFile*        getFile();
        T100IDEViewEdit*        getEdit();
        T100IDEViewView*        getView();
        T100IDEViewSearch*      getSearch();
        T100IDEViewProject*     getProject();
        T100IDEViewBuild*       getBuild();
        T100IDEViewDebug*       getDebug();
        T100IDEViewSetup*       getSetup();
        T100IDEViewHelp*        getHelp();


        T100BOOL                show();

        T100BOOL                start();

        T100BOOL                quit();

    protected:
        T100VOID                destroy();

    private:
        T100IDEFrameNew*        m_frame         = T100NULL;
        T100IDEMenu*            m_menu          = T100NULL;
        T100IDEStatusBar*       m_status_bar    = T100NULL;

        T100IDEViewFile*        m_file          = T100NULL;
        T100IDEViewEdit*        m_edit          = T100NULL;
        T100IDEViewView*        m_view          = T100NULL;
        T100IDEViewSearch*      m_search        = T100NULL;
        T100IDEViewProject*     m_project       = T100NULL;
        T100IDEViewBuild*       m_build         = T100NULL;
        T100IDEViewDebug*       m_debug         = T100NULL;
        T100IDEViewSetup*       m_setup         = T100NULL;
        T100IDEViewHelp*        m_help          = T100NULL;

        T100IDEViewManager*     m_manager       = T100NULL;

};

#endif // T100IDEVIEW_H
