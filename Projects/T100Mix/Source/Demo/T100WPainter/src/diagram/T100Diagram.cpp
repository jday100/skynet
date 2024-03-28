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
    T100BufferedFile                        diagram(file);
    T100DiagramTransducer                   transducer;
    T100DiagramFileSource                   source;
    T100DiagramTransducerTarget             target(&diagram);

    transducer.deserialize(source, target);
}

T100BOOL T100Diagram::save(T100STRING file, T100DiagramInfo& info)
{
    T100BufferedFile                        diagram(file);
    T100DiagramTransducer                   transducer;
    T100DiagramFileSource                   source;
    T100DiagramTransducerTarget             target(&diagram);

    transducer.serialize(source, target);
}
