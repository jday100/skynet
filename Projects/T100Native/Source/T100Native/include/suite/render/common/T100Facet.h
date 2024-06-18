#ifndef T100FACET_H
#define T100FACET_H

#include <vector>
#include "T100Point.h"

#define     T100FACET_VECTOR            std::vector<T100Facet*>

class T100Facet
{
    public:
        T100Facet();
        virtual ~T100Facet();

        T100Point               m_x;
        T100Point               m_y;
        T100Point               m_z;

    protected:

    private:
};

#endif // T100FACET_H
