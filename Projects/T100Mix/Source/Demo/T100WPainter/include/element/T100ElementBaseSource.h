#ifndef T100ELEMENTBASESOURCE_H
#define T100ELEMENTBASESOURCE_H

#include "T100ElementBase.h"
#include "T100DiagramTransducerSource.h"

class T100ElementBaseSource : public T100DiagramTransducerSource
{
    public:
        T100ElementBaseSource();
        virtual ~T100ElementBaseSource();

        T100VOID                    setElement(T100ElementBase*);
        T100ElementBase*            getElement();

    protected:

    private:
};

#endif // T100ELEMENTBASESOURCE_H
