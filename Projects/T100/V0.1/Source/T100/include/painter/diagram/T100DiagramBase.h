#ifndef T100DIAGRAMBASE_H
#define T100DIAGRAMBASE_H

#include "T100PainterCommon.h"
#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"

namespace T100Painter{

class T100DiagramBase
{
    public:
        T100DiagramBase();
        virtual ~T100DiagramBase();

        virtual T100BOOL            Load(T100Library::T100BufferedFileReader*, T100PAINTER_ELEMENT_VECTOR*) = 0;

        virtual T100BOOL            Save(T100Library::T100BufferedFileWriter*, T100PAINTER_ELEMENT_VECTOR*) = 0;

    protected:

    private:
};

}

#endif // T100DIAGRAMBASE_H
