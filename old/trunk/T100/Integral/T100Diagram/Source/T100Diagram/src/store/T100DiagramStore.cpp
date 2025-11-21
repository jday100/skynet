#include "T100DiagramStore.h"

#include "T100Diagram.h"

T100DiagramStore::T100DiagramStore()
{
    //ctor
}

T100DiagramStore::~T100DiagramStore()
{
    //dtor
}

T100BOOL T100DiagramStore::Load(T100WSTRING& path, T100DiagramInfo*& info)
{
    T100BOOL                    result      = T100FALSE;
    T100BufferedFileReader      reader(path);
    T100Diagram                 diagram;

    if(reader.Open()){
        result  = diagram.Load(&reader, info);

        if(result){
            info->SetPath(path);
        }

        if(reader.Close()){
            return result;
        }
    }

    return T100FALSE;
}

T100BOOL T100DiagramStore::Save(T100WSTRING& path, T100DiagramInfo* info)
{
    T100BOOL                    result      = T100FALSE;
    T100BufferedFileWriter      writer(path);
    T100Diagram                 diagram;

    if(writer.Open()){
        result  = diagram.Save(&writer, info);

        if(writer.Close()){
            return result;
        }
    }

    return T100FALSE;
}
