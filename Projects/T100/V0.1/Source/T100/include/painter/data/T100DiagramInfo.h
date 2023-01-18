#ifndef T100DIAGRAMINFO_H
#define T100DIAGRAMINFO_H

#include "T100String.h"
#include "T100PainterCommon.h"
#include "T100DiagramCommon.h"

namespace T100Painter{

class T100DiagramInfo
{
    public:
        T100DiagramInfo();
        virtual ~T100DiagramInfo();

        T100VOID                            setFile(T100STRING);
        T100STRING                          getFile();

        T100DIAGRAM_HEAD*                   getHead();
        T100PAINTER_ELEMENT_VECTOR*         getElements();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100STRING                          m_file;
        T100DIAGRAM_HEAD                    m_head;
        T100PAINTER_ELEMENT_VECTOR          m_elements;

};

}

#endif // T100DIAGRAMINFO_H
