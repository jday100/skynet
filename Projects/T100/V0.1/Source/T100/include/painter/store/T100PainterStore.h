#ifndef T100PAINTERSTORE_H
#define T100PAINTERSTORE_H

#include "T100String.h"
#include "T100File.h"
#include "T100FileStream.h"
#include "T100PainterCommon.h"
#include "T100DiagramV1.h"


namespace T100Painter{

class T100PainterStore
{
    public:
        T100PainterStore();
        virtual ~T100PainterStore();

        //
        T100BOOL                SaveAsFile(T100STRING, T100PAINTER_ELEMENT_VECTOR*, T100DiagramV1*);
        //

        T100BOOL                OpenFile(T100STRING, T100PAINTER_ELEMENT_VECTOR*);

        T100BOOL                SaveAsFile(T100STRING, T100PAINTER_ELEMENT_VECTOR*);




    protected:
        T100DiagramBase*        getDiagram(T100Library::T100FileReader*);

    private:
        T100Library::T100File*              m_file              = T100NULL;
        T100Library::T100FileStream*        m_stream            = T100NULL;

};

}

#endif // T100PAINTERSTORE_H
