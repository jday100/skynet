#ifndef T100WRITER_H
#define T100WRITER_H


#include "T100Common.h"


class T100Writer
{
    public:
        T100Writer();
        virtual ~T100Writer();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:

};

#endif // T100WRITER_H
