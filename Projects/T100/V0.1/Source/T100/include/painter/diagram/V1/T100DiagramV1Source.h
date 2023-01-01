#ifndef T100DIAGRAMV1SOURCE_H
#define T100DIAGRAMV1SOURCE_H

#include "T100DiagramSourceBase.h"
#include "T100DiagramInfoV1.h"


namespace T100Painter{

class T100DiagramV1Source : public T100DiagramSourceBase
{
    public:
        T100DiagramV1Source();
        virtual ~T100DiagramV1Source();

        T100VOID        SetDiagramInfo(T100DiagramInfoV1*);

        T100BOOL        serialize();
        T100BOOL        deserialize();

    protected:

    private:
};

}

#endif // T100DIAGRAMV1SOURCE_H
