#ifndef T100DIAGRAMSERVE_H
#define T100DIAGRAMSERVE_H

#include <atomic>
#include "T100DiagramInfo.h"
#include "T100ElementServe.h"
#include "T100PluginSourceImport.h"

class T100DiagramServe
{
    public:
        T100DiagramServe();
        virtual ~T100DiagramServe();

        T100DiagramInfo*        GetDiagramInfo();
        T100ElementServe&       GetElementServe();
        T100PluginSourceImport& GetSourceImport();

        T100BOOL                IsOpened();

        T100VOID                SetModified(T100BOOL);
        T100BOOL                IsModified();

        T100BOOL                Create();
        T100BOOL                Open(T100DiagramInfo*);
        T100BOOL                Append();

        T100BOOL                Remove();

        T100BOOL                Close();

        T100BOOL                Hit(T100INT, T100INT);

    protected:
        T100ElementServe        m_elementServe;
        std::atomic_bool        m_opened;
        std::atomic_bool        m_modified;

        T100PluginSourceImport          m_sourceImport;

    private:
        T100DiagramInfo*        m_current       = T100NULL;
};

#endif // T100DIAGRAMSERVE_H
