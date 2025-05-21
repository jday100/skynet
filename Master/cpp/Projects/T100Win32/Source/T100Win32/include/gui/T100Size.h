#ifndef T100SIZE_H
#define T100SIZE_H

#include "T100Common.h"

class T100Size
{
    public:
        T100Size();
        T100Size(T100INT, T100INT);
        virtual ~T100Size();

        T100INT             width           = 0;
        T100INT             height          = 0;

    protected:

    private:
};

#endif // T100SIZE_H
