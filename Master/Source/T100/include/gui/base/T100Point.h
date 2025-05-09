#ifndef T100POINT_H
#define T100POINT_H

#include "T100Common.h"
#include "T100Class.h"

class T100Point : public T100Class
{
    public:
        T100Point();
        T100Point(T100INT, T100INT);
        virtual ~T100Point();

        T100INT         m_x     = 0;
        T100INT         m_y     = 0;

    protected:

    private:
};

#endif // T100POINT_H
