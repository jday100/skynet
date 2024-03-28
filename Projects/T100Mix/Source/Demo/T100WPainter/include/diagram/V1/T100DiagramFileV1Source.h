#ifndef T100DIAGRAMFILEV1SOURCE_H
#define T100DIAGRAMFILEV1SOURCE_H

#include "T100DiagramTransducerSource.h"


class T100DiagramFileV1Source : public T100DiagramTransducerSource
{
    public:
        T100DiagramFileV1Source();
        virtual ~T100DiagramFileV1Source();

        T100BOOL            serialize();
        T100BOOL            deserialize();

    protected:

    private:
};

#endif // T100DIAGRAMFILEV1SOURCE_H
