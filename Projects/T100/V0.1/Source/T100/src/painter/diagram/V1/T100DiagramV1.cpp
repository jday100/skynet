#include "T100DiagramV1.h"

#include "T100AllSourceV1.h"
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

T100BOOL T100DiagramV1::Load(T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL            result;
    T100ElementTransducer               trans;
    T100ElementTransducerSource         source;

    do{

    }while(T100TRUE);

    return T100TRUE;
}

T100BOOL T100DiagramV1::Save(T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100ElementTransducer               trans;

    for(T100ElementBase* element : *elements){

    }

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

}
