#ifndef T100PROJECTSERVE_H
#define T100PROJECTSERVE_H

#include <atomic>
#include "T100String.h"
#include "T100MansionInfo.h"
#include "T100ProjectDrawer.h"

namespace T100PROJECT{

class T100ProjectServe
{
    public:
        T100ProjectServe();
        virtual ~T100ProjectServe();

        T100BOOL                opened();

        T100BOOL                NewFile(T100STRING&, T100MansionInfo*&);
        T100BOOL                OpenFile(T100STRING&, T100MansionInfo*);
        T100BOOL                CloseFile();
        T100BOOL                Save();
        T100BOOL                SaveAs();
        T100BOOL                Quit();

        T100MansionInfo*        getCurrent();

        T100ProjectDrawer*      getProjectDrawer();

    public:
        T100BOOL                SaveFile(T100STRING);
        T100BOOL                LoadFile(T100STRING);

        T100VOID                setModified(T100BOOL);
        T100BOOL                IsModified();
        T100VOID                DiscardEdits();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        std::atomic_bool        m_opened;
        std::atomic_bool        m_modified;

        T100MansionInfo*        m_current           = T100NULL;
        T100ProjectDrawer*      m_project_drawer    = T100NULL;
};

}

#endif // T100PROJECTSERVE_H
