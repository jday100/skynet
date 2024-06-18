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

        T100FACET_VECTOR&                   GetFacets();

    protected:
        T100FACET_VECTOR                    m_facets;

    private:

};

#endif // T100ENTITY_H
