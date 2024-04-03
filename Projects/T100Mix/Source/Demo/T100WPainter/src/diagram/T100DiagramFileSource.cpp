#include "T100DiagramFileSource.h"

#include "T100DiagramTransducerTarget.h"

T100DiagramFileSource::T100DiagramFileSource(T100DiagramInfo* diagram)
    :T100DiagramTransducerSource(), m_diagram(diagram)
{
    //ctor
}

T100DiagramFileSource::~T100DiagramFileSource()
{
    //dtor
}

T100WORD T100DiagramFileSource::getSign()
{
    return m_sign;
}

T100WORD T100DiagramFileSource::getType()
{
    return m_type;
}

T100WORD T100DiagramFileSource::getVersion()
{
    return m_version;
}

T100BOOL T100DiagramFileSource::serialize()
{
    T100BOOL                result;
    T100DIAGRAM_HEAD*       head            = T100NULL;

    head    = m_diagram->getHead();
    if(head){
        result  = m_target->setWORD(head->COMMON.SIGN);
        if(!result)return T100FALSE;

        result  = m_target->setWORD(head->TYPE);
        if(!result)return T100FALSE;

        result  = m_target->setWORD(head->VERSION);
    }

    return result;
}

T100BOOL T100DiagramFileSource::deserialize()
{
    T100BOOL            result;

    result  = m_target->getWORD(m_sign);

    result  = m_target->getWORD(m_type);

    result  = m_target->getWORD(m_version);

    return result;
}

T100BOOL T100DiagramFileSource::LoadDiagramFileHead()
{
    T100DiagramFileSource           source;

    source.SetDiagramInfo(m_diagram);
    source.setTarget(m_target);

    return source.deserialize();
}

T100BOOL T100DiagramFileSource::LoadElements()
{
    T100BOOL                            result              = T100FALSE;
    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;

    elements    = m_diagram->getElements();
    if(elements){
        T100ElementSource           source;
        T100ElementBaseSource*      current         = T100NULL;

        source.setTarget(m_target);
        do{
            result  = source.deserialize();
            if(!result){
                if(m_target->eof()){
                    return T100TRUE;
                }
                return T100FALSE;
            }

            current = getElementSource(source.getType());
            if(!current)return T100FALSE;

            current->setTarget(m_target);
            result  = current->deserialize();
            if(!result)return T100FALSE;

            elements->append(current->getElements());
        }while(T100TRUE);
    }
    return result;
}

T100BOOL T100DiagramFileSource::LoadElement(T100ElementBase*& element)
{
    return T100FALSE;
}

T100DiagramFileSource::SaveDiagramFileHead()
{
    T100DiagramFileSource           source;

    source.SetDiagramInfo(m_diagram);
    source.setTarget(m_target);

    return source.serialize();
}

T100BOOL T100DiagramFileSource::SaveElements()
{
    T100BOOL                            result              = T100FALSE;
    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;

    elements    = m_diagram->getElements();
    if(elements){
        for(T100ElementBase* element : *elements){
            result  = SaveElement(element);
            if(!result)return T100FALSE;
        }
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramFileSource::SaveElement(T100ElementBase* element)
{
    T100BOOL                    result          = T100FALSE;
    T100ElementBaseSource       source;

    source.setElement(element);
    source.setTarget(m_target);

    result  = source.serialize();
    if(!result)return T100FALSE;

    T100ElementBaseSource*      current         = T100NULL;

    current = getElementSource(element->getType());
    if(!current)return T100FALSE;

    current->setElement(element);
    current->setTarget(m_target);
    result  = current->serialize();

    return result;
}

T100ElementBaseSource* T100DiagramFileSource::getElementSource(T100WORD type)
{
    T100ElementBaseSource*          result          = T100NULL;

    switch(type){
    case T100ELEMENT_GRAPHICS_CIRCLE:
        {
            result  = T100NEW T100ElementCircleSource(T100NULL);
        }
        break;
    }
    return result;
}
