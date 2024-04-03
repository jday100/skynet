#include "T100Diagram.h"

#include "T100BufferedFile.h"
#include "T100DiagramTransducer.h"
#include "T100DiagramFileSource.h"

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
        transducer.deserialize(source, target);

        if(result){
            result  = diagram.close();
        }
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
        transducer.serialize(source, target);

        if(result){
            result  = saveInfo(diagram, info);
        }

        result  = diagram.close() ? result : T100FALSE;
    }
    return result;
}

T100BOOL T100Diagram::loadInfo()
{

}

T100BOOL T100Diagram::saveInfo(T100BufferedFile& file, T100DiagramInfo& info)
{
    T100WPAINTER_ELEMENT_VECTOR*        elements            = T100NULL;

    elements    = info.getElements();
    if(elements){
        for(T100ElementBase* element : *elements){
            if(element){

            }else{
                return T100FALSE;
            }
        }
    }
    return T100TRUE;
}
