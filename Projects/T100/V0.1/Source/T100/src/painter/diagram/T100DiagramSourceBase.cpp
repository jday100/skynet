#include "T100DiagramSourceBase.h"

#include "T100ElementCommon.h"
#include "T100AllSourceV1.h"
#include "T100DiagramSource.h"
#include "T100ElementSource.h"
#include "T100TransducerTarget.h"

namespace T100Painter{

T100DiagramSourceBase::T100DiagramSourceBase()
    :T100DiagramTransducerSource()
{
    //ctor
}

T100DiagramSourceBase::~T100DiagramSourceBase()
{
    //dtor
}

T100VOID T100DiagramSourceBase::SetDiagramInfo(T100DiagramInfo* diagram)
{
    m_diagram = diagram;
}

T100BOOL T100DiagramSourceBase::SaveDiagramHead()
{
    T100DiagramSource       source;

    source.SetDiagramInfo(m_diagram);
    source.setTarget((T100Library::T100TransducerTarget*)m_target);

    return source.serialize();
}

T100BOOL T100DiagramSourceBase::SaveElements()
{
    T100BOOL        result          = T100FALSE;
    T100PAINTER_ELEMENT_VECTOR*     elements        = T100NULL;

    elements = m_diagram->getElements();
    if(elements){
        for(T100ElementBase* element : *elements){
            result = SaveElement(element);
            if(!result)return T100FALSE;
        }
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramSourceBase::SaveElement(T100ElementBase* element)
{
    T100BOOL                result          = T100FALSE;
    T100ElementSource       source;

    source.setElement(element);
    source.setTarget((T100Library::T100TransducerTarget*)m_target);

    result = source.serialize();
    if(!result)return T100FALSE;

    T100ElementSourceBase*      base        = T100NULL;

    base = getElementSource(element);
    if(!base)return T100FALSE;

    base->setTarget((T100Library::T100TransducerTarget*)m_target);
    result = base->serialize();

    return result;
}

T100ElementSourceBase* T100DiagramSourceBase::getElementSource(T100ElementBase* element)
{
    T100ElementSourceBase*      result          = T100NULL;

    switch(element->getType()){
    case T100ELEMENT_CIRCLE:
        {
            result = T100NEW T100ElementCircleSource((T100ElementCircle*)element);
            result->setElement(element);
        }
        break;
    }

    return result;
}

}
