#ifndef T100IDESERVE_H
#define T100IDESERVE_H

#include "IServe.h"
#include "T100IDEStore.h"
#include "T100IDEServeProject.h"
#include "T100IDEServeFile.h"
#include "T100IDEServeEdit.h"
#include "T100IDEServeView.h"
#include "T100IDEServeSearch.h"
#include "T100IDEServeBuild.h"
#include "T100IDEServeDebug.h"
#include "T100IDEServeSetup.h"
#include "T100IDEServeHelp.h"


class T100IDEServe : public IServe
{
    public:
        T100IDEServe();
        virtual ~T100IDEServe();

        T100VOID                setStore(T100IDEStore*);
        T100IDEStore*           getStore();

        T100IDEServeFile*       getFile();
        T100IDEServeEdit*       getEdit();
        T100IDEServeView*       getView();
        T100IDEServeSearch*     getSearch();
        T100IDEServeProject*    getProject();
        T100IDEServeBuild*      getBuild();
        T100IDEServeDebug*      getDebug();
        T100IDEServeSetup*      getSetup();
        T100IDEServeHelp*       getHelp();


    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100IDEStore*           m_store         = T100NULL;

        T100IDEServeFile*       m_file          = T100NULL;
        T100IDEServeEdit*       m_edit          = T100NULL;
        T100IDEServeView*       m_view          = T100NULL;
        T100IDEServeSearch*     m_search        = T100NULL;
        T100IDEServeProject*    m_project       = T100NULL;
        T100IDEServeBuild*      m_build         = T100NULL;
        T100IDEServeDebug*      m_debug         = T100NULL;
        T100IDEServeSetup*      m_setup         = T100NULL;
        T100IDEServeHelp*       m_help          = T100NULL;

};

#endif // T100IDESERVE_H
