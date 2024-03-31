#ifndef T100DIAGRAMINFO_H
#define T100DIAGRAMINFO_H

#include "T100DiagramCommon.h"
#include "T100ElementBase.h"


class T100DiagramInfo
{
    public:
        T100DiagramInfo();
        virtual ~T100DiagramInfo();

        T100DIAGRAM_HEAD*                   getHead();
        T100WPAINTER_ELEMENT_VECTOR*        getElements();

    protected:
        T100VOID                            create();
        T100VOID                            destroy();

    private:
        T100DIAGRAM_HEAD                    m_head;
        T100WPAINTER_ELEMENT_VECTOR         m_elements;
};

#endif // T100DIAGRAMINFO_H
