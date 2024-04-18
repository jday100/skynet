#ifndef T100ELEMENTBASESOURCE_H
#define T100ELEMENTBASESOURCE_H

#include "T100ElementBase.h"
#include "T100DiagramTransducerSource.h"

class T100ElementBaseSource : public T100DiagramTransducerSource
{
    public:
        T100ElementBaseSource();
        virtual ~T100ElementBaseSource();
        T100WORD                    getType();

        T100VOID                    setElement(T100ElementBase*);
        T100ElementBase*            getElement();

        T100BOOL                    serialize();
        T100BOOL                    deserialize();

    protected:
        T100WORD                    m_type              = 0;
        T100ElementBase*            m_element           = T100NULL;

    private:
};

#endif // T100ELEMENTBASESOURCE_H
