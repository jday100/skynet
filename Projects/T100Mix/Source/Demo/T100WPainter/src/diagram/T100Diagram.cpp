#include "T100Diagram.h"

#include "T100BufferedFile.h"
#include "T100DiagramTransducer.h"

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
    T100DiagramTransducerSource             source;
    T100DiagramTransducerTarget             target;

    transducer.deserialize(source, target);
}

T100BOOL T100Diagram::save(T100STRING file, T100DiagramInfo& info)
{

}
