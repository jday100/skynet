#include "T100Diagram.h"

#include "T100DiagramTransducer.h"
#include "T100DiagramV1Source.h"

#include "T100DiagramSource.h"

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

T100DiagramSourceBase* T100Diagram::getDiagramSource(T100WORD type, T100WORD version)
{
    return T100NEW T100DiagramV1Source();
}

T100BOOL T100Diagram::Load(T100Library::T100BufferedFileReader* reader, T100DiagramInfo*& info)
{
    T100BOOL            result          = T100FALSE;
    T100DiagramTransducer               trans;
    T100DiagramTransducerTarget         target(reader);

    T100DiagramSource                   source;
    T100DiagramSourceBase*              current             = T100NULL;

    result = trans.deserialize(source, target);
    if(!result)return T100FALSE;

    current = getDiagramSource(source.getType(), source.getVersion());
    if(current){
        current->setTarget((T100Library::T100TransducerTarget*)&target);
        result = trans.deserialize(*current, target);
        if(result){
            info = current->GetDiagramInfo();
        }
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Diagram::Load(T100Library::T100BufferedFileReader* reader, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL            result;
    T100DiagramTransducer               trans;
    T100DiagramTransducerTarget         target(reader);

    T100DiagramSource                   source;
    T100DiagramSourceBase*              current             = T100NULL;

    result  = trans.deserialize(source, target);
    if(!result)return T100FALSE;

    current = getDiagramSource(source.getType(), source.getVersion());
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
