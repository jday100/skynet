#include "T100PainterStore.h"

#include "T100BufferedFile.h"
#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"

#include "T100Diagram.h"

namespace T100Painter{

T100PainterStore::T100PainterStore()
{
    //ctor
}

T100PainterStore::~T100PainterStore()
{
    //dtor
}

T100BOOL T100PainterStore::close()
{

}

T100BOOL T100PainterStore::OpenFile(T100STRING file, T100DiagramInfo*& info)
{
    T100BOOL        result          = T100FALSE;

    T100Library::T100BufferedFile               target(file.to_wstring());
    T100Library::T100BufferedFileReader*        reader          = T100NULL;

    reader  = target.getReader();
    if(reader){
        if(reader->open()){
            T100Diagram     diagram;

            result = diagram.Load(reader, info);

            if(!reader->close()){
                result = T100FALSE;
            }
        }
    }
    return result;
}

T100BOOL T100PainterStore::SaveAsFile(T100STRING file, T100DiagramInfo* info)
{
    T100BOOL        result          = T100FALSE;

    T100Library::T100BufferedFile               target(file.to_wstring());
    T100Library::T100BufferedFileWriter*        writer          = T100NULL;

    writer  = target.getWriter();
    if(writer){
        if(writer->open()){
            T100DiagramInfoV1*  data            = T100NULL;

            data    = static_cast<T100DiagramInfoV1*>(info);
            if(data){
                result = T100TRUE;
            }

            if(result){
                T100DiagramV1       diagram;
                result = diagram.Save(writer, data);
            }

            if(!writer->close()){
                result = T100FALSE;
            }
        }
    }
    return result;
}

}
