#include "T100Diagram.h"

#include "T100BufferedFile.h"
#include "T100ElementCommon.h"
#include "T100ElementSource.h"
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
            result  = loadDiagramInfo(info, target);
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
            result  = saveDiagramInfo(diagram, info);
        }

        result  = diagram.close() ? result : T100FALSE;
    }
    return result;
}

T100BOOL T100Diagram::loadDiagramInfo(T100BufferedFile& file, T100DiagramInfo& info)
{
    T100BOOL                                result;
    T100ElementSource                       source;

    T100DiagramTransducer                   transducer;

    return transducer.serialize(source, target);
}

T100BOOL T100Diagram::saveDiagramInfo(T100BufferedFile& file, T100DiagramInfo& info)
{
    T100BOOL                                result;
    T100ElementSource                       source;

    T100DiagramTransducer                   transducer;

    return transducer.deserialize(source, target);
}
