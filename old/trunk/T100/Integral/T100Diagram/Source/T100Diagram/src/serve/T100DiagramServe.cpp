#include "T100DiagramServe.h"

#include "T100DiagramInfoV1.h"
#include "T100AllElements.h"

T100DiagramServe::T100DiagramServe() :
    m_elementServe()
{
    //ctor
    m_opened        = T100FALSE;
    m_modified      = T100FALSE;
}

T100DiagramServe::~T100DiagramServe()
{
    //dtor
}

T100DiagramInfo* T100DiagramServe::GetDiagramInfo()
{
    return m_current;
}

T100ElementServe& T100DiagramServe::GetElementServe()
{
    return m_elementServe;
}

T100PluginSourceImport& T100DiagramServe::GetSourceImport()
{
    return m_sourceImport;
}

T100BOOL T100DiagramServe::IsOpened()
{
    return m_opened;
}

T100VOID T100DiagramServe::SetModified(T100BOOL flag)
{
    m_modified  = flag;
}

T100BOOL T100DiagramServe::IsModified()
{
    return m_modified;
}

T100BOOL T100DiagramServe::Create()
{
    m_current   = T100NEW T100DiagramInfoV1();
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100BOOL T100DiagramServe::Open(T100DiagramInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    m_elementServe.Load(info->GetElements());

    if(info->GetCanvas()->WIDTH < m_elementServe.GetWidth()){
        info->GetCanvas()->WIDTH = m_elementServe.GetWidth();
    }

    if(info->GetCanvas()->HEIGHT < m_elementServe.GetHeight()){
        info->GetCanvas()->HEIGHT = m_elementServe.GetHeight();
    }

    for(T100ElementBase* element : *info->GetElements()){
        switch(element->GetType()){
        case T100ELEMENT_LIGATURE:
            {
                T100ElementLigature*    ligature        = dynamic_cast<T100ElementLigature*>(element);

                if(ligature){
                    T100ElementBase*    start           = m_elementServe.GetElement(ligature->GetStartIndex());
                    T100ElementBase*    end             = m_elementServe.GetElement(ligature->GetEndIndex());

                    ligature->SetStart(start);
                    ligature->SetEnd(end);
                }
            }
            break;
        case T100ELEMENT_SINGLE_TRACK:
            {
                T100ElementSingleTrack*    singletrack          = dynamic_cast<T100ElementSingleTrack*>(element);

                if(singletrack){
                    T100ElementBase*    start           = m_elementServe.GetElement(singletrack->GetStartIndex());
                    T100ElementBase*    end             = m_elementServe.GetElement(singletrack->GetEndIndex());

                    singletrack->SetStart(start);
                    singletrack->SetEnd(end);
                }
            }
            break;
        case T100ELEMENT_BIDIRECTION:
            {
                T100ElementBidirection*    bidirection          = dynamic_cast<T100ElementBidirection*>(element);

                if(bidirection){
                    T100ElementBase*    start           = m_elementServe.GetElement(bidirection->GetStartIndex());
                    T100ElementBase*    end             = m_elementServe.GetElement(bidirection->GetEndIndex());

                    bidirection->SetStart(start);
                    bidirection->SetEnd(end);
                }
            }
            break;
        }
    }


    m_current   = info;
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100BOOL T100DiagramServe::Append()
{
    T100ElementBase*    element     = m_elementServe.GetElement();

    if(element){
        m_current->GetElements()->push_back(element);
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100DiagramServe::Remove()
{
    T100ElementBase*    element     = m_elementServe.GetElement();

    if(element){
        if(m_current->Remove(element)){
            m_elementServe.SetElement(T100NULL);
            T100SAFE_DELETE(element)
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100DiagramServe::Close()
{
    m_current   = T100NULL;
    m_elementServe.SetElement(T100NULL);
    m_modified  = T100FALSE;
    m_opened    = T100FALSE;

    return T100TRUE;
}

T100BOOL T100DiagramServe::Hit(T100INT x, T100INT y)
{
    T100DIAGRAM_ELEMENT_VECTOR*     elements    = m_current->GetElements();

    for(T100ElementBase* item : *elements){
        if(item->Hit(x, y)){
            m_elementServe.SetElement(item);
            return T100TRUE;
        }
    }
    return T100FALSE;
}
