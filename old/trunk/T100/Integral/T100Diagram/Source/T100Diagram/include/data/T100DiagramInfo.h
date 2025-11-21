#ifndef T100DIAGRAMINFO_H
#define T100DIAGRAMINFO_H

#include "T100DiagramCommon.h"
#include "T100ElementBase.h"

class T100DiagramInfo
{
    public:
        T100DiagramInfo();
        virtual ~T100DiagramInfo();

        T100VOID                            SetPath(T100WSTRING&);
        T100WSTRING&                        GetPath();

        T100DIAGRAM_HEAD*                   GetHead();

        T100DIAGRAM_CANVAS*                 GetCanvas();

        T100DIAGRAM_ELEMENT_VECTOR*         GetElements();

        T100BOOL                            Remove(T100ElementBase*);

    protected:

    private:
        T100WSTRING                         m_path;
        T100DIAGRAM_HEAD                    m_head;
        T100DIAGRAM_CANVAS                  m_canvas;
        T100DIAGRAM_ELEMENT_VECTOR          m_elements;

        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100DIAGRAMINFO_H
