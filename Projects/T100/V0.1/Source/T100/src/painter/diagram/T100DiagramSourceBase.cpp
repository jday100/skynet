#include "T100DiagramSourceBase.h"

#include "T100ElementCommon.h"
#include "T100AllSourceV1.h"
#include "T100DiagramSource.h"
#include "T100ElementSource.h"
#include "T100TransducerTarget.h"
#include "T100DiagramTransducerTarget.h"

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

T100DiagramInfo* T100DiagramSourceBase::GetDiagramInfo()
{
    return m_diagram;
}

T100BOOL T100DiagramSourceBase::LoadDiagramHead()
{
    T100DiagramSource       source;

    source.SetDiagramInfo(m_diagram);
    source.setTarget((T100Library::T100TransducerTarget*)m_target);

    return source.deserialize();
}

T100BOOL T100DiagramSourceBase::LoadElements()
{
    T100BOOL        result          = T100FALSE;
    T100PAINTER_ELEMENT_VECTOR*     elements            = T100NULL;

    elements = m_diagram->getElements();
    if(elements){
        T100ElementSource           source;
        T100ElementSourceBase*      current             = T100NULL;

        source.setTarget((T100Library::T100TransducerTarget*)m_target);
        do{
            result = source.deserialize();
            if(!result){
                if(m_target->eof()){
                    return T100TRUE;
                }
                return T100FALSE;
            }

            current = getElementSource(source.getType());
            if(!current)return T100FALSE;

            current->setTarget((T100Library::T100TransducerTarget*)m_target);
            result = current->deserialize();
            if(!result)return T100FALSE;

            elements->append(current->getElement());

        }while(T100TRUE);
    }
    return result;
}

T100BOOL T100DiagramSourceBase::LoadElement(T100ElementBase*& element)
{
    T100BOOL                result          = T100FALSE;

    return result;
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

    T100ElementSourceBase*      current         = T100NULL;

    current = getElementSource(element->getType());
    if(!current)return T100FALSE;

    current->setElement(element);
    current->setTarget((T100Library::T100TransducerTarget*)m_target);
    result = current->serialize();

    return result;
}

T100ElementSourceBase* T100DiagramSourceBase::getElementSource(T100WORD type)
{
    T100ElementSourceBase*      result          = T100NULL;

    switch(type){
    case T100ELEMENT_CIRCLE:
        {
            result = T100NEW T100ElementCircleSource(T100NULL);
        }
        break;
    case T100ELEMENT_RECTANGLE:
        {
            result = T100NEW T100ElementRectangleSource(T100NULL);
        }
        break;
    }

    return result;
}

}
