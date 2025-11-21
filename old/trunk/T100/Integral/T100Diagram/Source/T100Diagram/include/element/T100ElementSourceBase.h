#ifndef T100ELEMENTSOURCEBASE_H
#define T100ELEMENTSOURCEBASE_H

#include "T100ElementTransducerSource.h"

class T100ElementSourceBase : public T100ElementTransducerSource
{
    public:
        T100ElementSourceBase();
        virtual ~T100ElementSourceBase();

        T100VOID                SetElement(T100ElementBase*);
        T100ElementBase*        GetElement();

    protected:
        T100ElementBase*        m_element       = T100NULL;

    private:
};

#endif // T100ELEMENTSOURCEBASE_H
