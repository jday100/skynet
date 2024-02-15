#ifndef T100REGISTER64_H
#define T100REGISTER64_H


#include "T100Common.h"

typedef union{
    struct{
        INT8        HIGH;
        INT8        LOW;
    };
    INT16           DATA;
}INT16S;

typedef union{
    struct{
        INT16S      HIGH;
        INT16S      LOW;
    };
    INT32           DATA;
}INT32S;


typedef union{
    struct{
        INT32S      HIGH;
        INT32S      LOW;
    };
    INT64           DATA;
}INT64S;


class T100Register64
{
    public:
        T100Register64();
        virtual ~T100Register64();


        INT64S              DATA;

    protected:

    private:
};

#endif // T100REGISTER64_H
