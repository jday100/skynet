#ifndef T100ELEMENTSERVE_H
#define T100ELEMENTSERVE_H

#include <atomic>
#include "T100ElementBase.h"

class T100ElementServe
{
    friend class T100DiagramServe;
    public:
        T100ElementServe();
        virtual ~T100ElementServe();

        T100VOID                    SetElement(T100ElementBase*);
        T100ElementBase*            GetElement();

        T100ElementBase*            Create(T100UINT);

        T100ElementBase*            GetElement(T100UINT);

        T100UINT                    GetWidth();
        T100UINT                    GetHeight();

    protected:
        std::atomic_uint            m_index;
        std::atomic_uint            m_width;
        std::atomic_uint            m_height;
        T100ElementBase*            m_current       = T100NULL;

        T100DIAGRAM_ELEMENT_INDEX_HASH          m_elements;

    private:
        T100VOID                    Load(T100DIAGRAM_ELEMENT_VECTOR*);
};

#endif // T100ELEMENTSERVE_H
