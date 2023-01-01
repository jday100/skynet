#include "T100DiagramV1Source.h"


namespace T100Painter{

T100DiagramV1Source::T100DiagramV1Source()
    :T100DiagramSourceBase()
{
    //ctor
}

T100DiagramV1Source::~T100DiagramV1Source()
{
    //dtor
}

T100VOID T100DiagramV1Source::SetDiagramInfo(T100DiagramInfoV1* diagram)
{
    m_diagram = diagram;
}

T100BOOL T100DiagramV1Source::serialize()
{
    T100BOOL            result;

    result = SaveDiagramHead();

    if(result){
        result = SaveElements();
    }
    return result;
}

T100BOOL T100DiagramV1Source::deserialize()
{

}

}
