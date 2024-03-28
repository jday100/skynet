#ifndef T100ELEMENTCIRCLESOURCE_H
#define T100ELEMENTCIRCLESOURCE_H

#include "T100DiagramTransducerSource.h"

class T100ElementCircleSource : public T100DiagramTransducerSource
{
    public:
        T100ElementCircleSource();
        virtual ~T100ElementCircleSource();

        T100BOOL            serialize();
        T100BOOL            deserialize();

    protected:

    private:
};

#endif // T100ELEMENTCIRCLESOURCE_H
