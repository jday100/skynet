#ifndef T100ELEMENTBIDIRECTIONSOURCE_H
#define T100ELEMENTBIDIRECTIONSOURCE_H

#include "T100ElementBidirection.h"
#include "T100ElementSourceBase.h"

class T100ElementBidirectionSource : public T100ElementSourceBase
{
    public:
        T100ElementBidirectionSource(T100ElementBidirection*);
        virtual ~T100ElementBidirectionSource();

        T100BOOL                        Serialize();
        T100BOOL                        Deserialize();

    protected:
        T100ElementBidirection*         m_element       = T100NULL;

    private:
};

#endif // T100ELEMENTBIDIRECTIONSOURCE_H
