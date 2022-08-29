#ifndef T100VIRTUALBUILDER_H
#define T100VIRTUALBUILDER_H

#include "T100ProduceBuilder.h"
#include "T100ProduceInfo.h"


class T100VirtualBuilder : public T100ProduceBuilder
{
    public:
        T100VirtualBuilder();
        virtual ~T100VirtualBuilder();

        T100BOOL            run(T100STRING&, T100ProduceInfo&);

    protected:

    private:
};

#endif // T100VIRTUALBUILDER_H
