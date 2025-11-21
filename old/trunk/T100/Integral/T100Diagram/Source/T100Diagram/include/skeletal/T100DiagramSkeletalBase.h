#ifndef T100DIAGRAMSKELETALBASE_H
#define T100DIAGRAMSKELETALBASE_H

#include "T100DiagramView.h"
#include "T100DiagramServe.h"
#include "T100DiagramStore.h"

class T100DiagramSkeletalBase
{
    public:
        T100DiagramSkeletalBase();
        virtual ~T100DiagramSkeletalBase();

        T100BOOL                    FileCreate();
        T100BOOL                    FileOpen();
        T100BOOL                    FileClose();

        T100BOOL                    FileSave();
        T100BOOL                    FileSaveAs();

        T100BOOL                    FileQuit();

    protected:
        T100DiagramView*            m_view          = T100NULL;
        T100DiagramServe*           m_serve         = T100NULL;
        T100DiagramStore*           m_store         = T100NULL;

    private:
};

#endif // T100DIAGRAMSKELETALBASE_H
