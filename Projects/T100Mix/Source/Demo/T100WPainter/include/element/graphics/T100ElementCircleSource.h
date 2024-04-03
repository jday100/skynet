#ifndef T100ELEMENTCIRCLESOURCE_H
#define T100ELEMENTCIRCLESOURCE_H

#include "T100ElementCircle.h"
#include "T100DiagramTransducerSource.h"

class T100ElementCircleSource : public T100DiagramTransducerSource
{
    public:
        T100ElementCircleSource(T100ElementCircle*);
        virtual ~T100ElementCircleSource();

        T100BOOL                serialize();
        T100BOOL                deserialize();

    protected:

    private:
        T100ElementCircle*      m_element           = T100NULL;
};

#endif // T100ELEMENTCIRCLESOURCE_H
