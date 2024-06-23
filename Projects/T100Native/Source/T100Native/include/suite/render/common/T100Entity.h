#ifndef T100ENTITY_H
#define T100ENTITY_H

#include <vector>
#include "T100Facet.h"

#define     T100ENTITY_VECTOR           std::vector<T100Entity*>

class T100Entity
{
    public:
        T100Entity();
        virtual ~T100Entity();

        T100INT                             m_type              = 0;

        T100FACET_VECTOR&                   GetFacets();

        T100VOID                            SetOrigin(T100FLOAT, T100FLOAT, T100FLOAT);
        virtual T100VOID                    SetTerminus(T100FLOAT, T100FLOAT, T100FLOAT) = 0;

    protected:
        T100FACET_VECTOR                    m_facets;

    private:
        T100FLOAT                           m_origin_x          = 0;
        T100FLOAT                           m_origin_y          = 0;
        T100FLOAT                           m_origin_z          = 0;

};

#endif // T100ENTITY_H
