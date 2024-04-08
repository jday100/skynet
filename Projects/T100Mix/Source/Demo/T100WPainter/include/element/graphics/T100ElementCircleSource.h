#ifndef T100ELEMENTCIRCLESOURCE_H
#define T100ELEMENTCIRCLESOURCE_H

#include "T100ElementCircle.h"
#include "T100ElementBaseSource.h"

class T100ElementCircleSource : public T100ElementBaseSource
{
    public:
        T100ElementCircleSource(T100ElementCircle*);
        virtual ~T100ElementCircleSource();

        T100BOOL                    serialize();
        T100BOOL                    deserialize();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100ElementCircle*          m_element           = T100NULL;
};

#endif // T100ELEMENTCIRCLESOURCE_H
