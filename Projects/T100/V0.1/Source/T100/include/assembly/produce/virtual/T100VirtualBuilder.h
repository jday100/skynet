#ifndef T100VIRTUALBUILDER_H
#define T100VIRTUALBUILDER_H

#include "T100ProduceBuilder.h"
#include "T100PartToken.h"
#include "T100SegmentToken.h"
#include "T100ProduceInfo.h"
#include "T100VirtualInfo.h"

namespace T100Assembly{

class T100VirtualBuilder : public T100ProduceBuilder
{
    public:
        T100VirtualBuilder();
        virtual ~T100VirtualBuilder();

        T100BOOL            run(T100STRING&, T100ProduceInfo&);

    protected:
        T100BOOL            build(T100ProduceInfo&);
        T100BOOL            build(T100PartToken*);
        T100BOOL            build(T100SegmentToken*);
        T100BOOL            build(T100SentenceToken*);

        T100BOOL            merge(T100ProduceInfo&, T100VirtualInfo&);
        T100BOOL            save(T100STRING&, T100VirtualInfo&);

        T100BOOL            save(T100PartInfo*);

    private:
        T100PartInfo*       m_part          = T100NULL;

};

}

#endif // T100VIRTUALBUILDER_H
