#ifndef T100DOT_H
#define T100DOT_H

#include "T100Entity.h"

class T100Dot : public T100Entity
{
    public:
        T100Dot();
        virtual ~T100Dot();

        T100UINT                row;
        T100UINT                column;
        T100WSTRING             file;

        virtual T100VOID        load();

    protected:

    private:
};

#endif // T100DOT_H
