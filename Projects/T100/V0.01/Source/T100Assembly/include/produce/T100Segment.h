#ifndef T100SEGMENT_H
#define T100SEGMENT_H

#include "T100AssemblyCommon.h"
#include "T100SegmentEqual.h"
#include "T100SegmentHash.h"




#define     T100SEGMENT_HASH            std::unordered_map<T100SEGMENT_KEY, T100Segment*, T100SegmentHash, T100SegmentEqual>


class T100Segment
{
    friend class T100RealMerger;
    friend class T100BuildInfo;
    friend class T100SentenceVariable;
    public:
        T100Segment();
        virtual ~T100Segment();

        T100WORD                    size();

        T100WORD_VECTOR&            getMem();

        T100WORD                    getOffset();

        T100BOOL                    setWord(T100WORD&, T100WORD);
        T100BOOL                    setString(T100WORD&, T100String);
        T100BOOL                    setArray(T100WORD&, T100WORD);

        T100VOID                    setName(T100String);
        T100String                  getName();

        T100WORD                    getLocation();
        T100WORD                    getLength();



    protected:
        T100String                  m_name;
        T100WORD_VECTOR             m_mem;

        T100BOOL                    isMaster            = T100FALSE;
        T100BOOL                    isDefault           = T100FALSE;
        T100BOOL                    isVirtual           = T100FALSE;
        T100BOOL                    isShare             = T100FALSE;

        T100WORD                    m_offset            = 0;
        T100WORD                    m_location          = 0;
        T100WORD                    m_length            = 0;

    private:
};

#endif // T100SEGMENT_H
