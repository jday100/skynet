#ifndef T100DIAGRAM_H
#define T100DIAGRAM_H

#include "T100DiagramBase.h"
#include "T100DiagramSourceBase.h"

namespace T100Painter{
class T100DiagramSource;

class T100Diagram : public T100DiagramBase
{
    public:
        T100Diagram();
        virtual ~T100Diagram();

        T100BOOL            Load(T100Library::T100BufferedFileReader*, T100DiagramInfo*&);

        ///

        T100BOOL                Load(T100Library::T100BufferedFileReader*, T100PAINTER_ELEMENT_VECTOR*);

        T100BOOL                Save(T100Library::T100BufferedFileWriter*, T100PAINTER_ELEMENT_VECTOR*);

    protected:
        T100DiagramSourceBase*          getDiagramSource(T100WORD, T100WORD);

    private:
};

}

#endif // T100DIAGRAM_H
