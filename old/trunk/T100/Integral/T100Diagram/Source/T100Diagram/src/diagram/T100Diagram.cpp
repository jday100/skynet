#include "T100Diagram.h"

#include "T100DiagramSource.h"
#include "T100DiagramV1Source.h"
#include "T100DiagramTransducer.h"

T100Diagram::T100Diagram()
{
    //ctor
}

T100Diagram::~T100Diagram()
{
    //dtor
}

T100DiagramSourceBase* T100Diagram::GetDiagramSource(T100UINT type, T100UINT version)
{
    return T100NEW T100DiagramV1Source();
}

T100BOOL T100Diagram::Load(T100BufferedFileReader* reader, T100DiagramInfo*& info)
{
    T100BOOL                        result      = T100FALSE;
    T100DiagramTransducer           transducer;
    T100DiagramTransducerTarget     target(reader);

    T100DiagramSource               source;
    T100DiagramSourceBase*          current;

    result  = transducer.Deserialize(source, target);
    if(!result){
        return T100FALSE;
    }

    current     = GetDiagramSource(source.GetType(), source.GetVersion());

    if(current){
        current->SetTarget(&target);
        result  = transducer.Deserialize(*current, target);
        if(result){
            info    = current->GetDiagramInfo();
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Diagram::Save(T100BufferedFileWriter* writer, T100DiagramInfo* info)
{
    T100BOOL            result          = T100FALSE;
    T100DiagramTransducer               transducer;
    T100DiagramTransducerTarget         target(writer);

    T100DiagramSource                   source;
    T100DiagramSourceBase*              current;

    source.SetDiagramInfo(info);
    result = transducer.Serialize(source, target);
    if(!result){
        return T100FALSE;
    }

    current     = GetDiagramSource(source.GetType(), source.GetVersion());

    if(current){
        current->SetDiagramInfo(info);
        current->SetTarget(&target);
        result  = transducer.Serialize(*current, target);
        if(result){
            return T100TRUE;
        }
    }
    return T100FALSE;
}
