#ifndef T100DIAGRAMV1_H
#define T100DIAGRAMV1_H

#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"
#include "T100DiagramBase.h"
#include "T100ElementTransducerSource.h"

#include "T100DiagramInfoV1.h"

namespace T100Painter{

class T100DiagramV1 : public T100DiagramBase
{
    public:
        T100DiagramV1();
        virtual ~T100DiagramV1();

        T100BOOL            Load(T100Library::T100BufferedFileReader*, T100PAINTER_ELEMENT_VECTOR*);

        T100BOOL            Save(T100Library::T100BufferedFileWriter*, T100PAINTER_ELEMENT_VECTOR*);

        ///
        T100BOOL            Save(T100Library::T100BufferedFileWriter*, T100DiagramInfoV1*);

    protected:
        T100ElementTransducerSource&        getSource(T100ElementBase*);

    private:
};

}

#endif // T100DIAGRAMV1_H
