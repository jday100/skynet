#include "T100DiagramV1Source.h"

#include "T100DiagramTransducerTarget.h"


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
    T100BOOL        result;

    result = SaveDiagramHead();

    if(result){
        result = SaveElements();
    }
    return result;
}

T100BOOL T100DiagramV1Source::deserialize()
{
    T100BOOL        result          = T100FALSE;

    m_diagram = T100NEW T100DiagramInfoV1();
    if(m_diagram){
        m_target->reset();
        result = LoadDiagramHead();
        if(!result)return T100FALSE;

        result = LoadElements();
        if(!result){
            T100SAFE_DELETE(m_diagram);
        }
    }

    return result;
}

}
