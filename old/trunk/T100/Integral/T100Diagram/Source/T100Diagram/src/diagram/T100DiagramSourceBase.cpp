#include "T100DiagramSourceBase.h"

#include "T100AllSourceV1.h"
#include "T100ElementSource.h"
#include "T100DiagramSource.h"
#include "T100DiagramTransducerTarget.h"

T100DiagramSourceBase::T100DiagramSourceBase() :
    T100DiagramTransducerSource()
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
    source.SetTarget((T100TransducerTarget*)m_target);

    return source.Deserialize();
}

T100BOOL T100DiagramSourceBase::LoadElements()
{
    T100BOOL        result          = T100FALSE;
    T100DIAGRAM_ELEMENT_VECTOR*     elements            = T100NULL;

    elements = m_diagram->GetElements();
    if(elements){
        T100ElementSource           source;
        T100ElementSourceBase*      current             = T100NULL;

        source.SetTarget((T100TransducerTarget*)m_target);
        do{
            result = source.Deserialize();
            if(!result){
                if(m_target->Eof()){
                    return T100TRUE;
                }
                return T100FALSE;
            }

            current = GetElementSource(source.GetType());
            if(!current)return T100FALSE;

            current->SetTarget((T100TransducerTarget*)m_target);
            result = current->Deserialize();
            if(!result)return T100FALSE;

            T100ElementBase*    element     = current->GetElement();
            element->SetIndex(source.GetIndex());
            elements->push_back(element);

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
    source.SetTarget((T100TransducerTarget*)m_target);

    return source.Serialize();
}

T100BOOL T100DiagramSourceBase::SaveElements()
{
    T100BOOL        result          = T100FALSE;
    T100DIAGRAM_ELEMENT_VECTOR*     elements        = T100NULL;

    elements = m_diagram->GetElements();
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

    source.SetElement(element);
    source.SetTarget((T100TransducerTarget*)m_target);

    result = source.Serialize();
    if(!result)return T100FALSE;

    T100ElementSourceBase*      current         = T100NULL;

    current = GetElementSource(element->GetType());
    if(!current)return T100FALSE;

    current->SetElement(element);
    current->SetTarget((T100TransducerTarget*)m_target);
    result = current->Serialize();

    return result;
}

T100ElementSourceBase* T100DiagramSourceBase::GetElementSource(T100UINT type)
{
    T100ElementSourceBase*      result          = T100NULL;

    switch(type){
    case T100ELEMENT_LIGATURE:
        {
            result = T100NEW T100ElementLigatureSource(T100NULL);
        }
        break;
    case T100ELEMENT_SINGLE_TRACK:
        {
            result = T100NEW T100ElementSingleTrackSource(T100NULL);
        }
        break;
    case T100ELEMENT_BIDIRECTION:
        {
            result = T100NEW T100ElementBidirectionSource(T100NULL);
        }
        break;
    case T100ELEMENT_MODULE:
        {
            result = T100NEW T100ElementModuleSource(T100NULL);
        }
        break;
    }

    return result;
}
