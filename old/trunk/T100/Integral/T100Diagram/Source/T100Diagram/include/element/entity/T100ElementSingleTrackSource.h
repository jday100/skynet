#ifndef T100ELEMENTSINGLETRACKSOURCE_H
#define T100ELEMENTSINGLETRACKSOURCE_H

#include "T100ElementSingleTrack.h"
#include "T100ElementSourceBase.h"

class T100ElementSingleTrackSource : public T100ElementSourceBase
{
    public:
        T100ElementSingleTrackSource(T100ElementSingleTrack*);
        virtual ~T100ElementSingleTrackSource();

        T100BOOL                        Serialize();
        T100BOOL                        Deserialize();

    protected:
        T100ElementSingleTrack*         m_element       = T100NULL;

    private:
};

#endif // T100ELEMENTSINGLETRACKSOURCE_H
