#ifndef T100REALBUILDER_H
#define T100REALBUILDER_H

#include "T100ProduceBuilder.h"
#include "T100BuildInfo.h"
#include "T100SentenceToken.h"
#include "T100SegmentToken.h"
#include "T100PartToken.h"
#include "T100PartInfo.h"
#include "T100ParseInfo.h"
#include "T100RealInfo.h"
#include "T100ProduceInfo.h"


class T100RealBuilder : public T100ProduceBuilder
{
    public:
        T100RealBuilder();
        virtual ~T100RealBuilder();

        T100BOOL            run(T100STRING&, T100ProduceInfo&);

    protected:
        T100BOOL            build(T100ProduceInfo&);
        T100BOOL            build(T100PartToken*);
        T100BOOL            build(T100SegmentToken*);
        T100BOOL            build(T100SentenceToken*);

        T100BOOL            save(T100PartInfo*);

        T100BOOL            merge(T100ProduceInfo&, T100RealInfo&);
        T100BOOL            save(T100STRING&, T100RealInfo&);

    private:
        T100PartInfo*       m_part          = T100NULL;

};

#endif // T100REALBUILDER_H
