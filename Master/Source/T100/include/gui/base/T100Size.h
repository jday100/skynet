#ifndef T100SIZE_H
#define T100SIZE_H

#include "T100Common.h"
#include "T100Class.h"

class T100Size : public T100Class
{
    public:
        T100Size();
        T100Size(T100INT, T100INT);
        virtual ~T100Size();

        T100INT         m_x     = 0;
        T100INT         m_y     = 0;

    protected:

    private:

};

#endif // T100SIZE_H
