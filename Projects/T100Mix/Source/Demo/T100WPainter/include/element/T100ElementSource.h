#ifndef T100ELEMENTSOURCE_H
#define T100ELEMENTSOURCE_H

#include "T100DiagramTransducerSource.h"

class T100ElementSource : public T100DiagramTransducerSource
{
    public:
        T100ElementSource();
        virtual ~T100ElementSource();

        T100WORD            getType();

    protected:

    private:
};

#endif // T100ELEMENTSOURCE_H
