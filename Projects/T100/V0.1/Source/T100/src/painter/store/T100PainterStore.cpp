#include "T100PainterStore.h"

#include "T100BufferedFile.h"
#include "T100BufferedFileReader.h"
#include "T100BufferedFileWriter.h"

namespace T100Painter{

T100PainterStore::T100PainterStore()
{
    //ctor
}

T100PainterStore::~T100PainterStore()
{
    //dtor
}

T100DiagramBase* T100PainterStore::getDiagram(T100Library::T100FileReader* reader)
{

}

T100BOOL T100PainterStore::OpenFile(T100STRING file, T100PAINTER_ELEMENT_VECTOR* elements)
{
    T100BOOL            result          = T100FALSE;
    T100DiagramBase*    diagram         = T100NULL;
    T100Library::T100FileReader*        reader          = T100NULL;

    m_file  = T100NEW T100Library::T100File(file.to_wstring());

    reader = m_file->getReader();

    if(reader){
        diagram = getDiagram(reader);
    }

    if(diagram){
        result = diagram->Load(elements);
    }

    return result;
}

T100BOOL T100PainterStore::SaveAsFile(T100STRING file, T100PAINTER_ELEMENT_VECTOR* elements, T100DiagramV1* diagram)
{
    T100BOOL            result          = T100FALSE;

    T100Library::T100BufferedFile               target(file.to_wstring());
    T100Library::T100BufferedFileWriter*        writer          = T100NULL;

    writer = target.getWriter();
    if(writer){
        if(writer->open()){
            result = diagram->Save(writer, elements);

            if(!writer->close()){
                result = T100FALSE;
            }
        }
    }

    return result;
}

}
