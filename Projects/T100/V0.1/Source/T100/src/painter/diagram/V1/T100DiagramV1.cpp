#include "T100DiagramV1.h"

#include "T100AllSourceV1.h"

#include "T100DiagramSource.h"
#include "T100ElementSource.h"
#include "T100DiagramTransducer.h"
#include "T100DiagramV1Source.h"

#include "T100ElementTransducer.h"

namespace T100Painter{

T100DiagramV1::T100DiagramV1()
    :T100DiagramBase()
{
    //ctor
}

T100DiagramV1::~T100DiagramV1()
{
    //dtor
}

T100BOOL T100DiagramV1::Load(T100Library::T100BufferedFileReader* reader, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL            result;
    T100DiagramTransducer               trans;
    T100DiagramTransducerTarget         target(reader);

    T100DiagramSource                   source;

    result = trans.deserialize(source, target);
    if(!result)return T100FALSE;

    do{
        result = trans.deserialize(source, target);
        if(!result)return T100FALSE;
    }while(T100TRUE);

    return T100TRUE;
}

T100BOOL T100DiagramV1::Save(T100Library::T100BufferedFileWriter* writer, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100ElementTransducer               trans;
    T100ElementTransducerTarget         target(writer);

    for(T100ElementBase* element : *elements){
        T100ElementTransducerSource& source = getSource(element);
        trans.serialize(source, target);
    }

    return T100TRUE;
}

T100ElementTransducerSource& T100DiagramV1::getSource(T100ElementBase* element)
{
    return *(T100NEW T100ElementCircleSource((T100ElementCircle*)element));
}

T100BOOL T100DiagramV1::Save(T100Library::T100BufferedFileWriter* writer, T100DiagramInfoV1* info)
{
    T100BOOL            result          = T100FALSE;
    T100DiagramTransducer               trans;
    T100DiagramTransducerTarget         target(writer);
    T100DiagramV1Source                 source;

    source.SetDiagramInfo(info);
    result = trans.serialize(source, target);

    return result;
}

}
