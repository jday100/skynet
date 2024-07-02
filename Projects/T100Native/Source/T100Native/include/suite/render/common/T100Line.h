#ifndef T100LINE_H
#define T100LINE_H

#include <vector>
#include "T100Point.h"

#define     T100LINE_VECTOR         std::vector<T100Line*>

class T100Line
{
    public:
        T100Line();
        virtual ~T100Line();

        T100Point           m_a;
        T100Point           m_b;

    protected:

    private:
};

#endif // T100LINE_H
