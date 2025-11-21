#ifndef T100ELEMENTSOURCE_H
#define T100ELEMENTSOURCE_H

#include "T100ElementSourceBase.h"

class T100ElementSource : public T100ElementSourceBase
{
    public:
        T100ElementSource();
        virtual ~T100ElementSource();

        T100BOOL            Serialize();
        T100BOOL            Deserialize();

        T100UINT            GetType();
        T100UINT            GetIndex();

    protected:
        T100UINT            m_type      = 0;
        T100UINT            m_index     = 0;

    private:
};

#endif // T100ELEMENTSOURCE_H
