#ifndef T100DIAGRAMSOURCEBASE_H
#define T100DIAGRAMSOURCEBASE_H

#include "T100DiagramInfo.h"
#include "T100DiagramTransducerSource.h"
#include "T100ElementSourceBase.h"
#include "T100ElementBase.h"

namespace T100Painter{

class T100DiagramSourceBase : public T100DiagramTransducerSource
{
    public:
        T100DiagramSourceBase();
        virtual ~T100DiagramSourceBase();

        T100VOID                SetDiagramInfo(T100DiagramInfo*);
        T100DiagramInfo*        GetDiagramInfo();

    protected:
        T100DiagramInfo*        m_diagram           = T100NULL;

        T100BOOL        LoadDiagramHead();
        T100BOOL        LoadElements();
        T100BOOL        LoadElement(T100ElementBase*&);

        T100BOOL        SaveDiagramHead();
        T100BOOL        SaveElements();
        T100BOOL        SaveElement(T100ElementBase*);

        T100ElementSourceBase*      getElementSource(T100WORD);

    private:
};

}

#endif // T100DIAGRAMSOURCEBASE_H
