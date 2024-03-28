#ifndef T100DIAGRAMINFO_H
#define T100DIAGRAMINFO_H

#include "T100ElementBase.h"


class T100DiagramInfo
{
    public:
        T100DiagramInfo();
        virtual ~T100DiagramInfo();

        T100WPAINTER_ELEMENT_VECTOR*        getElements();

    protected:

    private:
        T100WPAINTER_ELEMENT_VECTOR         m_elements;
};

#endif // T100DIAGRAMINFO_H
