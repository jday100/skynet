#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include <atomic>
#include "T100String.h"
#include "T100PainterCommon.h"
#include "T100DiagramInfo.h"

namespace T100Painter{

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100BOOL                opened();

        T100BOOL                NewFile(T100STRING&, T100DiagramInfo*&);
        T100BOOL                OpenFile(T100STRING&, T100DiagramInfo*);
        T100BOOL                CloseFile();
        T100BOOL                Save();
        T100BOOL                SaveAs();
        T100BOOL                Quit();

        T100DiagramInfo*        getCurrent();

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

        T100DiagramInfo*        m_current           = T100NULL;

        T100PAINTER_ELEMENT_VECTOR      m_elements;

};

}

#endif // T100PAINTERSERVE_H
