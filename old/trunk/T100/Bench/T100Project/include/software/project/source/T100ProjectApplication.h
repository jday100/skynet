#ifndef T100PROJECTAPPLICATION_H
#define T100PROJECTAPPLICATION_H

#include <wx/event.h>
#include "T100ProjectView.h"
#include "T100ProjectServe.h"
#include "T100ProjectStore.h"

#include "T100Class.h"
#include "T100PluginManager.h"
#include "T100ExtensionManager.h"

#include "T100ProjectCreateDialog.h"

class T100ProjectApplication : public T100Class
{
    public:
        T100ProjectApplication();
        virtual ~T100ProjectApplication();

        virtual T100VOID        Create(T100ProjectFrame*);
        virtual T100VOID        Destroy();

        virtual T100VOID        Load();

        T100VOID                SendEvent(wxCommandEvent&);

        T100VOID                Quit();

    protected:
        T100ProjectView         m_view;
        T100ProjectServe        m_serve;
        T100ProjectStore        m_store;

        T100VOID*               CreateCreateDialog(T100VOID*);

    private:
        T100PluginManager       m_pluginManager;
        T100ExtensionManager    m_extensionManager;

        T100VOID                init(T100ProjectFrame*);
        T100VOID                uninit();
};

#endif // T100PROJECTAPPLICATION_H
