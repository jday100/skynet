#ifndef T100DIAGRAMV1_H
#define T100DIAGRAMV1_H

#include "T100FileReader.h"
#include "T100FileWriter.h"
#include "T100DiagramBase.h"


namespace T100Painter{

class T100DiagramV1 : public T100DiagramBase
{
    public:
        T100DiagramV1();
        virtual ~T100DiagramV1();

        T100BOOL            Load(T100PAINTER_ELEMENT_VECTOR*);

        T100BOOL            Save(T100Library::T100FileWriter*);

    protected:

    private:
};

}

#endif // T100DIAGRAMV1_H
