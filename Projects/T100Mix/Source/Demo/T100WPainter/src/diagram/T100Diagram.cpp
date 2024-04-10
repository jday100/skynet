#include "T100Diagram.h"

#include "T100BufferedFile.h"
#include "T100ElementCommon.h"
#include "T100ElementSource.h"
#include "T100ElementBaseSource.h"
#include "T100DiagramTransducer.h"
#include "T100DiagramFileSource.h"

#include "T100ElementCircleSource.h"

T100Diagram::T100Diagram()
{
    //ctor
}

T100Diagram::~T100Diagram()
{
    //dtor
}

T100BOOL T100Diagram::load(T100STRING file, T100DiagramInfo& info)
{
    T100BOOL                                result;
    T100BufferedFile                        diagram(file);
    T100DiagramTransducer                   transducer;
    T100DiagramFileSource                   source(&info);
    T100DiagramTransducerTarget             target(&diagram);

    result  = diagram.open();
    if(result){
        m_target    = &target;
        transducer.deserialize(source, target);

        if(result){
            result  = loadInfo(diagram, info);
        }

        result  = diagram.close() ? result : T100FALSE;
    }
    return result;
}

T100BOOL T100Diagram::save(T100STRING file, T100DiagramInfo& info)
{
    T100BOOL                                result;
    T100BufferedFile                        diagram(file);
    T100DiagramTransducer                   transducer;
    T100DiagramFileSource                   source(&info);
    T100DiagramTransducerTarget             target(&diagram);

    result  = diagram.open();
    if(result){
        m_target    = &target;
        transducer.serialize(source, target);

        if(result){
            result  = saveInfo(diagram, info);
        }

        result  = diagram.close() ? result : T100FALSE;
    }
    return result;
}

T100BOOL T100Diagram::loadInfo(T100BufferedFile& file, T100DiagramInfo& info)
{
    T100BOOL                            result;
    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;

    elements    = info.getElements();
    if(elements){
        T100ElementBaseSource           source;
        T100ElementBaseSource*          current             = T100NULL;

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

            elements->push_back(current->getElement());
        }while(T100TRUE);
    }
    return T100TRUE;
}

T100BOOL T100Diagram::saveInfo(T100BufferedFile& file, T100DiagramInfo& info)
{
    T100BOOL                            result;
    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;

    elements    = info.getElements();
    if(elements){
        for(T100ElementBase* element : *elements){
            if(element){
                result  = saveElement(element);
                if(!result)return T100FALSE;
            }else{
                return T100FALSE;
            }
        }
    }
    return T100TRUE;
}

T100BOOL T100Diagram::loadElement(T100ElementBase* element)
{
    T100BOOL                    result;
    T100ElementBaseSource       source;

    source.setElement(element);
    source.setTarget(m_target);

    result  = source.deserialize();
    if(!result)return T100FALSE;

    T100ElementBaseSource*      current             = T100NULL;

    current     = getElementSource(element->getType());
    if(!current)return T100FALSE;

    current->setElement(element);
    current->setTarget(m_target);
    result  = current->deserialize();

    return result;
}

T100BOOL T100Diagram::saveElement(T100ElementBase* element)
{
    T100BOOL                    result;
    T100ElementBaseSource       source;

    source.setElement(element);
    source.setTarget(m_target);

    result  = source.serialize();
    if(!result)return T100FALSE;

    T100ElementBaseSource*      current             = T100NULL;

    current = getElementSource(element->getType());
    if(!current)return T100FALSE;

    current->setElement(element);
    current->setTarget(m_target);
    result  = current->serialize();

    return result;
}

T100ElementBaseSource* T100Diagram::getElementSource(T100WORD type)
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
