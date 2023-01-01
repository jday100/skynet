#include "T100Diagram.h"

#include "T100DiagramTransducer.h"
#include "T100DiagramV1Source.h"

namespace T100Painter{

T100Diagram::T100Diagram()
    :T100DiagramBase()
{
    //ctor
}

T100Diagram::~T100Diagram()
{
    //dtor
}

T100DiagramSourceBase* T100Diagram::getDiagramSource(T100DiagramSourceBase& diagram)
{
    return T100NEW T100DiagramV1Source();
}

T100BOOL T100Diagram::Load(T100Library::T100BufferedFileReader* reader, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL            result;
    T100DiagramTransducer               trans;
    T100DiagramTransducerTarget         target(reader);

    T100DiagramSourceBase               source;
    T100DiagramSourceBase*              current             = T100NULL;

    result  = trans.deserialize(source, target);
    if(!result)return T100FALSE;

    current = getDiagramSource(source);
    if(current){
        result = trans.deserialize(*current, target);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Diagram::Save(T100Library::T100BufferedFileWriter* writer, T100PAINTER_ELEMENT_VECTOR* elements)
{
    return T100FALSE;
}

}
