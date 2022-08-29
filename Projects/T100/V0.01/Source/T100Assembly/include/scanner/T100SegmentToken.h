#ifndef T100SEGMENTTOKEN_H
#define T100SEGMENTTOKEN_H

#include "T100AssemblyCommon.h"
#include "T100Token.h"
#include "T100SentenceToken.h"

#define     T100SEGMENT_VECTOR      std::vector<T100SegmentToken*>


class T100SegmentToken : public T100Token
{
    public:
        T100SegmentToken();
        virtual ~T100SegmentToken();

        T100STRING              name;

        T100SENTENCE_VECTOR     sentences;

        T100SegmentToken*       copy();

        T100VOID                clear();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
};

#endif // T100SEGMENTTOKEN_H
