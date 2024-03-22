#include "T100DiagramDrawer.h"

#include "T100DiagramTransducer.h"

T100DiagramDrawer::T100DiagramDrawer()
{
    //ctor
}

T100DiagramDrawer::~T100DiagramDrawer()
{
    //dtor
}

T100BOOL T100DiagramDrawer::Load(T100FileBufferedReader* reader, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL                            result;

    T100DiagramTransducer               transducer;
    T100DiagramTransducerTarget         target(reader);

    T100DiagramTransducerSource         source;

    result  = transducer.deserialize(source, target);
    if(!result)return T100FALSE;

    return result;
}

T100BOOL T100DiagramDrawer::Save(T100FileBufferedWriter* writer, T100PAINTER_ELEMENT_VECTOR* elements)
{

}

